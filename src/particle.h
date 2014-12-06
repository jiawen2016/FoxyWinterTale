//
//  particle.h
//  FoxyWinterTale
//
//  Created by LaParure on 12/6/14.
//
//

#ifndef __FoxyWinterTale__particle__
#define __FoxyWinterTale__particle__

#include <stdio.h>
#include <fstream>
#include <string>
#include "ofVectorMath.h"
#include "ofMain.h"

class Particle {
    
public:
    Particle ();
    Particle ( ofVec2f pos );
    Particle ( ofVec2f pos, ofVec2f vel, float size, ofTexture* texture );
    ~Particle ();
    void setup ();
    
    void update ();
    void draw ();
    bool isOffscreen ();
    
    void setColor ( int r, int g, int b );
    void setColor ( ofColor c );
    
    ofVec2f mPos;
    ofVec2f mVel;
    ofVec2f mTop;
    
    float mSize;
    
    int mAge;
    int mLifetime;
    bool mDead;
    
    
    ofTexture* mTexture;
    
    int mColorR;
    int mColorG;
    int mColorB;
    int mOpacity;
    
    bool mFalling;
    
};


#endif /* defined(__FoxyWinterTale__particle__) */
