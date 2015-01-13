#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    socket.connect("192.168.1.70", 6666);
    socket.addListener(this);
    
    keyboard = new ofxiOSKeyboard(2,500,320,32);
    keyboard->setBgColor(255, 255, 255, 255);
    keyboard->setFontColor(0,0,0, 255);
    keyboard->setFontSize(26);
    keyboard->setPosition(40, 200);
    
    setSceneManager(&manager);
}

//--------------------------------------------------------------
void ofApp::update(){
    keyboard->setVisible(true);

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 255);
    ofDrawBitmapString("tap the textfield to open the keyboard", 2, 35);
    
    ofSetColor(20, 160, 240, 255);
    ofDrawBitmapString("text entered = "+  keyboard->getText() , 2, 100);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
    socket.send("butts");
}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}

