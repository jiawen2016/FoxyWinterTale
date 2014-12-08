//
//  particle.cpp
//  FoxyWinterTale
//
//  Created by LaParure on 12/6/14.
//
//

#include "particle.h"
Particle::Particle () {
    
    mPos = ofVec2f ( ofRandomWidth (), ofRandomWidth () );
    setup ();
    
}

//--------------------------------------------------------------
Particle::Particle ( ofVec2f pos ) {
    
    mPos = pos;
    setup ();
    
}
//--------------------------------------------------------------
Particle::Particle ( ofVec2f pos, ofVec2f vel, float size, ofTexture* texture ) {
    
    mPos = pos;
    mVel = vel;
    mTop=mPos;
    mSize = size;
    mTexture = texture;
    
    mAge = 0;
    mLifetime = 200;
    mDead = false;
    mFalling=false;
    
}

//--------------------------------------------------------------
Particle::~Particle () {
    //cout << "Particle destructed" << endl;
}

//--------------------------------------------------------------
void Particle::setup () {
    
    mVel = ofVec2f ( ofRandomf (), ofRandomf () ) * 10;
    mSize = 5.0;
    
    mAge = 0;
    mLifetime = 200;
    mDead = false;
    mFalling=false;
}

//--------------------------------------------------------------
void Particle::update () {
    mAge++;
    
    if(mFalling){
        mLifetime=200;
        
    }
    
    mPos+=mVel;
    if(mAge>mLifetime)
        mDead = true;
    
}

//--------------------------------------------------------------
void Particle::draw () {
    float x = mPos.x - ( mSize / 2 );
    float y = mPos.y - ( mSize / 2 );
    //glEnable ( GL_BLEND );
    //glBlendFunc ( GL_SRC_ALPHA, GL_ONE );
    //glBlendFunc ( GL_ONE, GL_ONE );
    //ofSetColor ( mColorR, mColorG, mColorB, mOpacity );
    mTexture->draw ( x, y, mSize, mSize );
    //glDisable ( GL_BLEND );
    //ofFill ();
    //    ofCircle ( mPos.x, mPos.y, mSize * ( (float) ( mLifetime - mAge ) / (float) mLifetime ) );
    //ofCircle ( mPos.x, mPos.y, mSize );
}

//--------------------------------------------------------------
bool Particle::isOffscreen () {
    return ( mPos.x < 0 || mPos.y < 0 || mPos.x > ofGetWidth() || mPos.y > ofGetHeight() );
}

//--------------------------------------------------------------
void Particle::setColor ( int r, int g, int b ) {
    mColorR = r;
    mColorG = g;
    mColorB = b;
}
//--------------------------------------------------------------
void Particle::setColor ( ofColor c ) {
    mColorR = c.r;
    mColorG = c.g;
    mColorB = c.b;
}