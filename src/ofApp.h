#pragma once

#include "ofMain.h"
#include "Blob.hpp"
#include "ofxClipper.h"

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
    
        ofVec3f pos;
        ofVec3f speed;
    
        ofVec3f pos2;

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
		
};
