#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    total = 200;
    noiseScale = 800;
    
    m_pos.resize(total);
    
    
    for(int i = 0; i < total; i++){
        m_pos[i] = ofPoint(ofRandom(0, ofGetWidth()),ofRandom(0,ofGetHeight()));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // https://www.openprocessing.org/sketch/514385
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float width = ofGetWidth();
    float height = ofGetHeight();
    
    
    for(int i = 0; i < total; i++){
        float radius = ofMap(i, 0, total, 1, 5);
        float alpha = ofMap(i, 0, total, 0, 250);
        float speed = ofRandom(0.4,0.8);
        float angle = ofNoise(m_pos[i].x / noiseScale, m_pos[i].y / noiseScale) * TWO_PI * noiseScale;
        float dirX = cos(angle);
        float dirY = sin(angle);
        ofVec2f vel = ofVec2f(dirX, dirY);
        
        vel.scale(speed);
        m_pos[i] = m_pos[i] + vel;
        
        ofSetColor(69,33,124,alpha);
        
        ofDrawCircle(m_pos[i], radius);
        
        if(m_pos[i].x > width || m_pos[i].x < 0 || m_pos[i].y > height || m_pos[i].y < 0){
            m_pos[i].x = ofRandom(50, width);
            m_pos[i].y = ofRandom(50, height);
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
