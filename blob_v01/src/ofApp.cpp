#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(200);
    ofSetCircleResolution(80);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float time = ofGetElapsedTimef();
    float centerY = ofGetHeight()/2;
    float h = 50;
    float marge = 200;
    float total = 400;

    
    for (int i = 0; i < total; i++){
        for (int j = 0; j < 2; j++){
            float r = 0;
            float g = 127 + 90 * sin(i * 0.01) + j*10;
            float b = 127 + 10 * sin(i * 0.022);
            
            
            float posX = marge + i;
            float posY = centerY - 50 + h * sin(i*0.03 + time*3.8) + 50*j;
            float size = 50 + 25 * sin(i*0.01 + time);
     
            
            ofSetColor(r, g, b);
            ofDrawCircle(posX, posY, size);
        }
       
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
