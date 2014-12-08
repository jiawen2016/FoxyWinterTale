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
void Track::setImg(string str,int i){
    img.loadImage(str);
    if(i==2)
        img.resize(ofGetWindowWidth()/10,ofGetWindowWidth()/10);
    else if(i==8)
        img.resize(ofGetWindowWidth()/4,ofGetWindowWidth()/8);
    else
        img.resize(ofGetWindowWidth()/14,ofGetWindowWidth()/14);
    w=img.getWidth();
    h=img.getHeight();
    step=i;
    
}
void Track::setPos(float xPos,float yPos){
    x=xPos;
    y=yPos;
}
void Track::setTrack(string str){
    track.loadSound(str);
}
