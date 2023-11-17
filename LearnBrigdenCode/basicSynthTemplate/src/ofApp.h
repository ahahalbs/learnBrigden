#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		// Audio output
        void audioOut(ofSoundBuffer & buffer);
        //turn off our soundstream when app closes
        void exit();
    
        ofSoundStreamSettings soundSettings;
        ofSoundStream soundStream;
    
        //SampleRate: how many cycles per second is captured
        //bufferSize: how much time the computer is given to process our audio
        int sampleRate, bufferSize;
    
        float carrierFreq;
        float modulationFreq;
    
        float harmonicity;
        maxiOsc carrier, modulation, modIndex,osc4, amp;
};
