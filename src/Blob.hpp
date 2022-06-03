#pragma once

#include "ofMain.h"

class Blob {
    public:
        Blob() {}
        
        void build(int resolution);
        void update(ofVec3f position, float w, float h);
        void draw();
        void drawBounds();
        void checkCollision();
    
        ofPolyline getPolyline();
    
        ofPolyline polyline;
        ofRectangle bounds;
    
        ofVec3f position;
        ofVec3f speed;
        float yoff;
};
