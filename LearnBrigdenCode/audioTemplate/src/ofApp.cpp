#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //settings for our DSP
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
    
    //text setup
    ofTrueTypeFont::setGlobalDpi(72);
    myFont.load("verdana.ttf", 20, true, true);
    //Basic graphic setup
    ofBackground(255);
    ofSetFrameRate(60);
    audio.assign(bufferSize, 0.0);
    
    
    //put your code below here----------------------------------

    
}

//--------------------------------------------------------------
void ofApp::update(){
        
    //uncomment these 3 lines after step 2 is complete----------
//    carrierValue = to_string(carrierFreq);
//    modFreqValue = to_string(modFreq);
//    modIndexValue = to_string(modIndex);
    
    
    //put your code below here----------------------------------
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //This is some code to draw the output of the audio to the canvas
    ofPushStyle();
        ofPushMatrix();
        ofTranslate(0,ofGetHeight()/2 );
        ofSetColor(245, 58, 135);
        ofSetLineWidth(3);
            ofBeginShape();
            for (unsigned int i = 0; i < audio.size(); i++){
                float x =  ofMap(i, 0, audio.size(), 0, ofGetWidth(), true);
                ofVertex(x, audio[i]*360.0f);
            }
            ofEndShape(false);
        ofPopMatrix();
    ofPopStyle();
    ofPushStyle();
    //text feedback for synth of screen
    ofSetColor(0);
    myFont.drawString("Carrier Frequency " + carrierValue, 20, 40);
    myFont.drawString("Modulation Frequency (Ratio) " + modFreqValue, 20, 60);
    myFont.drawString("Modulation Index " + modIndexValue, 20, 80);
    ofPopStyle();
    
}
//--------------------------------------------------------------
void ofApp::exit() {
    ofSoundStreamClose();
}
//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer & buffer){
    
    for (unsigned int i = 0; i < buffer.getNumFrames(); i++) {
        
    //put your code below here-----------------------------------
        double signal;
        
        signal = carrier.sinewave(440 + (modulator.phasor(0.5)*100));
                    
        
        //This is our audio buffer and our speakers!
        audio[i] = buffer[i*buffer.getNumChannels()    ] =  signal * 0.2;
        buffer[i*buffer.getNumChannels() + 1] =  signal * 0.2;

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

