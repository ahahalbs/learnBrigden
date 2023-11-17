#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    
    sampleRate = 44100;
    bufferSize = 512;
    
    // settings for ofxMaxim.
    maxiSettings::setup(sampleRate, 2, bufferSize);
    
    //sets up the soundStream object with default devices
    auto devices = soundStream.getMatchingDevices("default");
    //you can also list input/output devices with soundStream.printDeviceList()
    soundSettings.setOutListener(this);
    soundSettings.sampleRate = sampleRate;
    soundSettings.numOutputChannels = 2;
    soundSettings.numInputChannels = 0;
    soundSettings.bufferSize = bufferSize;
    soundStream.setup(soundSettings);

}

//--------------------------------------------------------------
void ofApp::update(){
harmonicity = ofMap(mouseX, 0, ofGetWidth(), 0, 12);
    //carrierFreq = 130.810;
    //carrierFreq = ofMap(mouseY,0,ofGetHeight(),130.810, 760);
    modulationFreq = ofMap(mouseY, 0, ofGetHeight(),36,4400, true);
}

//--------------------------------------------------------------
void ofApp::draw(){

}
//--------------------------------------------------------------
void ofApp::exit() {
    ofSoundStreamClose();
}
//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer & buffer){
    
    for (unsigned int i = 0; i < buffer.getNumFrames(); i++) {
        double wave;
        double amplitudeFollower;
        
        
        //our sound has a sharp attack that fades away
        amplitudeFollower =amp.phasor(1,36, 440);
        
        //wave = carrier.sinewave(carrierFreq + modulation.sinewave(carrierFreq*harmonicity)*(modIndex.sinewave(amplitudeFollower)*390));
        wave = carrier.triangle(130 *modulation.saw(modulationFreq)* amplitudeFollower);
        
        buffer[i*buffer.getNumChannels()    ]= wave * 0.01;
        buffer[i*buffer.getNumChannels() + 1]= wave * 0.01;

    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


    
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
