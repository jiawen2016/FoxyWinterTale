#include "ofApp.h"
#include <string>
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
    mFullscreen = false;
    mMouseDown = false;
    ofSetVerticalSync ( true );
    ofBackground ( 0,0,0 );
    mTextureImage.loadImage("3.png");
    mParticleController = new ParticleController ( mTextureImage.getTextureReference(), ofVec2f ( ofGetWidth()-100, ofGetHeight() - 20 ), 3, 10.0, 20.0,90, 60 );

    ofSetFrameRate ( 30 );
    ofSetWindowTitle("FoxyTale");
    bg.loadImage("WinterMoon.jpg");
    bg.resize(ofGetWindowWidth(),ofGetWindowHeight());
    foxy.setImg("foxy.png");
    g=9.81;
    a=g;
    ground=ofGetWindowHeight()*0.75f;
    foxy.setPos(ofGetWindowWidth()*0.05, ground);
    vYo=pow((ofGetHeight()*0.1*2*g), 0.5);
    vXo=ofGetWindowWidth()/135.f;
    vy=vYo;
    /*
    tracks.push_back(piano);
    tracks.push_back(strings);
    tracks.push_back(percussion);
    tracks.push_back(guitar);
     */
    drum.loadSound(".mp3");
    drum.play();
    drum.setVolume(1.f);
    Track m;
  //Sina Dec 6 2014////////
    x_space = 0.08;
    
    for (int i=0;i<4;i++){
        tracks.push_back(m);
    }
    
    dist[0] = 0;
    for (int i=1;i<tracks.size() + 1;i++) {
        dist[i]= dist[i-1] + rymth[i-1];
    }
    
    for (int i=0;i<tracks.size();i++) {
        tracks[i].setPos((ofGetWindowWidth()*x_space)*(dist[i]+2),ofGetWindowHeight()*0.25*pitchs[i]);
        std::stringstream ss;
        ss <<pitchs[i]<<".png";
        tracks[i].setImg(ss.str());
    }
    //Sina Dec 6 2014////////
    g_time2=0;

}

//--------------------------------------------------------------
void ofApp::update(){
    if ( mMouseDown )
    {
        mParticleController->mPosition = mMousePos;
    }
    mParticleController->update ();
    bg.resize(ofGetWindowWidth(),ofGetWindowHeight());
    foxy.img.resize(ofGetWindowWidth()/scale,ofGetWindowWidth()/scale);
    if(g_time==0) t=0;
    else t=(float)g_time/2;
    if(foxy.jump){
        //cout<<foxy.y<<endl;
        vy=vy-a;
        yt +=vy-0.5*a;
        //yt+=vy*0.5;
        if(vYo>0)
            yPos=ground-yt;
        else
            yPos=ceiling-yt;
        if(yPos>ground){
            foxy.jump=false;
            g_time=0;
            vYo=pow((ofGetHeight()*0.1*2*g), 0.5);
            vy=vYo;
            yt=0;
            foxy.y = ground;
            a=g;
        }
        if(yPos<0.f){
            foxy.y=0.f;
            vy=0;
            vYo=0;
            ceiling=0.f;
            yt=0;
            a=g;
            g_time=0;
        }
        else{
            foxy.y=yPos;
            g_time++;
        }
    }
        xPos=vXo*g_time2;
        if(xPos>ofGetWindowWidth()){
            g_time2=1;
            xPos=vXo*g_time2;
        }
        else{
            foxy.x=xPos;
        }
        g_time2++;

    /*
    if(foxy.moveLeft){
        foxy.x=vXo*t;
        g_time++;
    }*/
    if(foxy.rotate){
        foxy.img.rotate90(1);
    }
    /*
    if(foxy.x <= 0||foxy.x >= ofGetWindowWidth()-foxy.w)
    {
        foxy.x = ofGetWindowWidth()*0.05;
    }*/
    if(foxy.y > ground)
    {
        foxy.y = ground;
    }
    if(foxy.y <= 0)
    {
        foxy.y = 0;
    }
    
    for (int i=0;i<tracks.size();i++) {
        //printf("%d %d %d ")
        if(foxy.x<=tracks[i].x+tracks[i].w + 50 &&foxy.x>=tracks[i].x+tracks[i].w && tracks[i].flag == false){
           // cout<<foxy.x<<" "<<foxy.y<<endl;
            drum.setVolume(0.f);
            cout << "miss"<<endl;
        }
        
        if(abs(foxy.x + foxy.w/2- tracks[i].x - tracks[i].w/2) < 50 && abs(foxy.y + foxy.h/2- tracks[i].y - tracks[i].h/2) < 50  ) {
           tracks[i].y = -10000;
            tracks[i].flag = 1;
            //foxy.success=true;
           drum.setVolume(1.0);
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    bg.draw(0,0);
    for (int i=0;i<tracks.size();i++) {
        tracks[i].draw();
    }
    foxy.draw();
    mParticleController->draw ();
    //ofSetColor ( 0xffffff);
    ofDrawBitmapString ( "FPS: " + ofToString ( ofGetFrameRate() ), 10, 20 );
    ofDrawBitmapString ( "Particles: " + ofToString ( mParticleController->getParticleCount() ), 10, 30 );
    //ofSetColor ( 0x0080FF );
    //ofDrawBitmapString ( "Press/drag mouse to spawn particles", ofGetWidth() - (35*8) - 10, 20 );
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==OF_KEY_UP){
        foxy.jump=true;
        a-=6.5f;
        
    }
    if(key==OF_KEY_RIGHT){
        if(!foxy.moveLeft&&foxy.moveRight){
            foxy.img.mirror(false, true);
            foxy.moveLeft=true;
            foxy.moveRight=false;
        }
    }
    if(key==OF_KEY_LEFT){
        if(foxy.moveLeft&&!foxy.moveRight){
            foxy.img.mirror(false, true);
            foxy.moveRight=true;
            foxy.moveLeft=false;
        }

    }
    if(key==OF_KEY_DOWN){
        foxy.rotate=true;
    }
      switch (key){
          case 'f':
          case 'F':
              mFullscreen = !mFullscreen;
              ofSetFullscreen ( mFullscreen );
              break;
          case '1':
              mParticleController->falling=true;
              break;

          case '2':
              if(piano.track.getVolume()==0)
                  piano.track.setVolume(1.0);
              else
                  piano.track.setVolume(0);
              break;
        case '3':
              if(strings.track.getVolume()==0)
                  strings.track.setVolume(1.0);
              else
                  strings.track.setVolume(0);
              break;
          case '4':
              if(percussion.track.getVolume()==0)
                  percussion.track.setVolume(1.0);
              else
                  percussion.track.setVolume(0);
              break;
          case '5':
              if(guitar.track.getVolume()==0)
                  guitar.track.setVolume(1.0);
              else
                  guitar.track.setVolume(0);
    
              break;
      }

    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key==OF_KEY_UP){
        a=g;
    }
    if(key==OF_KEY_RIGHT){
        //foxy.moveLeft=true;
        //foxy.img.mirror(false, true);
       
    }
    if(key==OF_KEY_LEFT){
        //foxy.moveRight=true;
    }
    
    if(key==OF_KEY_DOWN){
        foxy.rotate=false;
        foxy.setImg("foxy.png");
    }
    
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
     mMousePos = ofVec2f ( x, y );
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
     mMousePos = ofVec2f ( x, y );
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mMouseDown = true;
    mMousePos = ofVec2f ( x, y );
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mMouseDown = false;
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
