//
// Created by Jack Ende on 5/2/18.
//

#ifndef SLIM_SHADY_AND_THE_BEAVER_BROWN_BAND_BUTTON_H
#define SLIM_SHADY_AND_THE_BEAVER_BROWN_BAND_BUTTON_H
#include "Obstacle.h"

class Button {
private:
    int height;
    int width;
    point center;
    color fill;
    color border;

public:
    //Default Constructor
    //Requires: Nothing
    //Modifies: Nothing
    //Effects: Creates a default button as a 10x5 rectangle with black fill centered at (0,0)
    Button();

    //Non-Default Constructors
    //Require: ints for height and width, doubles or color for fill/border, integers or point for center.
    //Modify: Nothing
    //Effect: Create buttons using inputted parameters
    Button(int h, int w);
    Button(int h, int w, int x, int y, double rf, double gf, double bf);
    Button(int h, int w, int x, int y, color f, color b);
    Button(int h, int w, point c, color f, color b);

    //Getters
    //Require: Nothing
    //Modify: Nothing
    //Effect: Return stored values for height, width, center, fill, or border.
    int getHeight() const;
    int getWidth() const;
    point getCenter() const;
    color getFill() const;
    color getBorder() const;

    //Setters
    //Require: New integer, point, color, or double as parameter(s).
    //Modify: Button fields
    //Effect: Sets new value for height, width, center, fill, or border.
    void setHeight(int nH);
    void setWidth(int nW);
    void setCenter(point nC);
    void setCenter(int nX, int nY);
    void setFill(color nF);
    void setFill(double rf, double gf, double bf);
    void setBorder(color nB);
    void setBorder(double rb, double gb, double bb);

    //Border Highlight Function
    //Requires: Nothing
    //Modifies: Border field of button object.
    //Effects: "Highlights" the border of the button by changing it to white.
    void highlightBorder();

    //Draw Function
    //Requires: Nothing
    //Modifies: Graphics display
    //Effects: Will draw a square/rectangle in GLUT using fields of Button object.
    void draw() const;

    bool isOverlapping(const point &p) const;

    void move(int deltaX, int deltaY);
};


#endif //SLIM_SHADY_AND_THE_BEAVER_BROWN_BAND_BUTTON_H
