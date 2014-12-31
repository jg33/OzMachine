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

class NoPlaceScene: public ofxScene{
    
public:
    NoPlaceScene():ofxScene("NoPlace"){};
    void setup();
    void update();
    void draw();
    
private:
    
    
};


#endif /* defined(__OzHost__NoPlaceScene__) */
