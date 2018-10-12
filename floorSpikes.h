#ifndef SLIM_SHADY_AND_THE_BEAVER_BROWN_BAND_FLOORSPIKES_H
#define SLIM_SHADY_AND_THE_BEAVER_BROWN_BAND_FLOORSPIKES_H

#include "Obstacle.h"
#include "graphics.h"

class floorSpikes : public Obstacle{
public:

    //constructors
    floorSpikes();
    floorSpikes(int nHeight, int nWidth, int X, int Y);
    floorSpikes(int nHeight, int nWidth, int X, int Y, double red, double green, double blue);

    //overriden from base Obstacle
    int calcArea() override;
    double calcPerimeter() override;
    void draw() override;

};


#endif //SLIM_SHADY_AND_THE_BEAVER_BROWN_BAND_FLOORSPIKES_H
