//
// Created by Jack Ende on 5/2/18.
//
#include "Button.h"
#include "graphics.h"
#include <memory>
using namespace std;

Button::Button()
{
    height = 10;
    width = 20;
    center = point(250,250);
    fill = color(1,0,0);
    border = color(1,0,0);
}

Button::Button(int h, int w)
{
    height = h;
    width = w;
    center = point(250,250);
    fill = color(1,0,0);
    border = color(1,0,0);
}

Button::Button(int h, int w, int x, int y, double rf, double gf, double bf)
{
    height = h;
    width = w;
    center = point(x,y);
    fill = color(rf,gf,bf);
    border = color(rf,gf,bf);
}

Button::Button(int h, int w, int x, int y, color f, color b)
{
    height = h;
    width = w;
    center = point(x,y);
    fill = f;
    border = b;
}
Button::Button(int h, int w, point c, color f, color b)
{
    height = h;
    width = w;
    center = c;
    fill = f;
    border = b;
}

int Button::getHeight() const
{
    return height;
}

int Button::getWidth() const
{
    return width;
}

point Button::getCenter() const
{
    return center;
}

color Button::getFill() const
{
    return fill;
}

color Button::getBorder() const
{
    return border;
}

void Button::setHeight(int nH)
{
    height = nH;
}

void Button::setWidth(int nW)
{
    width = nW;
}

void Button::setCenter(int nX, int nY)
{
    center = point(nX,nY);
}

void Button::setCenter(point nC)
{
    center = nC;
}

void Button::setFill(double rf, double gf, double bf)
{
    fill = color(rf,gf,bf);
}

void Button::setFill(color nF)
{
    fill = nF;
}

void Button::setBorder(double rb, double gb, double bb)
{
    border = color(rb,gb,bb);
}

void Button::setBorder(color nB)
{
    border = nB;
}

void Button::highlightBorder()
{
    border = color(1,1,1);
}

void Button::draw() const
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

    glLineWidth((GLfloat)5.0);
    // draw border
    glColor3f(border.red, border.green, border.blue);
    glBegin(GL_LINE_STRIP);
    // top left
    glVertex2i(center.x-(width/2.0), center.y-(height/2.0));
    // top right
    glVertex2i(center.x+(width/2.0), center.y-(height/2.0));
    // bottom right
    glVertex2i(center.x+(width/2.0), center.y+(height/2.0));
    // bottom left
    glVertex2i(center.x-(width/2.0), center.y+(height/2.0));
    // top left
    glVertex2i(center.x-(width/2.0), center.y-(height/2.0));
    glEnd();
}

bool Button::isOverlapping(const point &p) const {
    return (p.x >= center.x-(width/2.0) && // left side
            p.x <= center.x+(width/2.0) && // right side
            p.y >= center.y-(height/2.0) && // top
            p.y <= center.y+(height/2.0)); // bottom
}

void Button::move(int deltaX, int deltaY){
    center.x += deltaX;
    center.y += deltaY;
}