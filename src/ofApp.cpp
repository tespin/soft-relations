#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    radius = 100;
//
//    pos.x = ofGetWidth() / 2 - radius / 2;
//    pos.y = ofGetHeight() / 2;
//
//    pos2.x = ofGetWidth() / 2 + radius / 2;
//    pos2.y = ofGetHeight() / 2;
//
//    speed.x = 1.05;
//    speed.y = 1.35;
//
//    blob.build(100);
//    blob2.build(100);
//
//    blob.update(pos, radius, radius);
//    blob2.update(pos2, radius, radius);
//
//    currentClipperType = ClipperLib::ctIntersection;
//
//    clipper.addPolyline(blob.getPolyline(), ClipperLib::ptSubject);
//    clipper.addPolyline(blob2.getPolyline(), ClipperLib::ptClip);
//
//    hasStarted = false;
//    hasEnded = false;
//    replayStarted = false;
    
//    cam.setup(1280, 720);
//    tracker.setup();
//
//    currentLabel = 0;
//    prevLabel = 0;
    
    cam1.setDeviceID(0);
    cam1.setup(1280, 720);
//    cam1.listDevices();
    tracker1.setup();
    
    cam2.setDeviceID(1);
    cam2.setup(1280, 720);
    tracker2.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
//    currentTime = ofGetElapsedTimef();
//    cam1.update();
//    cam2.update();
//
//    if (cam1.isFrameNew()) {
//        tracker1.update(cam1);
//    }
//
//    if (cam2.isFrameNew()) {
//        tracker2.update(cam2);
//    }
    updateTracker(cam1, tracker1, face1);
    updateTracker(cam2, tracker2, face2);
//    cam.update();
//    if (cam.isFrameNew()) {
//        tracker.update(cam);
//
//        if (tracker.getInstances().size() != 0) {
//            ofxFaceTracker2Instance instance = tracker.getInstances()[0];
//            currentFace = instance.getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::FACE_OUTLINE);
//            currentLabel = instance.getLabel();
//
//            // once a new face is detected
//            if (currentLabel != prevLabel) {
//
//                // if it's the first face (label = 1) then record
//                if (currentLabel == 1) {
//                    cout << "first face" << endl;
//                }
//
//                // replay the old face
//                cout << "new face" << endl;
//
//            } else {
//                // begin recording
//            }
//
//            prevLabel = currentLabel;
//        }
//    }
//
//    pos.x = ofGetMouseX();
//    pos.y = ofGetMouseY();
////    pos += speed;
//    blob.update(pos, radius, radius);
//    blob2.update(pos2, radius, radius);
//
//    updateClipper();
//
//    if (isIntersecting()) {
//        replayStarted = false;
//        isRecording = true;
//        if (!hasStarted) {
//            startTime = currentTime;
//            hasStarted = true;
//        }
//
//        for (ofPolyline line: clips) {
//            recordings.push_back(std::make_pair(currentTime, line));
//        }
//
//    } else {
//        hasStarted = false;
//
//        if (isRecording) {
//            endTime = currentTime;
//            elapsedTime = endTime - startTime;
//            isRecording = false;
//        }
//
//        // replay
//        if (currentReplayTime >= startTime + elapsedTime) replayStartTime = currentTime;
//        currentReplayTime = currentTime - replayStartTime + startTime;
//
////        std::vector<std::pair<float, ofPolyline>>::iterator lower = std::lower_bound(recordings.begin(), recordings.end(), currentReplayTime, [](std::pair<float, ofPolyline>& a, std::pair<float, ofPolyline>& b) {
////            return a.first < b.first;
////        });
//
//        auto lower = std::lower_bound(recordings.begin(), recordings.end(), std::make_pair(currentReplayTime, currentReplayContour), [](std::pair<float, ofPolyline> a, std::pair<float, ofPolyline> b) {
//            return a.first < b.first;
//        });
//
//        if (lower != recordings.end()) {
//            currentReplayContour = lower->second;
//            replayStarted = true;
//        }
//    }
//
//    //    cout << started << ", " << startTime << endl;
//
////    blobBounds = blob.getBoundingBox();
////
////    if (blobBounds.x > ofGetWidth() - blobBounds.getWidth() || blobBounds.x < 0) speed.x *= -1;
////    if (blobBounds.y > ofGetHeight() - blobBounds.getHeight() || blobBounds.y < 0) speed.y *= -1;
//
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawFace(face1);
    drawFace(face2);
//    tracker1.drawDebug();
//    tracker2.drawDebug();
    
//    ofSetBackgroundColor(255);
//    cam.draw(0, 0);
////
//    tracker.drawDebug();
//    tracker.drawDebugPose();
    
//    if (currentFace.size() != 0) {
//        currentFace.draw();
//    }
//    
//    if (replayStarted) {
//        ofSetColor(255, 0, 255);
//        currentReplayContour.draw();
//    } else {
//        ofSetColor(255);
//        blob.draw();
//        blob2.draw();
//
//        for (auto& line: clips) {
//            ofSetColor(255, 0, 255);
//            line.draw();
//        }
//    }
    
//    ofNoFill();
//    ofDrawRectangle(blobBounds);
}

//void ofApp::updateClipper() {
//    clips.clear();
//    clipper.Clear();
//    clipper.addPolyline(blob.getPolyline(), ClipperLib::ptSubject);
//    clipper.addPolyline(blob2.getPolyline(), ClipperLib::ptClip);
//    clips = clipper.getClipped(currentClipperType);
//}
//
//bool ofApp::isIntersecting() {
//    for (auto& v: blob.getPolyline() ) {
//        if (blob2.getPolyline().inside(v)) return true;
//    }
//    return false;
//}
void ofApp::updateTracker(ofVideoGrabber& grabber, ofxFaceTracker2& tracker, ofPolyline& face) {
    grabber.update();
    if (grabber.isFrameNew()) {
        tracker.update(grabber);
        
        face = getFacePolyline(tracker);
    }
}

ofPolyline ofApp::getFacePolyline(ofxFaceTracker2& tracker) {
    //        if (tracker.getInstances().size() != 0) {
    //            ofxFaceTracker2Instance instance = tracker.getInstances()[0];
    //            currentFace = instance.getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::FACE_OUTLINE);
    if (tracker.getInstances().size() != 0) {
        ofxFaceTracker2Instance instance = tracker.getInstances()[0];
        return instance.getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::FACE_OUTLINE);
    } else {
        return ofPolyline();
    }
}

void ofApp::drawFace(ofPolyline& face) {
    if (face.size() != 0) face.draw();
}
