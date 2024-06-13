#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setup(1920, 1080);
    
    colorImg.allocate(1920, 1080);
    grayImg.allocate(1920, 1080);
    canvas.allocate(1920, 1080, GL_RGBA);
    canvas2.allocate(1920, 1080, GL_RGBA);
    vignette.allocate(1920, 1080);
    
    maxContours = 15;
    
    threshold = 80;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    path.clear();
//    ofEnableAlphaBlending();
    
    path.circle(ofGetMouseX(), ofGetMouseY(), 300);
    
//    if (cam.isFrameNew()) {
//    }
    
//
//    if (video.isFrameNew()) {
//        colorImg.setFromPixels(video.getPixels());
//        grayImg = colorImg;
//
//        grayImg.threshold(threshold);
//        contourFinder.findContours(grayImg, 430, ((ofGetScreenWidth()*ofGetScreenHeight())/3), 10, true);
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    path.draw();
    ofSetBackgroundColor(255);
    canvas.begin();
    ofClear(255, 255, 255, 0);
    path.draw();
    canvas.end();
//
    cam.getTexture().setAlphaMask(canvas.getTexture());
////    cam.draw(0, 0);
    canvas2.begin();
    ofClear(255);
    cam.draw(0, 0);
    canvas2.end();
//
    canvas2.draw(0, 0);
//    //    video.draw(0, 0);
//    grayImg.draw(0, 0);
//    for (int i = 0; i < contourFinder.nBlobs; i++) {
//        contourFinder.blobs[i].draw(0, 0);
//    }
}
