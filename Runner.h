//
// Created by Jack Ende on 4/19/18.
//

#ifndef SLIM_SHADY_AND_THE_BEAVER_BROWN_BAND_RUNNER_H
#define SLIM_SHADY_AND_THE_BEAVER_BROWN_BAND_RUNNER_H

#include <unistd.h>
#include "floorSpikes.h"
#include "stdlib.h"


class Runner {
public:
    int height;
    int width;
    point center;
    color fill;
    point ogPos;

    //Default constructor
    //Requires: Nothing
    //Modifies: Nothing
    //Effects: Creates a default Runner as a 10x5 rectangle with black fill centered at (0,0)
    Runner();

    //Non-Default Constructors
    //Require: ints for height and width, doubles or color for fill, integers or point for center.
    //Modify: Nothing
    //Effect: Creates a runner objects using inputted parameters
    Runner(int h, int w);
    Runner(int h, int w, int x, int y, double rf, double gf, double bf);
    Runner(int h, int w, point c, color f);

    //Getters
    //Require: Nothing
    //Modify: Nothing
    //Effect: Return stored values for height, width, center, or fill.
    int getHeight() const;
    int getWidth() const;
    point getCenter() const;
    color getFill() const;
    point getOGPos() const;

    //Setters
    //Require: New integer, point, color, or double as parameter(s).
    //Modify: Runner fields
    //Effect: Sets new value for height, width, center, or fill.
    void setHeight(int nH);
    void setWidth(int nW);
    void setCenter(point nC);
    void setCenter(int nX, int nY);
    void setFill(color nF);
    void setFill(double rf, double gf, double bf);
    void setOGPos(int nX, int nY);
    void setOGPos(point nP);

    //Move Function
    //Requires: int deltaX, int deltaY
    //Modifies: Center field of Runner object
    //Effects: Changes the location of Runner object by shifting center coordinates.
    //Will be used for arrow key assignments in graphics portion.
    void move(int deltaX, int deltaY);

    //Draw Function
    //Requires: Nothing
    //Modifies: Graphics display
    //Effects: Will draw a square/rectangle in GLUT using fields of Runner object
    void draw() const;

    //Random Color Function
    //Requires: Nothing
    //Modifies: RGB doubles of Runner fill field
    //Effects: Changes the color of the Runner object
    void randomColor();

    bool isColliding(const floorSpikes &spikes) const;

    bool collectBoost(const Runner &boost) const;

};


#endif //SLIM_SHADY_AND_THE_BEAVER_BROWN_BAND_RUNNER_H
