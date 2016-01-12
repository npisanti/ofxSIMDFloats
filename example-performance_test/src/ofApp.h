#pragma once

#include "ofMain.h"
#include "ofxSIMDFloats.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();

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

        void calculateSIMD();
        void calculateNonAccelerated();

        float * arrayX;
        float * arrayY;
        float * arrayZ;

        int size;
        
        int timeBaddC;
        int timeBaddS;
        int timeBmulC;
        int timeBmulS;
        int timeBsubC;
        int timeBsubS;
        int timeBdivC;
        int timeSsubB;
        int timeBadd_CmulS;
        int time1divB;
        int timeabsB;
        int timenegB;
        int timesqrtB;
        int timesinB;
        int timecosB; 
        int timetanB;
        int timelogB;
        int timelogSB;
        int timeexpB;
        int timepowSB;
        int timefloorB;
        int timemaxBC;
        int timemaxBS;
        int timeminBC;
        int timeminBS;
        int timeclipB;
        int timeline;
        int timeramp;
        int timeB;
        int timeS;
        int timeZero;
        
        int timeBaddCnon;
        int timeBaddSnon;
        int timeBmulCnon;
        int timeBmulSnon;
        int timeBsubCnon;
        int timeBsubSnon;
        int timeBdivCnon;
        int timeSsubBnon;
        int timeBadd_CmulSnon;        
        int time1divBnon;
        int timeabsBnon;
        int timenegBnon;
        int timesqrtBnon;        
        int timesinBnon;
        int timecosBnon; 
        int timetanBnon;
        int timelogBnon;
        int timelogSBnon;
        int timeexpBnon;
        int timepowSBnon;
        int timefloorBnon;
        int timemaxBCnon;
        int timemaxBSnon;
        int timeminBCnon;
        int timeminBSnon;
        int timeclipBnon;
        int timelinenon;
        int timerampnon;
        int timeBnon;
        int timeSnon;
        int timeZeronon;
                
        chrono::nanoseconds nanosecs;
        chrono::time_point<chrono::high_resolution_clock> start, end;
};
