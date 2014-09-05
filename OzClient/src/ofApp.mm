#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetOrientation(OF_ORIENTATION_90_RIGHT);//Set iOS to Orientation Landscape Right
    
    ofSetFrameRate(30);
    
    grabber.initGrabber(1280, 720, OF_PIXELS_BGRA);
    camTex.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGB);
    
    pix = new unsigned char[ (int)( grabber.getWidth() * grabber.getHeight() * 3.0) ];
    
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    
    if (grabber.isFrameNew()) {
        camTex = grabber.getTextureReference();
        //camTex.loadData(grabber.getPixels(), 1280, 720, GL_RGB);

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
        
    camTex.draw(0,0);

    ofDrawBitmapString("TEXT", ofPoint(ofGetWidth()/2, ofGetHeight()/2));
    
        

}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){

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

