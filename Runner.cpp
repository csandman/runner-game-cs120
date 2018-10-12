//
// Created by Jack Ende on 4/19/18.
//

#include "Runner.h"
#include <iostream>
#include "graphics.h"

using namespace std;

point::point() : x(0), y(0) { }

point::point(int X, int Y) : x(X), y(Y) { }

color::color() : red(0), green(0), blue(0) { }

color::color(double red, double green, double blue) : red(red), green(green), blue(blue) { }

Runner::Runner()
{
    height = 10;
    width = 5;
    center = point();
    fill = color();
    ogPos = point();
}

Runner::Runner(int h, int w)
{
    height = h;
    width = w;
    center = point();
    fill = color();
    ogPos = point();
}


Runner::Runner(int h, int w, int x, int y, double rf, double gf, double bf)
{
    height = h;
    width = w;
    center = point(x,y);
    fill = color(rf,gf,bf);
    ogPos = point(x,y);
}

Runner::Runner(int h, int w, point c, color f)
{
    height = h;
    width = h;
    center = c;
    fill = f;
    ogPos = c;
}

int Runner::getHeight() const
{
    return height;
}

int Runner::getWidth() const
{
    return width;
}

point Runner::getCenter() const
{
    return center;
}

color Runner::getFill() const
{
    return fill;
}

point Runner::getOGPos() const
{
    return ogPos;
}

void Runner::setHeight(int nH)
{
    height = nH;
}

void Runner::setWidth(int nW)
{
    width = nW;
}

void Runner::setCenter(point nC)
{
    center = nC;
}

void Runner::setCenter(int nX, int nY)
{
    center = point(nX,nY);
}

void Runner::setFill(color nF)
{
    fill = nF;
}

void Runner::setFill(double rf, double gf, double bf)
{
    fill = color(rf,gf,bf);
}

void Runner::setOGPos(int nX, int nY)
{
    ogPos = point(nX,nY);
}

void Runner::setOGPos(point nP)
{
    ogPos = nP;
}

void Runner::move(int deltaX, int deltaY)
{
    center.x += deltaX;
    center.y += deltaY;
}

void Runner::draw() const
{
    // draw fill
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    // top left
    glVertex2i(center.x-(width/2.0), center.y-(height/2.0));
    // top right
    glVertex2i(center.x+(width/2.0), center.y-(height/2.0));
    // bottom right
    glVertex2i(center.x+(width/2.0), center.y+(height/2.0));
    // bottom left
    glVertex2i(center.x-(width/2.0), center.y+(height/2.0));
    glEnd();
}

void Runner::randomColor()
{
    double r = rand() % 255 + 1;
    double g = rand() % 255 +1;
    double b = rand() % 255 +1;

    fill.red = (r/255.0);
    fill.green = (g/255.0);
    fill.blue = (b/255.0);
}

bool Runner::isColliding(const floorSpikes &spikes) const {
    return !(center.x+(width/2.0) < spikes.objectCorner.x || // self is left of rectangle
             spikes.objectCorner.x + spikes.width < center.x-(width/2.0) || // rectangle is left of self
             center.y-(height/2.0) > spikes.objectCorner.y || // self is below rectangle
             spikes.objectCorner.y-(spikes.height) > center.y+(height/2.0)); // rectangle is below self
}

bool Runner::collectBoost(const Runner &boost) const {
    return !(center.x+(width/2.0) < (boost.center.x - boost.width/2.0) || // self is left of rectangle
             boost.center.x + (boost.width /2.0) < center.x-(width/2.0) || // rectangle is left of self
              center.y-(height/2.0) > (boost.center.y + boost.height/2.0) || // self is below rectangle
             boost.center.y - boost.height/2.0 > center.y+(height/2.0)); // rectangle is below self
}
