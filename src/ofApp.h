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
        void updateClipper();
        ofPolyline getFacePolyline(ofxFaceTracker2& tracker);
        void drawFace(ofPolyline& face);
        std::vector<ofPolyline> getClips(ofPolyline& face1, ofPolyline& face2, ClipperLib::ClipType clipType);
        bool isIntersecting(Blob blob1, Blob blob2);
        bool isIntersecting(ofPolyline& face1, ofPolyline& face2);
    
        ofxFaceTracker2 tracker1;
        ofxFaceTracker2 tracker2;
        ofVideoGrabber cam1;
        ofVideoGrabber cam2;
    
        Blob blob;
        Blob blob2;
    
        ofVec3f pos;
        ofVec3f speed;
        ofVec3f pos2;
        
        float yoff;
        float radius;

        ofPolyline face1;
        ofPolyline face2;
    
        ofx::Clipper clipper;
        ClipperLib::ClipType currentClipperType;
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
