//
//  Track.cpp
//  FoxyWinterTale
//
//  Created by LaParure on 12/6/14.
//
//

#include "Track.h"
#include "ofMain.h"
#include <string>

void Track::draw(){
    img.draw(x,y);
}
void Track::setImg(string str){
    img.loadImage(str);
    img.resize(ofGetWindowWidth()/7,ofGetWindowWidth()/7);
    w=img.getWidth();
    h=img.getHeight();
}
void Track::setPos(float xPos,float yPos){
    x=xPos;
    y=yPos;
}
void Track::setTrack(string str){
    track.loadSound(str);
}
