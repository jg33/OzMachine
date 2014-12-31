#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    /* IF SERVER?
    ofxLibwebsockets::ServerOptions options = ofxLibwebsockets::defaultServerOptions();
    options.port = 6666;
    options.bUseSSL = false;
    socket.setup(options);
    socket.addListener(this);
     */
    
    ofxLibwebsockets::ClientOptions options = ofxLibwebsockets::defaultClientOptions();
    options.port = 14949;
    options.bUseSSL = false;
    options.host = "localhost";
    socket.connect(options);
    socket.addListener(this);
    
    retryAfter = 100;
    
    startTime = ofGetElapsedTimeMillis();
    
    ofSetLogLevel("ofxSceneManager", OF_LOG_VERBOSE);
    sm.setup();
    twinkle = (twinkleScene*)sm.add(new twinkleScene() );
    sm.gotoScene("twinkle");

    
}

//--------------------------------------------------------------
void ofApp::update(){
    localTime = ofGetElapsedTimeMillis()-startTime;
    
    if (!socket.isConnected() && retryCounter>retryAfter) {
        socket.connect("ozcloud.takethefort.com");
        retryCounter=0;
    } else if (!socket.isConnected()){
        retryCounter++;
    }
    
    ofSetWindowTitle("ozHost | fps: " + ofToString(ofGetFrameRate()) );
    
    
    sm.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    sm.draw();
    
    //ofDrawCircle(ofGetWidth()/2 +sin(localTime*0.001)*ofGetWidth()/2, ofGetHeight()/2, 50);
}

void ofApp::onConnect(ofxLibwebsockets::Event & e){
    cout<< e.conn.getClientName()<<" connected!"<<endl;
}

void ofApp::onMessage(ofxLibwebsockets::Event & e){
    cout << "message: " << e.message <<endl;
    vector<string> msg = ofSplitString( e.message , " ");
    if (msg[0] == "/time"){
        remoteTime = ofToInt(msg[1]);
        if( abs( localTime-remoteTime ) > 10 ){
            resync(remoteTime);
        }
    } else if (msg[0] == "/trigger"){
        twinkle->triggerPulse(ofToInt(msg[1]));
    } else if (msg[0] =="/welcome"){
        socket.send("/imHost");

    }
    
}

void ofApp::onClose(ofxLibwebsockets::Event & e){
    
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key>48 && key< 58){
        int scene = key-48;
        socket.send("/setScene "+ ofToString(scene));
        
    } else{
        switch(key){
            case('r'):
                resync(remoteTime);
                break;
            case('p'):
                socket.send("/ping");
                break;
            case('t'):
                try{
                    twinkle->triggerPulse(ofRandom(0,2000));
                } catch(...){
                    
                }
            default:
                break;
                
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
