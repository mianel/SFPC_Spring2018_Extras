#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "myParticles.hpp"
#include "ofxFaceTracker.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    void loadMicro();
    void loadParticles();
    void audioIn(float * input, int bufferSize, int nChannels);
    
    // ------ Particles ------- //
    float coutPar;
    float total;
    vector <myParticles> mParticles;

    // ------ Gui ------- //
    ofxPanel gui;
    ofxFloatSlider guiSpeed;
    ofxFloatSlider guiForce;
    ofxFloatSlider guiArea;
    ofxFloatSlider guiMicro;
    
    // ------ Microphone ------- //
    int bufferCounter;
    int drawCounter;
    float smoothedVol;
    float scaledVol;
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    ofSoundStream soundStream;

    // ------ Tracker ------- //
    ofVideoGrabber cam;
    ofxFaceTracker tracker;
    ExpressionClassifier classifier;
};

