#pragma once

#include "ofMain.h"
#include "Blob.hpp"
#include "ofxClipper.h"
#include "ofxFaceTracker2.h"

class ofApp : public ofBaseApp{

	public:
    
        Blob blob;
        Blob blob2;
        std::vector<ofPolyline> clips;
        std::vector<std::pair<float, ofPolyline> > recordings;
        float currentTime;
        float startTime;
        float endTime;
        float elapsedTime;
        
        bool hasStarted;
        bool hasEnded;
        bool isRecording;
        bool replayStarted;
    
        ofx::Clipper clipper;
        ClipperLib::ClipType currentClipperType;
    
    
        glm::vec3 pos;
        glm::vec3 pos2;
        glm::vec3 speed;

        float yoff;
        float radius;
    
        ofPolyline currentReplayContour;
        float currentReplayTime;
        float replayStartTime;
    
        void setup();
		void update();
		void draw();
    
        void updateClipper();
        bool isIntersecting();
    
    ofxFaceTracker2 tracker;
    ofVideoGrabber cam;
		
};
