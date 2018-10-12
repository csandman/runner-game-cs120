#ifndef SLIM_SHADY_AND_THE_BEAVER_BROWN_BAND_OBSTACLE_H
#define SLIM_SHADY_AND_THE_BEAVER_BROWN_BAND_OBSTACLE_H

//Structs to use as fields in multiple classes
struct color
{
    double red;
    double green;
    double blue;

    color();
    color(double red, double green, double blue);
};

struct point
{
    int x;
    int y;

    point();
    point(int X, int Y);
};


class Obstacle {
public:
    int height;
    int width;
    point objectCorner;
    color objectFill;
    point ogPos;





    //constructors
    Obstacle();
    Obstacle(int nHeight, int nWidth, int X, int Y);
    Obstacle(int nHeight, int nWidth, int X, int Y, double red, double green, double blue);


    /**
     * getters
     */
    int getHeight();
    int getWidth();
    point getCorner();


    /**
     * setters
     */
    void setHeight(int nHeight);
    void setWidth(int nWidth);
    void setCorner(int x, int y);
    void setCorner(point p);
    void setColor(double red, double green, double blue);
    void setColor(color c);


    void move(int deltaX, int deltaY);

    //pure virtuals
    //override for different obstacles
    virtual int calcArea() = 0;
    virtual double calcPerimeter() = 0;
    virtual void draw() = 0;

};


#endif //SLIM_SHADY_AND_THE_BEAVER_BROWN_BAND_OBSTACLE_H
