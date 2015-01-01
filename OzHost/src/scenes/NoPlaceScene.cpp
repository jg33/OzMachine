//
//  NoPlaceScene.cpp
//  OzHost
//
//  Created by Jesse Garrison on 12/31/14.
//
//

#include "NoPlaceScene.h"

void NoPlaceScene::setup(){
    homes.clear();
    font.load("Bellerose.ttf", 24);
}

void NoPlaceScene::draw(){
    ofBackground(0);
    for (int i =0;i<homes.size();i++){
        homes[i].draw();
    }
}

void NoPlaceScene::addHome(string home){
    homes.push_back(Home(home, &font));
}


Home::Home(string _text){
    loc = ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    text = _text;
    
    
}

Home::Home(string _text, ofTrueTypeFont * _fontRef){
    loc = ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    text = _text;
    fontRef = _fontRef;
}

void Home::draw(){
    
    ofSetColor(255) ;
    fontRef->drawString(text, loc.x, loc.y);
    //ofDrawBitmapString(text, loc);
}