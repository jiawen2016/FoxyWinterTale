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
        img.resize(ofGetWindowWidth()/9,ofGetWindowWidth()/9);
    else if(i==1)
        img.resize(ofGetWindowWidth()/11.5,ofGetWindowWidth()/11.5);
    else if(i==9){
        img.resize(ofGetWindowWidth()/4,ofGetWindowWidth()/8);
        flag=true;
    }
    else
        img.resize(ofGetWindowWidth()/12,ofGetWindowWidth()/12);
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
