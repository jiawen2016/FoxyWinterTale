//
//  particleController.cpp
//  FoxyWinterTale
//
//  Created by LaParure on 12/6/14.
//
//

#include "particleController.h"
ParticleController::ParticleController () {
}

ParticleController::ParticleController ( ofTexture& ptext, ofVec2f pos, int rate, float psizemin, float psizemax, float direction, float directiondev ) {
    
    mColorIndex = 0;
    mDifferentColors = 1200;
    
    mPosition = pos;
    mRate = rate;
    mParticleSizeMin = psizemin;
    mParticleSizeMax = psizemax;
    mDirection = direction;
    mDirectionDeviation = directiondev;
    mParticleTexture = &ptext;
    falling=false;
}


//--------------------------------------------------------------
void ParticleController::update () {
    
    
    for ( std::list<Particle>::iterator p = mParticles.begin (); p != mParticles.end (); )
    {
        p->mFalling =falling;
        if ( p->isOffscreen ()||p->mDead)
        {
            //for ( std::list<Particle>::iterator p = mParticles.begin (); p != mParticles.end (); ++p )
            //{
            p = mParticles.erase ( p );
            //}
            //return;
            
            
        } else {
            p->update ();
            p++;
        }
    }
    for ( int i = 0; i < mRate; ++i )
    {
        float size = ofRandom ( mParticleSizeMin, mParticleSizeMax );
        ofVec2f vel = ofVec2f( size / 4 , 0);
        vel.rotate( ofRandom ( mDirection - mDirectionDeviation, mDirection + mDirectionDeviation) );
        Particle tmpParticle = Particle ( mPosition, vel , size, mParticleTexture );
        //tmpParticle.setColor ( nextColor () );
        mParticles.push_back ( tmpParticle );
    }
    
}

//--------------------------------------------------------------
void ParticleController::draw () {
    
    for ( std::list<Particle>::iterator p = mParticles.begin (); p != mParticles.end (); ++p )
    {
        p->draw();
    }
}

//--------------------------------------------------------------
void ParticleController::addParticle ( ofVec2f pos ) {
    mParticles.push_back ( Particle ( pos ) );
}

//--------------------------------------------------------------
void ParticleController::addParticles ( ofVec2f pos, int amt ) {
    
    for ( int i = 0; i < amt; ++i )
    {
        mParticles.push_back ( Particle ( pos ) );
    }
}

//--------------------------------------------------------------
void ParticleController::addParticles ( int amt ) {
    
    for ( int i = 0; i < amt; ++i )
    {
        mParticles.push_back ( Particle () );
    }
}

//--------------------------------------------------------------
void ParticleController::removeParticles ( int amt ) {
    
}

//--------------------------------------------------------------
int ParticleController::getParticleCount () {
    return mParticles.size();
}

//--------------------------------------------------------------
ofColor ParticleController::nextColor () {
    float f, p1, p2;
    ofColor c;
    
    f =  TWO_PI*2 / mDifferentColors;
    p1 = TWO_PI / 3;
    p2 = p1 * 2;
    
    c.r = sin(mColorIndex * f + 0) * 127 + 128;
    c.g = sin(mColorIndex * f + p1) * 127 + 128;
    c.b = sin(mColorIndex++ * f + p2) * 127 + 128;
    return c;
}
