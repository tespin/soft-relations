#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setup(1920, 1080);
    
//    colorImg.allocate(1920, 1080);
//    grayImg.allocate(1920, 1080);

    shapeFbo.allocate(1920, 1080);
    cameraFbo.allocate(1920, 1080);
    
    maxContours = 15;
    minArea = 20;
    maxArea = 200;
    threshold = 128;
    
//    for (std::size_t i = 0; i < maxContours; i++) {
//        int randRadius = ofRandom(25, 200);
//        int randX = ofRandom(randRadius, ofGetWidth()-randRadius/2);
//        int randY = ofRandom(randRadius, ofGetHeight()-randRadius/2);
//
//        ofPath path;
//        path.circle(randX, randY, randRadius);
//
//        contours.push_back(path);
//    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()) {
        contours.clear();
        paths.clear();
        contourFinder.setMinAreaRadius(minArea);
        contourFinder.setMaxAreaRadius(maxArea);
        contourFinder.setThreshold(threshold);
        contourFinder.findContours(cam);
        contourFinder.setFindHoles(true);

        contours = contourFinder.getPolylines();

        if (contours.size() > 0) {
            for (std::size_t i = 0; i < contours.size(); i++) {
                ofPath path;
                path = polylineToPath(contours[i]);

                paths.push_back(path);
            }
        }
    }
    //    for (std::size_t i = 0; i < contours.size(); i++) {
//        contours[i].clear();
//    }
//    path.clear();
//    ofEnableAlphaBlending();
    
//    path.circle(ofGetMouseX(), ofGetMouseY(), 300);
    
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
//    ofSetBackgroundColor(255);
    
    shapeFbo.begin();
    ofClear(255, 255, 255, 0);
    for (std::size_t i = 0; i < paths.size(); i++) {
        paths[i].draw();
    }
//    contourFinder.draw();
    shapeFbo.end();
    
//    shapeFbo.draw(0, 0);
//    canvas.begin();
//    ofClear(255, 255, 255, 0);
//    path.draw();
//    canvas.end();
////
    cam.getTexture().setAlphaMask(shapeFbo.getTexture());
    cameraFbo.begin();
    ofClear(255);
    cam.draw(0, 0);
    cameraFbo.end();
    
    cameraFbo.draw(0, 0);
}

ofPath ofApp::polylineToPath(ofPolyline &polyline) {
    ofPath path;
    
    for (int i = 0; i < polyline.size(); i++) {
        if (i == 0) {
            path.newSubPath();
            path.moveTo(polyline[i]);
        } else {
            path.lineTo(polyline[i]);
        }
    }
    
    return path;
}
