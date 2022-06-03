//
//  Blob.cpp
//  intersection-test
//
//  Created by Tristan Espinoza on 5/30/22.
//

#include "Blob.hpp"

void Blob::build(int resolution) {
    for (int i = 0; i < resolution; i++) {
        polyline.addVertex(0, 0);
    }
    
    polyline.close();
}

void Blob::update(ofVec3f position, float w, float h) {
    float xoff = 0;
    float step = TWO_PI / polyline.size();
    for (int i = 0; i < polyline.size(); i++) {
        float offset = ofMap(ofNoise(xoff, yoff), 0, 1, -10, 10);
        float woff = w + offset;
        float hoff = h + offset;
        
        polyline[i].x = position.x + woff * cos(i*step);
        polyline[i].y = position.y + hoff * sin(i*step);
        
        xoff += 0.1;
    }
    yoff += 0.01;
}

void Blob::draw() {
    ofSetColor(0);
    polyline.draw();
}

void Blob::drawBounds() {
    ofSetColor(255, 0, 0);
    ofDrawRectangle(bounds);
}

void Blob::checkCollision() {
    
}

ofPolyline Blob::getPolyline() {
    return polyline;
}
