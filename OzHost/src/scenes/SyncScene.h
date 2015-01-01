//
//  SyncScene.h
//  OzHost
//
//  Created by Jesse Garrison on 1/1/15.
//
//

#ifndef __OzHost__SyncScene__
#define __OzHost__SyncScene__

#include <stdio.h>
#include "ofxAppUtils.h"

class SyncScene: public ofxScene{
    
public:
    SyncScene():ofxScene("sync"){};
    SyncScene(int * _time):ofxScene("sync"){localTime=_time;};
    
    void setup();
    void draw();
private:
    
    int * localTime;
    
};

#endif /* defined(__OzHost__SyncScene__) */
