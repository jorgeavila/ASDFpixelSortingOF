#pragma once

#include "ofMain.h"

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void sortColumn();
    void sortRow();
	int getFirstNotBlackX(int _x, int _y);
	int getNextBlackX(int _x, int _y);
	int getFirstBrightX(int _x, int _y);
	int getNextDarkX(int _x, int _y);
	int getFirstNotWhiteX(int _x, int _y);
	int getNextWhiteX(int _x, int _y);
	int getFirstNotBlackY(int _x, int _y);
	int getNextBlackY(int _x, int _y);
	int getFirstBrightY(int _x, int _y);
	int getNextDarkY(int _x, int _y);
	int getFirstNotWhiteY(int _x, int _y);
	int getNextWhiteY(int _x, int _y);
	
	
    ofImage img;
	//string imgFileName = "PIA15635";
	//string fileType = "png";

    int loops;
	int blackValue;
    int brigthnessValue;
    int whiteValue;
    
    int  row;
    int column;
    
    bool saved;

    int mode;
	int width, height;
		
};
