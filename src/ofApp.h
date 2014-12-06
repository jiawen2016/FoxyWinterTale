#pragma once

#include "ofMain.h"
#include "Foxy.h"
#include "Track.h"
#include "particleController.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    int g_time;
    int g_time2;
    float g;
    float a;
    Foxy foxy;
    ofImage bg;
    float vYo;
    float vXo;
    float yPos;
    float xPos;
    float yt;
    float xt;
    float vy;
    float t;
    float ground;
    float keyUpPressed;
    vector<Track> tracks;
    Track piano;
    Track strings;
    Track percussion;
    Track guitar;
    ParticleController * mParticleController;
    ofImage mTextureImage;
    bool mFullscreen;
    bool mMouseDown;
    ofVec2f mMousePos;
    ofSoundPlayer drum;

    
		
};
