#pragma once

#include "ofMain.h"
#include "Blob.hpp"
#include "ofxClipper.h"
#include "ofxCv.h"
//#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{

	public:    
        void setup();
		void update();
		void draw();
        ofPath polylineToPath(ofPolyline& polyline);
    
        ofPath path;
        std::vector<ofPath> paths;
        std::vector<ofPolyline> contours;
        std::vector<std::pair<float, ofPolyline>> recordings;
        int maxContours;
    
        ofVideoGrabber cam;
        float minArea, maxArea, threshold;
    
        ofxCv::ContourFinder contourFinder;
		
        ofFbo shapeFbo;
        ofFbo cameraFbo;
};
