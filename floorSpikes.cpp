#include "floorSpikes.h"
#include <iostream>
using namespace std;

//square obstacle

floorSpikes::floorSpikes() {};
floorSpikes::floorSpikes(int nHeight, int nWidth, int X, int Y) {
    height = nHeight;
    width = nWidth;
    objectCorner = point(X,Y);
    ogPos = point(X,Y);
}
floorSpikes::floorSpikes(int nHeight, int nWidth, int X, int Y, double red, double green, double blue) {
    height = nHeight;
    width = nWidth;
    objectCorner = point(X,Y);
    objectFill = color(red, green, blue);
    ogPos = point(X,Y);
}

int floorSpikes::calcArea() {
    return width * height;
}

double floorSpikes::calcPerimeter() {
    return (2*width + 2*height);
}

void floorSpikes::draw() {
    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(objectCorner.x,objectCorner.y);
    glVertex2i(objectCorner.x + width,objectCorner.y);
    glVertex2i(objectCorner.x + width/2,objectCorner.y - height);
    glEnd();
}