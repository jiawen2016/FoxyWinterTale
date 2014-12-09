#include "ofApp.h"
#include <string>
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
    mFullscreen = false;
    mMouseDown = false;
    ofSetVerticalSync ( true );
    ofBackground ( 0,0,0 );
    mTextureImage.loadImage("8.png");
    mTextureImage2.loadImage("26.png");
    mParticleController = new ParticleController ( mTextureImage.getTextureReference(), ofVec2f ( ofGetWidth()-100, ofGetHeight() - 20 ), 3, 20.0, 20.0,90, 60 );
    mParticleController2 = new ParticleController ( mTextureImage2.getTextureReference(), ofVec2f ( ofGetWidth()-100, ofGetHeight() - 20 ), 2, 30.0, 50.0,90, 60 );

    ofSetFrameRate ( 30.0 );
    ofSetWindowTitle("FoxyTale");
    bg.loadImage("WinterMoon.jpg");
    bg.resize(ofGetWindowWidth(),ofGetWindowHeight());
    foxy.setImg("foxy.png");
    g=9.81f;
    a=g;
    ground=ofGetWindowHeight()*0.8f;
    foxy.setPos(0.0, ground);
    vYo=pow((ofGetHeight()*0.2*2*g), 0.5);
    vXo=ofGetWindowWidth()/2850.0;
    vy=vYo;
    x_speed = ofGetWindowWidth()/170.3;
    /*
    tracks.push_back(piano);
    tracks.push_back(strings);
    tracks.push_back(percussion);
    tracks.push_back(guitar);
     */
    drum.loadSound("jinglebell.mp3");
    accompany.loadSound("rhythm.mp3");
    //drum.play();
    
    drum.setVolume(1.f);
    Track m;
  //Sina Dec 6 2014////////
    x_space = 0.1065f;
    
    for (int i=0;i<pitch_num;i++){
        tracks.push_back(m);
    }
    
    dist[0] = 0.f;
    for (int i=1;i<tracks.size() + 1;i++) {
        dist[i]= dist[i-1] + rymth[i-1];
    }
    
    for (int i=0;i<tracks.size();i++) {
        tracks[i].setPos((ofGetWindowWidth()*x_space)*(dist[i]), ofGetWindowHeight()*0.98-ofGetWindowHeight()*0.98*(1.f/8.f)*pitchs[i]);
            std::stringstream ss;
            ss <<pitchs[i]<<".png";
            tracks[i].setImg(ss.str(),pitchs[i]);
            if(pitchs[i]==0)
                tracks[i].y=-1000;
            else if(pitchs[i]==9)
                tracks[i].y=0.f;
        
    }
    //Sina Dec 6 2014////////
    g_time2=0;

}

//--------------------------------------------------------------
void ofApp::update(){
    if(started){
        accompany.play();
        drum.play();
        started=false;
    }
    if(!startedMoving)
        return;
    
    if (snow)
    {
        mParticleController->mPosition = mSnowPos;
        cout<<"Where are my snow?"<<endl;
        mParticleController->update ();
    }
    if (gifts)
    {
        mParticleController2->mPosition = mGiftPos;
        cout<<"Where are my gifts?"<<endl;
        mParticleController2->update ();
      
    }
    
    
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
    
    
    if(foxy.rotate){
        foxy.img.rotate90(1);
        foxy.rotated=true;
    }
    
    if(foxy.x >= ofGetWindowWidth()-foxy.w)
    {
        foxy.x = ofGetWindowWidth()-foxy.w;
    }
    if(foxy.y > ground)
    {
        foxy.y = ground;
    }
    if(foxy.y <= 0)
    {
        foxy.y = 0;
    }
   
    for (int i=0;i<tracks.size();i++) {
      
        tracks[i].x = tracks[i].x - x_speed;
        
        if(tracks[i].step>0&&tracks[i].step<9){
            if(tracks[i].x<foxy.x-50&&tracks[i].y>-1000&&tracks[i].ifMiss){
                miss++;
                tracks[i].ifMiss=false;
            }
           
            if(foxy.x<=tracks[i].x+tracks[i].w + 50 &&foxy.x>=tracks[i].x+tracks[i].w && tracks[i].flag == false)
                drum.setVolume(0.f);
    
        
            if(abs(foxy.x + foxy.w/2- tracks[i].x - tracks[i].w/2) < 50 && abs(foxy.y + foxy.h/2- tracks[i].y - tracks[i].h/2) < 50 ) {
            
                if((tracks[i].step==1&&foxy.rotated)||(tracks[i].step==2&&foxy.rocked)||tracks[i].step>2){
            
                        if(tracks[i].step==8){
                            snow=true;
                            mSnowPos = ofVec2f (tracks[i].x,0);
                        }
               

                        tracks[i].y = -1000;
                        tracks[i].flag = 1;
                        drum.setVolume(1.0);
                        success++;
                }
            }
        
        }
        if(tracks[i].step==9){
            mGiftPos = ofVec2f (tracks[i].x,tracks[i].y+tracks[i].h-10);
            if(foxy.x>=tracks[i].x&&foxy.x<=tracks[i].x+foxy.w){
                gifts=true;
                snow=false;
            }
        }
    }
    
    foxy.rotated=false;
    foxy.rocked=false;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    bg.draw(0,0);
    for (int i=0;i<tracks.size();i++) {
        tracks[i].draw();
    }
    foxy.draw();
    if(snow)
        mParticleController->draw ();
    if(gifts)
        mParticleController2->draw ();
    score=success*10-miss*5;
    ofSetColor ( 0xffffff);
    ofDrawBitmapString ( "Number of Misses: " + ofToString (miss), 10, 20 );
    ofDrawBitmapString ( "Number of Successes: " + ofToString (success), 10, 30 );
    //ofDrawBitmapString ( "Score: "+ ofToString(score),10,20);
    ofSetColor ( 0x0080FF );
    
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==OF_KEY_UP){
        foxy.jump=true;
        a-=10.0f;
        pressed++;
        
    }
    if(key==OF_KEY_RIGHT){
        if(!foxy.moveLeft&&foxy.moveRight){
            foxy.img.mirror(false, true);
            foxy.moveLeft=true;
            foxy.moveRight=false;
            foxy.rocked=true;
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
              started=true;
              startedMoving=true;
              break;
               }

    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key==OF_KEY_UP){
        a=g;
        pressed=0;
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
     //mMousePos = ofVec2f ( x, y );
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
     //mMousePos = ofVec2f ( x, y );
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //mMouseDown = true;
    //mMousePos = ofVec2f ( x, y );
    started=true;
    startedMoving=true;
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    //mMouseDown = false;
    
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
