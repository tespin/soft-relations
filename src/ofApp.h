#pragma once

#include "ofMain.h"
#include "Blob.hpp"
#include "ofxClipper.h"
#include "ofxFaceTracker2.h"

class ofApp : public ofBaseApp{

	public:

        void setup();
		void update();
		void draw();
        
        void updateTracker(ofVideoGrabber& grabber, ofxFaceTracker2& tracker, ofPolyline& face);
        ofPolyline getFacePolyline(ofxFaceTracker2& tracker);
        void drawFace(ofPolyline& face);
        std::vector<ofPolyline> getClips(ofPolyline& face1, ofPolyline& face2, ClipperLib::ClipType clipType);
        bool isIntersecting(ofPolyline& face1, ofPolyline& face2);
    
        ofxFaceTracker2 tracker1;
        ofxFaceTracker2 tracker2;
        ofVideoGrabber cam1;
        ofVideoGrabber cam2;

        ofPolyline face1;
        ofPolyline face2;
    
        ofx::Clipper clipper;
        std::vector<ofPolyline> clips;
        std::vector<std::pair<float, ofPolyline> > recordings;
        ofPolyline currentReplayContour;
    
        float currentTime;
        float startTime;
        float endTime;
        float elapsedTime;
        float currentReplayTime;
        float replayStartTime;
    
        bool hasStarted;
        bool hasEnded;
        bool isRecording;
        bool replayStarted;
};
