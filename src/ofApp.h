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
//        std::vector<ofxCvBlob> blobs;
        std::vector<ofPolyline> contours;
        int maxContours;
    
        ofVideoGrabber cam;
//        ofxCvColorImage colorImg;
//        ofxCvGrayscaleImage grayImg;
//        ofxCvGrayscaleImage grayDiff;
        float minArea, maxArea, threshold;
    
        ofxCv::ContourFinder contourFinder;
		
        ofFbo shapeFbo;
        ofFbo cameraFbo;
};
