//
//  Track.h
//  FoxyWinterTale
//
//  Created by LaParure on 12/6/14.
//
//

#ifndef __FoxyWinterTale__Track__
#define __FoxyWinterTale__Track__

#include <stdio.h>
#include "ofMain.h"
#include <string>
class Track{
public:
    // Methods
    void draw();
    void setImg(string str);
    void setPos(float xPos,float yPos);
    void setTrack(string str);
    // Properties
    ofImage img;
    ofSoundPlayer track;
    float x;
    float y;
    float w;
    float h;
};

#endif /* defined(__FoxyWinterTale__Track__) */
