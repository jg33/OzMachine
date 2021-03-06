#pragma once

#include "ofMain.h"
#include "ofxLibwebsockets.h"
#include "ofxAppUtils.h"
//#include "ofxControlPanel.h"

#include "scenes.h"

class twinkleScene;
class NoPlaceScene;

class ofApp : public ofxApp{

	public:
		void setup();
		void update();
		void draw();
    
    void onConnect(ofxLibwebsockets::Event & e);
    void onOpen(ofxLibwebsockets::Event & e){};
    void onClose(ofxLibwebsockets::Event & e);
    void onMessage(ofxLibwebsockets::Event & e);
    void onIdle(ofxLibwebsockets::Event & e){};
    void onBroadcast(ofxLibwebsockets::Event & e){};



		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void onGuiEvent(guiCallbackData & d);

    void switchScene(int scene);
    
private:
    //ofxLibwebsockets::Server socket;
    ofxLibwebsockets::Client socket;
    ofxLibwebsockets::ClientOptions options = ofxLibwebsockets::defaultClientOptions();
    
    int startTime, localTime, remoteTime;
    int retryCounter, retryAfter;
    
    //ofxControlPanel controls;
    
    void resync(int time){
        localTime = time;
        startTime = ofGetElapsedTimeMillis()-localTime;
        cout<< "synced" <<endl;
    };
    
    ofxSceneManager sm;
    twinkleScene * twinkle;
    NoPlaceScene * noPlace;
    
    vector<string> sceneNames;
    int currentScene = 0;
};
