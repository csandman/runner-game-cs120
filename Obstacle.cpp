#include "Obstacle.h"
#include <iostream>

using namespace std;


Obstacle::Obstacle(){};

Obstacle::Obstacle(int nHeight, int nWidth, int X, int Y) {
    height = nHeight;
    width = nWidth;
    objectCorner = point(X, Y);

}

Obstacle::Obstacle(int nHeight, int nWidth, int X, int Y, double red, double green, double blue) {
    height = nHeight;
    width = nWidth;
    objectCorner = point(X,Y);
    objectFill = color(red, green, blue);
}

int Obstacle::getHeight() {
    return height;
}

int Obstacle::getWidth() {
    return width;
}

point Obstacle::getCorner() {
    return objectCorner;
}


void Obstacle::setHeight(int nHeight) {
    height = nHeight;
}

void Obstacle::setWidth(int nWidth) {
    width = nWidth;
}

void Obstacle::setCorner(int x, int y) {
    objectCorner = point(x,y);
}

void  Obstacle::setCorner(point p) {
    objectCorner = point(p.x,p.y);
}

void Obstacle::setColor(double red, double green, double blue) {
    objectFill = color(red, green, blue);
}

void Obstacle::setColor(color c) {
    objectFill = color(c.red,c.green,c.blue);
}

void Obstacle::move(int deltaX, int deltaY)
{
    objectCorner.x += deltaX;
    objectCorner.y += deltaY;
}