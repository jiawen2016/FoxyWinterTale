//
//  Foxy.h
//  FoxyWinterTale
//
//  Created by LaParure on 12/5/14.
//
//

#ifndef __FoxyWinterTale__Foxy__
#define __FoxyWinterTale__Foxy__

#include <stdio.h>
#include "ofMain.h"
#include <string>
class Foxy{
public:
    // Methods
    void draw();
    void setImg(string str);
    void setPos(float xPos,float yPos);
    // Properties
    float g=9.81;
    float x;
    float y;
    ofImage img;
    float w;
    float h;
    bool jump=false;
    bool moveRight=false;
    bool moveLeft=false;
    bool rotate=false;
};

#endif /* defined(__FoxyWinterTale__Foxy__) */
