//
//  twinkleScene.cpp
//  OzHost
//
//  Created by Jesse Garrison on 12/31/14.
//
//

#include "twinkleScene.h"

void twinkleScene::setup(){
    bits.clear();
    int i=0;
    for (int y=BITSIZE; y< ofGetHeight(); y+=BITSIZE*2) {
        for (int x= BITSIZE; x< ofGetWidth();x+=BITSIZE*2){
            bits.push_back(TwinkleBit(x,y,i));
            i++;
        }
    }
    
    cout<<"setup twinkle"<<endl;
    
}

void twinkleScene::update(){
    for (int i=0;i<bits.size();i++){
        bits[i].update();
    }
    
}

void twinkleScene::draw(){
    ofBackground(0);
    
    for (int i=0;i<bits.size();i++){
        bits[i].draw();
    }
}

void twinkleScene::triggerPulse(int ID){
    bits[ID].trigger();
}



void TwinkleBit::update(){
    if(brightness>0){
        brightness*=0.9;
    }
    //brightness= sin(x)*255;
    //brightness=255;

}

void TwinkleBit::draw(){
    
    ofSetColor(brightness);
    ofDrawCircle(x, y, BITSIZE);
    
}

void TwinkleBit::trigger(){
    brightness = 255;
    cout<<ID<<" "<<brightness<<endl;

}
