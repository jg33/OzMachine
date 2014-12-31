//
//  twinkleScene.h
//  OzHost
//
//  Created by Jesse Garrison on 12/31/14.
//
//

#ifndef __OzHost__twinkleScene__
#define __OzHost__twinkleScene__

#include <stdio.h>
#include "ofxAppUtils.h"

#define BITSIZE 10

class TwinkleBit;

class twinkleScene : public ofxScene{
    
public:
    twinkleScene():ofxScene("twinkle"){setup(); setSingleSetup(true);};
    void setup();
    void update();
    void draw();
    
    void triggerPulse(int ID);
    
private:
    vector<TwinkleBit> bits;
    
};


class TwinkleBit:public ofPoint{
    
public:
    TwinkleBit(){};
    TwinkleBit(int _x, int _y, int i){ set(_x,_y); ID=i;};
    void trigger();
    
    void update();
    void draw();
    
private:
    ofPoint loc;
    int ID;
    int count;
    float brightness = 0;
};



#endif /* defined(__OzHost__twinkleScene__) */
