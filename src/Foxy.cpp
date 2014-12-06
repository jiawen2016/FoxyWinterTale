//
//  Foxy.cpp
//  FoxyWinterTale
//
//  Created by LaParure on 12/5/14.
//
//

#include "Foxy.h"
#include <string>
void Foxy::draw(){
    img.draw(x,y);
}
void Foxy::setImg(string str){
    img.loadImage(str);
    img.resize(ofGetWindowWidth()/10,ofGetWindowWidth()/10);
    w=img.getWidth();
    h=img.getHeight();
}
void Foxy::setPos(float xPos,float yPos){
    x=xPos;
    y=yPos;
}
