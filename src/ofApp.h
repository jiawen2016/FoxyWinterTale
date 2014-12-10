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
    ofImage cover;
    ofImage instruction;
    ofImage credits;
    bool entered=false;
    bool instructed=false;
    bool stopped=false;
    float vYo;
    float vXo;
    float yPos;
    float xPos;
    float yt;
    float xt;
    float vy;
    float t;
    float ground;
    float ceiling;
    int pressed;
    vector<Track> tracks;
    ParticleController * mParticleController;
    ParticleController * mParticleController2;
    ofImage mTextureImage;
    ofImage mTextureImage2;
    bool mFullscreen;
    bool mMouseDown;
    bool snow=false;
    bool gifts=false;
    ofVec2f mSnowPos;
    ofVec2f mGiftPos;
    ofSoundPlayer drum;
    ofSoundPlayer accompany;
    int scale=10;

    //Sina Dec 6 2014////////
    /*
    int pitch_num = 68;
    int pitchs[68] = {
        
        
                     1,1,1,2,
                     2,3,8,6,
                     1,1,1,2,
                     2,8,8,4,
                     6,6,6,5,
                     7,7,6,5,
                     6,6,6,5,
                     7,7,8,4,
                        1,1,1,2,
                        2,3,8,6,
                        1,1,1,2,
                        2,8,8,4,
                        6,6,6,5,
                        7,7,6,5,
                        6,6,6,5,
                        7,7,8,4,
                        7,7,8,4,
    };
    int rymth[68] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    int dist[69];
     */
    
     int pitch_num = 73;
     int pitchs[73] = {
     
     0,0,0,0,0,0,
     1,1,1,2,
     2,3,8,6,
     1,1,1,2,
     2,8,8,4,
     6,6,6,6,
     7,7,6,5,
     6,6,6,6,
     7,7,8,4,
     1,1,1,2,
     2,3,8,6,
     1,1,1,2,
     2,8,8,4,
     6,6,6,6,
     7,7,6,5,
     6,6,6,6,
     7,7,8,4,
     7,7,9,
     };
    int rymth[73] = {2,2,2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,2,2,
                     2,2,4,
                    };
    int dist[74];

    float x_space;
    float x_speed;
    bool started=false;
    bool startedMoving=false;
    int miss=0;
    int success=0;
    float score=0.f;
};
