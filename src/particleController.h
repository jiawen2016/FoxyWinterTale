//
//  particleController.h
//  FoxyWinterTale
//
//  Created by LaParure on 12/6/14.
//
//

#ifndef __FoxyWinterTale__particleController__
#define __FoxyWinterTale__particleController__

#include <stdio.h>
#include "ofMain.h"
#include "particle.h"
#include "ofVectorMath.h"

class ParticleController {
    
public:
    ParticleController ();
    ParticleController ( ofTexture &ptext, ofVec2f pos, int rate, float psizemin, float psizemax, float direction, float directiondev );
    void update ();
    void draw ();
    
    void addParticle ( ofVec2f pos );
    void addParticles ( ofVec2f pos, int amt );
    void addParticles ( int amt );
    void removeParticles ( int amt );
    
    int getParticleCount ();
    
    std::list<Particle> mParticles;
    
    int mRate; // emitting rate
    int mRateDeviation; // emitting rate deviation
    float mParticleSizeMin;
    float mParticleSizeMax;
    ofVec2f mPosition; // position of the emitter
    float mDirection; // angle in degrees
    float mDirectionDeviation; // min/max deviation from Direction, angle in degrees
    ofTexture* mParticleTexture;
    
    int mColorIndex;
    int mDifferentColors;
    ofColor nextColor ();
    bool falling;
};


#endif /* defined(__FoxyWinterTale__particleController__) */
