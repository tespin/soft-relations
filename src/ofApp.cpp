#include "ofApp.h"

void ofApp::setup(){
    
    
//    cam1.setDeviceID(0);
//    cam1.setup(1280, 720);
//    cam1.listDevices();
//    tracker1.setup();
//
//    cam2.setDeviceID(1);
//    cam2.setup(1280, 720);
//    tracker2.setup();
    
    radius = 200;
    
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

void ofApp::update(){
    currentTime = ofGetElapsedTimef();

//    updateTracker(cam1, tracker1, face1);
//    updateTracker(cam2, tracker2, face2);

//    if (face1.size() != 0 && face2.size() != 0) {
//        clips = getClips(face1, face2, ClipperLib::ctIntersection);
//    }
    
    pos.x = ofGetMouseX();
    pos.y = ofGetMouseY();
    
    blob.update(pos, radius, radius);
    blob2.update(pos2, radius, radius);
    
    updateClipper();
    
    if (isIntersecting(blob, blob2)) {
        replayStarted = false;
        isRecording = true;
        if (!hasStarted) {
            startTime = currentTime;
            hasStarted = true;
        }

        for (ofPolyline line: clips) {
            recordings.push_back(std::make_pair(currentTime, line));
        }

    } else {
        hasStarted = false;

        if (isRecording) {
            endTime = currentTime;
            elapsedTime = endTime - startTime;
            isRecording = false;
        }

        // replay
        if (currentReplayTime >= startTime + elapsedTime) replayStartTime = currentTime;
        currentReplayTime = currentTime - replayStartTime + startTime;

        auto lower = std::lower_bound(recordings.begin(), recordings.end(), std::make_pair(currentReplayTime, currentReplayContour), [](std::pair<float, ofPolyline> a, std::pair<float, ofPolyline> b) {
            return a.first < b.first;
        });

        if (lower != recordings.end()) {
            currentReplayContour = lower->second;
            replayStarted = true;
        }
    }
}

void ofApp::draw(){
    ofSetBackgroundColor(255);
    if (replayStarted) {
        cout << "drawing replay" << endl;
        ofSetColor(255, 0, 255);
        currentReplayContour.draw();
    } else {
        cout << "drawing intersection" << endl;
        ofSetColor(0);
        blob.draw();
        blob2.draw();
//        drawFace(face1);
//        drawFace(face2);

        for (auto& line: clips) {
            ofSetColor(255, 0, 255);
            line.draw();
        }
    }
}

void ofApp::updateClipper() {
    clips.clear();
    clipper.Clear();
    clipper.addPolyline(blob.getPolyline(), ClipperLib::ptSubject);
    clipper.addPolyline(blob2.getPolyline(), ClipperLib::ptClip);
    clips = clipper.getClipped(currentClipperType);
}

void ofApp::updateTracker(ofVideoGrabber& grabber, ofxFaceTracker2& tracker, ofPolyline& face) {
    grabber.update();
    if (grabber.isFrameNew()) {
        tracker.update(grabber);
        
        face = getFacePolyline(tracker);
    }
}

ofPolyline ofApp::getFacePolyline(ofxFaceTracker2& tracker) {
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

std::vector<ofPolyline> ofApp::getClips(ofPolyline& face1, ofPolyline& face2, ClipperLib::ClipType clipType) {
    clips.clear();
    clipper.Clear();
    clipper.addPolyline(face1, ClipperLib::ptSubject);
    clipper.addPolyline(face2, ClipperLib::ptClip);
    
    return clipper.getClipped(clipType);
}

bool ofApp::isIntersecting(Blob blob, Blob blob2) {
    for (auto& v: blob.getPolyline() ) {
        if (blob2.getPolyline().inside(v)) return true;
    }
    return false;
}

//bool ofApp::isIntersecting(ofPolyline& poly1, ofPolyline& poly2) {
//    for (glm::vec3& v : poly1) {
//        if (poly2.inside(v)) return true;
//    }
//    return false;
//}
