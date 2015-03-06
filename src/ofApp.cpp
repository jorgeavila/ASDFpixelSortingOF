#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    

	img.loadImage(ofToDataPath("bigHead.jpg"));
	ofSetWindowShape(img.getWidth(), img.getHeight());
	width = img.getWidth(); height = img.getHeight();
	img.draw(0,0);
	
	mode = 1;
	blackValue = -16000000;
	brigthnessValue = 60;
	whiteValue = -13000000;
	loops  = 1;
	row = 0;
	column = 0;
	saved = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    

    
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
	
    while (column < img.getWidth()-1) {
        sortColumn();
        column++;
        img.update();
        
        
        
        
    }
       while (row < img.getHeight()-1) {
        sortRow();
        row++;
		   img.update();

    }

	img.draw(0,0);
	if(!saved && ofGetFrameNum() >= loops) {
		//ofSaveScreen(imgFileName+"_"+ofToString(mode)+".png");
		ofSaveFrame();
		saved = true;
		ofLogVerbose() << "DONE" << ofGetFrameNum();
		exit();
	}
}



void ofApp::sortRow(){
    
    int x = 0;
    int y = row;
    int xend = 0;
    
    
    
    while (xend < img.getWidth()-1) {
        
        switch(mode) {
            case 0:
                x = getFirstNotBlackX(x, y);
                xend = getNextBlackX(x, y);
                break;
            case 1:
                x = getFirstBrightX(x, y);
                xend = getNextDarkX(x, y);
                break;
            case 2:
                x = getFirstNotWhiteX(x, y);
                xend = getNextWhiteX(x, y);
                break;
            default:
                break;
        }
        
        if (x < 0) break;
        
        int sortLength = xend-x;
		if(sortLength < 1) break;
		vector<int> unsorted(sortLength);
		vector<int> sorted(sortLength);
		
        for (int i=0; i<sortLength; i++) {
			unsorted[i] = img.getColor(x+i, y).getHex();
        }
        
        ofSort<int>(unsorted);
        
        for (int i=0; i<sortLength; i++) {
			ofColor c;
			c.setHex(unsorted[i]);
            img.setColor(x+i, y, c);
        }
        
        x = xend+1;
    }
}

void ofApp::sortColumn() {
	int x = column;
	int y = 0;
	int yend = 0;
	
	while(yend < img.getHeight()-1) {
		switch(mode) {
			case 0:
				y = getFirstNotBlackY(x, y);
				yend = getNextBlackY(x, y);
				break;
			case 1:
				y = getFirstBrightY(x, y);
				yend = getNextDarkY(x, y);
				break;
			case 2:
				y = getFirstNotWhiteY(x, y);
				yend = getNextWhiteY(x, y);
				break;
			default:
				break;
		}
		
		if(y < 0) break;
		
		int sortLength = yend-y;
		if(sortLength < 1) break;
		vector<int> unsorted(sortLength);
		
		for (int i=0; i<sortLength; i++) {
			unsorted[i] = img.getColor(x, y+i).getHex();
		}
		
		ofSort<int>(unsorted);
		
		for (int i=0; i<sortLength; i++) {
			ofColor c;
			c.setHex(unsorted[i]);
			img.setColor(x, y+i, c);
		}
		
		y = yend+1;
	}
}
//BLACK
int ofApp::getFirstNotBlackX(int _x, int _y) {
	int x = _x;
	int y = _y;
	while((img.getColor(x,y).getHex()|0xff000000) < blackValue) {
		x++;
		if(x >= width) return -1;
	}
	return x;
}

int ofApp::getNextBlackX(int _x, int _y) {
	int x = _x+1;
	int y = _y;
	while((img.getColor(x,y).getHex()|0xff000000) > blackValue) {
		x++;
		if(x >= width) return width-1;
	}
	return x-1;
}

int ofApp::getFirstBrightX(int _x, int _y) {
	int x = _x;
	int y = _y;
	while(img.getColor(x,y).getBrightness() < brigthnessValue) {
		x++;
		if(x >= width) return -1;
	}
	return x;
}

int ofApp::getNextDarkX(int _x, int _y) {
	int x = _x+1;
	int y = _y;
	while(img.getColor(x,y).getBrightness() > brigthnessValue) {
		x++;
		if(x >= width) return width-1;
	}
	return x-1;
}

//WHITE
int ofApp::getFirstNotWhiteX(int _x, int _y) {
	int x = _x;
	int y = _y;
	while((img.getColor(x,y).getHex()|0xff000000) > whiteValue) {
		x++;
		if(x >= width) return -1;
	}
	return x;
}

int ofApp::getNextWhiteX(int _x, int _y) {
	int x = _x+1;
	int y = _y;
	while((img.getColor(x,y).getHex()|0xff000000) < whiteValue) {
		x++;
		if(x >= width) return width-1;
	}
	return x-1;
}


//BLACK
int ofApp::getFirstNotBlackY(int _x, int _y) {
	int x = _x;
	int y = _y;
	if(y < height) {
		while((img.getColor(x,y).getHex()|0xff000000) < blackValue) {
			y++;
			if(y >= height) return -1;
		}
	}
	return y;
}

int ofApp::getNextBlackY(int _x, int _y) {
	int x = _x;
	int y = _y+1;
	if(y < height) {
		while((img.getColor(x,y).getHex()|0xff000000) > blackValue) {
			y++;
			if(y >= height) return height-1;
		}
	}
	return y-1;
}

//BRIGHTNESS
int ofApp::getFirstBrightY(int _x, int _y) {
	int x = _x;
	int y = _y;
	if(y < height) {
		while(img.getColor(x,y).getBrightness() < brigthnessValue) {
			y++;
			if(y >= height) return -1;
		}
	}
	return y;
}

int ofApp::getNextDarkY(int _x, int _y) {
	int x = _x;
	int y = _y+1;
	if(y < height) {
		while(img.getColor(x,y).getBrightness() > brigthnessValue) {
			y++;
			if(y >= height) return height-1;
		}
	}
	return y-1;
}

//WHITE
int ofApp::getFirstNotWhiteY(int _x, int _y) {
	int x = _x;
	int y = _y;
	if(y < height) {
		while((img.getColor(x,y).getHex()|0xff000000) > whiteValue) {
			y++;
			if(y >= height) return -1;
		}
	}
	return y;
}

int ofApp::getNextWhiteY(int _x, int _y) {
	int x = _x;
	int y = _y+1;
	if(y < height) {
		while((img.getColor(x,y).getHex()|0xff000000) < whiteValue) {
			y++;
			if(y >= height) return height-1;
		}
	}
	return y-1;
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
