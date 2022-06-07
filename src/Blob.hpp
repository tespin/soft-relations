#pragma once

#include "ofMain.h"

class Blob {
    public:
        Blob() {}
        
        void build(int resolution);
        void update(glm::vec3 position, float w, float h);
        void draw();
        void drawBounds();
        void checkCollision();
        void assignPolyType();
    
        ofPolyline getPolyline();
    
        ofPolyline polyline;
        ofRectangle bounds;
    
//        ofVec3f position;
//        ofVec3f speed;
        glm::vec3 position;
        glm::vec3 speed;
        float yoff;
};
