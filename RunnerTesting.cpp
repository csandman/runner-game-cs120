//
// Created by Jack Ende on 4/20/18.
//

#include "Runner.h"
#include <iostream>
using namespace std;

/*int main(){
    color black;
    color salmon(250,128,114);

    point origin;
    point fquad(1,1);

    Runner Default;
    cout << "Default Constructor Test: " << endl;
    cout << "Height should be 10: " << Default.getHeight() << endl;
    cout << "Width should be 5: " << Default.getWidth() << endl;
    cout << "Center should be 0,0: " << Default.getCenter().x << "," << Default.getCenter().y << endl;
    cout << "Color values should be 0,0,0: " << Default.getFill().red << "," << Default.getFill().green
         << "," << Default.getFill().blue << endl;

    Runner r1(15,15);
    cout << "\nNon-Default Constructor Test 1: " << endl;
    cout << "Height should be 15: " << r1.getHeight() << endl;
    cout << "Width should be 15: " << r1.getWidth() << endl;
    cout << "Center should be 0,0: " << r1.getCenter().x << "," << r1.getCenter().y << endl;
    cout << "Color values should be 0,0,0: " << r1.getFill().red << "," << r1.getFill().green
         << "," << r1.getFill().blue << endl;

    Runner r2(20,10,3,2,255,255,255);
    cout << "\nNon-Default Constructor Test 2: " << endl;
    cout << "Height should be 20: " << r2.getHeight() << endl;
    cout << "Width should be 10: " << r2.getWidth() << endl;
    cout << "Center should be 3,2: " << r2.getCenter().x  << "," << r2.getCenter().y << endl;
    cout << "Color values should be 255,255,255: " << r2.getFill().red << "," << r2.getFill().green
                                                                              << "," << r2.getFill().blue << endl;

    Runner r3(17,17,fquad,salmon);
    cout << "\nNon-Default Constructor Test 3: " << endl;
    cout << "Height should be 17: " << r3.getHeight() << endl;
    cout << "Width should be 17: " << r3.getWidth() << endl;
    cout << "Center should be 1,1: " << r3.getCenter().x << "," << r3.getCenter().y << endl;
    cout << "Color values should be 250,128,114: " << r3.getFill().red << "," << r3.getFill().green
                                                                              << "," << r3.getFill().blue << endl;
    Runner r4;
    r4.setHeight(25);
    r4.setWidth(15);
    r4.setCenter(5,5);
    r4.setFill(50,50,50);

    cout << "\nSetters Testing: " << endl;
    cout << "Height should be 25: " << r4.getHeight() << endl;
    cout << "Width should be 15: " << r4.getWidth() << endl;
    cout << "Center should be 5,5: " << r4.getCenter().x << "," << r4.getCenter().y << endl;
    cout << "Color values should be 50,50,50: " << r4.getFill().red << "," << r4.getFill().green
                                                                           << "," << r4.getFill().blue << endl;
    r4.setCenter(fquad);
    r4.setFill(salmon);
    cout << "Center should now be 1,1: " << r4.getCenter().x << "," << r4.getCenter().y << endl;
    cout << "Color values should now be 250,128,114: " << r4.getFill().red << "," << r4.getFill().green
                                                       << "," << r4.getFill().blue << endl;

    cout << "\nMove Function Testing: " << endl;
    cout << "First position should be 1,1: " << r4.getCenter().x << "," << r4.getCenter().y << endl;
    r4.move(3,3);
    cout << "Now position should be 4,4: " << r4.getCenter().x << "," << r4.getCenter().y << endl;
};*/

