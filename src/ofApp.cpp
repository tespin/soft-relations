#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    video.setup(1920, 1080);
    
    colorImg.allocate(1920, 1080);
    grayImg.allocate(1920, 1080);
    
    threshold = 80;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(100, 100, 100);
    video.update();
    
    if (video.isFrameNew()) {
        colorImg.setFromPixels(video.getPixels());
        grayImg = colorImg;
        
        grayImg.threshold(threshold);
        contourFinder.findContours(grayImg, 20, ((ofGetScreenWidth()*ofGetScreenHeight())/3), 10, true);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    video.draw(0, 0);
    grayImg.draw(0, 0);
    for (int i = 0; i < contourFinder.nBlobs; i++) {
        contourFinder.blobs[i].draw(0, 0);
    }
}
