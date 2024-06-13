#pragma once

#include "ofMain.h"
#include "Blob.hpp"
#include "ofxClipper.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{

	public:    
        void setup();
		void update();
		void draw();
    
        ofPath path;
        std::vector<ofPath> contours;
        std::vector<ofxCvBlob> blobs;
        int maxContours;
    
        ofVideoGrabber cam;
        ofxCvColorImage colorImg;
        ofxCvGrayscaleImage grayImg;
        ofxCvGrayscaleImage grayDiff;
        ofxCvContourFinder contourFinder;
        int threshold;
		
        ofFbo shapeFbo;
        ofFbo cameraFbo;
};
