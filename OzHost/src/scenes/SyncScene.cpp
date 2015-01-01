//
//  SyncScene.cpp
//  OzHost
//
//  Created by Jesse Garrison on 1/1/15.
//
//

#include "SyncScene.h"

void SyncScene::setup(){
    
}

void SyncScene::draw(){
    
     ofDrawCircle(ofGetWidth()/2 +sin(*localTime*0.001)*ofGetWidth()/2, ofGetHeight()/2, 50);
}