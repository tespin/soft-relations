#include "ofApp.h"

void ofApp::setup(){
    cam1.setDeviceID(0);
    cam1.setup(1280, 720);
//    cam1.listDevices();
    tracker1.setup();
    
    cam2.setDeviceID(1);
    cam2.setup(1280, 720);
    tracker2.setup();
}

void ofApp::update(){
    currentTime = ofGetElapsedTimef();

    updateTracker(cam1, tracker1, face1);
    updateTracker(cam2, tracker2, face2);

    if (face1.size() != 0 && face2.size() != 0) {
        clips = getClips(face1, face2, ClipperLib::ctIntersection);
    }
    
    if (isIntersecting(face1, face2)) {
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
        drawFace(face1);
        drawFace(face2);

        for (auto& line: clips) {
            ofSetColor(255, 0, 255);
            line.draw();
        }
    }
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

bool ofApp::isIntersecting(ofPolyline& face1, ofPolyline& face2) {
    for (glm::vec3& v : face1) {
        if (face2.inside(v)) return true;
    }
    return false;
}
