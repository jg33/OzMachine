#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"
#include "ofxLibwebsockets.h"
#include "ofxAppUtils.h"

#include "scenes/Scenes.h"

class ofApp : public ofxApp{
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

    
        void onConnect(ofxLibwebsockets::Event & e){};
        void onOpen(ofxLibwebsockets::Event & e){};
        void onClose(ofxLibwebsockets::Event & e){};
        void onMessage(ofxLibwebsockets::Event & e){};
        void onIdle(ofxLibwebsockets::Event & e){};
        void onBroadcast(ofxLibwebsockets::Event & e){};
    
        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
    
private:
    
    ofxSceneManager manager;
    ofxLibwebsockets::Client socket;
    ofxiOSKeyboard * keyboard;

};


