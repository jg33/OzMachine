//
//  NoPlaceScene.h
//  OzHost
//
//  Created by Jesse Garrison on 12/31/14.
//
//

#ifndef __OzHost__NoPlaceScene__
#define __OzHost__NoPlaceScene__

#include <stdio.h>
#include "ofxAppUtils.h"
#include "ofMain.h"

class Home;

class NoPlaceScene: public ofxScene{
    
public:
    NoPlaceScene():ofxScene("NoPlace"){setup();};
    void setup();
    void update(){};
    void draw();
    
    void addHome(string home);
    
private:
    
    vector<Home> homes;
    ofTrueTypeFont font;
    
};

class Home{
public:
    Home(string _text);
    Home(string _text, ofTrueTypeFont * _fontRef);
    
    void draw();
private:
    string text;
    ofPoint loc;
    ofTrueTypeFont * fontRef;
    
};

#endif /* defined(__OzHost__NoPlaceScene__) */
