#pragma once

#include "ofMain.h"
#include "Blob.hpp"
#include "ofxClipper.h"
#include "ofxFaceTracker2.h"

class ofApp : public ofBaseApp{

	public:
    
//        Blob blob;
//        Blob blob2;
//        std::vector<ofPolyline> clips;
//        std::vector<std::pair<float, ofPolyline> > recordings;
//        float currentTime;
//        float startTime;
//        float endTime;
//        float elapsedTime;
//
//        bool hasStarted;
//        bool hasEnded;
//        bool isRecording;
//        bool replayStarted;
    
//        ofx::Clipper clipper;
//        ClipperLib::ClipType currentClipperType;
    
    
//        glm::vec3 pos;
//        glm::vec3 pos2;
//        glm::vec3 speed;
//
//        float yoff;
//        float radius;
//
//        ofPolyline currentReplayContour;
//        float currentReplayTime;
//        float replayStartTime;
    
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
    
//    ofPolyline currentFace;
//    int currentLabel;
//    int prevLabel;
//
//    float currentTime;
//    float startTIme;
//    float endTime;
//    float elapsedTime;
//
//    bool hasStarted;
//    bool hasEnded;
//    bool isRecording;
//    bool replayStarted;
		
};
