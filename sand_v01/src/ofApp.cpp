#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    // ------ General ------- //
    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(80);
    ofSetLineWidth(2);
    coutPar = 0;
    
    // ------ Camera & Tracker ------- //
    cam.initGrabber(1280, 720);
    tracker.setup();
    tracker.setRescale(.5);
    
    // ------ Load Particles ------- //
    loadParticles();
    loadMicro();
    
    // ------ Gui ------- //
    gui.setup(); // most of the time you don't need a name
    gui.add(guiSpeed.setup("speed", 10, 0, 15));
    gui.add(guiForce.setup("force", 1.0, 1.0, 10.0));
    gui.add(guiArea.setup("radius mouth", 30, 0, 100));
    gui.add(guiMicro.setup("micro", 0, 0.00, 1.0));
}

//--------------------------------------------------------------
void ofApp::loadParticles() {
    for (int i = 0; i < 30000; i++){
        ofPoint m = ofPoint(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
        myParticles temp;
        mParticles.push_back(temp);
        mParticles[i].setup(ofVec3f(m.x, m.y, 0));
        
    }
}x

//--------------------------------------------------------------
void ofApp::update(){
    // Microphone
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    guiMicro = scaledVol;
    guiSpeed = (scaledVol * 15) + 5;
    guiArea = ((scaledVol + 0.5) * 50);
    
    for (int i = 0; i < mParticles.size(); i++) {
        mParticles[i].areaDectect = guiArea;
        mParticles[i].maxSpeed = guiSpeed;
        mParticles[i].maxForce = guiForce;
    }
    
    // Camera & Tracker
    cam.update();
    if(cam.isFrameNew()) {
        if(tracker.update(toCv(cam))) {
            classifier.classify(tracker);
        }
    }
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    // --------- General --------- //
     ofSeedRandom(0);
    
    // --------- Camera --------- //
    ofSetColor(255, 255, 255, 30);
    cam.draw(cam.getWidth(),0,-cam.getWidth(),cam.getHeight());
    
    // --------- TRACKER --------- //
    ofSetColor(255);
   //  tracker.draw();
    ofVec2f mouth = tracker.getImageFeature(ofxFaceTracker::INNER_MOUTH).getCentroid2D();
    float mouthX = ofGetWidth() - mouth.x;
    float mouthY = mouth.y;
    ofDrawCircle(mouthX, mouthY, 10);
    
   
   // --------- Particles --------- //
    float time = ofGetElapsedTimef() * 1.5;
    float stageW = ofGetWidth();
    float stageH = ofGetHeight();

    //screenFbo.draw(0,0);
    
    ofPushMatrix();
    ofTranslate(0, 0);
    
    for(int i = 0; i < mParticles.size(); i++){
        mParticles[i].behaviors(mouthX, mouthY);
        mParticles[i].update();
        mParticles[i].draw();
    }
    
    ofPopMatrix();
    
    // --------- Gui --------- //
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    int numCounted = 0;
    
    for (int i = 0; i < bufferSize; i++){
        left[i]        = input[i*2]*0.5;
        right[i]    = input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    curVol /= (float)numCounted;
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    bufferCounter++;
}

//--------------------------------------------------------------
void ofApp::loadMicro(){
    soundStream.printDeviceList();
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter = 0;
    drawCounter = 0;
    smoothedVol = 0.0;
    scaledVol = 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for(int i = 0; i < mParticles.size(); i++){
        mParticles[i].keyPressed(key);
    }
}
