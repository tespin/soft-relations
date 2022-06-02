#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    radius = 100;
    
    pos.x = ofGetWidth() / 2 - radius / 2;
    pos.y = ofGetHeight() / 2;
    
    pos2.x = ofGetWidth() / 2 + radius / 2;
    pos2.y = ofGetHeight() / 2;
    
    speed.x = 1.05;
    speed.y = 1.35;
    
    blob.build(100);
    blob2.build(100);
    
    blob.update(pos, radius, radius);
    blob2.update(pos2, radius, radius);
    
    currentClipperType = ClipperLib::ctIntersection;
    
    clipper.addPolyline(blob.getPolyline(), ClipperLib::ptSubject);
    clipper.addPolyline(blob2.getPolyline(), ClipperLib::ptClip);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    currentTime = ofGetElapsedTimef();
    
    pos.x = ofGetMouseX();
    pos.y = ofGetMouseY();
//    pos += speed;
    blob.update(pos, radius, radius);
    blob2.update(pos2, radius, radius);
    
//    clips = clipper.getClipped(currentClipperType);
    updateClipper();
    
//    if (checkIntersection()) {
//        for (auto line : clips) {
//            recording.push_back(line);
//        }
//    } else {
//        cout << "not intersecting" << endl;
//    }

//    blobBounds = blob.getBoundingBox();
//
//    if (blobBounds.x > ofGetWidth() - blobBounds.getWidth() || blobBounds.x < 0) speed.x *= -1;
//    if (blobBounds.y > ofGetHeight() - blobBounds.getHeight() || blobBounds.y < 0) speed.y *= -1;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(255);
    ofSetColor(0);
    blob.draw();
    blob2.draw();
    
    for (auto& line: clips) {
        ofSetColor(255, 0, 255);
        line.draw();
    }
    
//    for (auto& r: recording) {
//        r.draw();
//    }
    
    ofNoFill();
//    ofDrawRectangle(blobBounds);
}

void ofApp::updateClipper() {
    clips.clear();
    clipper.Clear();
    clipper.addPolyline(blob.getPolyline(), ClipperLib::ptSubject);
    clipper.addPolyline(blob2.getPolyline(), ClipperLib::ptClip);
    clips = clipper.getClipped(currentClipperType);
}

bool ofApp::checkIntersection() {
    for (auto& v: blob.getPolyline() ) {
        if (blob2.getPolyline().inside(v)) return true;
    }
    return false;
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
