#pragma once

#include "ofMain.h"
#include "Blob.hpp"
#include "ofxClipper.h"

class ofApp : public ofBaseApp{

	public:
    
//        ofPolyline blob;
//        ofRectangle blobBounds;
    
        Blob blob;
        Blob blob2;
        std::vector<ofPolyline> clips;
        std::vector<std::pair<float, ofPolyline> > recordings;
        float currentTime;
        float startTime;
        float endTime;
        float elapsedTime;
        
        bool started;
        bool ended;
        bool recording;
        bool playing;
    
        ofx::Clipper clipper;
        ClipperLib::ClipType currentClipperType;
    
        ofVec3f pos;
        ofVec3f speed;
    
        ofVec3f pos2;
    
//        float xspeed = 1;
//        float yspeed = 3.3;
        float yoff;
        float radius;
    
//        ofPolyline buildBlob(int resolution);
    
        void setup();
		void update();
		void draw();
    
        void updateClipper();
        bool checkIntersection();
    
//        void drawBlob();
//        void updateBlob(ofPolyline& polyline, ofVec3f position, float w, float h);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
