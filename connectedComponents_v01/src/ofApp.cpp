#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    w = 680;
    h = 454;
    
    img.load("island.jpg");
    threshold.allocate(w,h, OF_IMAGE_COLOR);
    
    // ------ Gui ------- //
    gui.setup(); // most of the time you don't need a name
    gui.add(guiThreshold.setup("threshold", 127, 0, 255));
    gui.add(guiColorR.setup("red", 0, 0, 255));
    gui.add(guiColorG.setup("green", 127, 0, 255));
    gui.add(guiColorB.setup("blue", 127, 0, 255));
    gui.add(guiDiffCol.setup("dif color", 10, 0, 100));
    gui.add(guiCropTop.setup("cropTop", 20, 0, h));
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofColor askColor = ofColor(guiColorR, guiColorG, guiColorB);
    float askColorHue = askColor.getHue();
    
    avgX = 0;
    avgY = 0;
    count = 0;
    
    for (int x = 0; x < w; x++){
        for (int y = guiCropTop; y < h; y++){
            ofColor pixel = img.getPixels().getColor(x,y);
            float pixelHue = pixel.getHue();
            float dif = ofDist(askColorHue, askColorHue, pixelHue, pixelHue);
            
//            if(dif < guiThreshold){
//                avgX += x;
//                avgY += y;
//                count++;
//                threshold.setColor(x,y, ofColor(255));
//            } else {
//                threshold.setColor(x,y, ofColor(0));
//            }
//
            if(pixelHue < askColorHue - guiDiffCol && pixel.getBrightness() > guiThreshold){
                threshold.setColor(x,y, ofColor(255));
            } else {
                threshold.setColor(x,y, ofColor(0));
            }
//
//            if (pixel.getLightness() > guiThreshold){
//                threshold.setColor(x,y, ofColor(255));
//            } else {
//                threshold.setColor(x,y, ofColor(0));
//            }
        }
    }
    
    for (int x = 0; x < w; x++){
        for (int y = 0; y < guiCropTop; y++){
            threshold.setColor(x,y, ofColor(0));
        }
    }
    threshold.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetColor(255);
    img.draw(0,0);
    threshold.draw(w, 0, w, h);
    gui.draw();
    
//    if(count > 0){
//        avgX = avgX / count;
//        avgY = avgY / count;
//
//        ofNoFill();
//        ofSetColor(255, 0, 0);
//        ofDrawRectangle(avgX, avgY, 10, 10);
//    }
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
