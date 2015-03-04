#include "ofApp.h"




float ofApp::getFirstNotBlackX(  int _x , int _y ){
    int x = _x;
    int y = _y;
    color c;
    while ( (c = img.pixels[x + y * img.getWidth()]) < blackValue) {
        x++;
        if (x >= img.getWidth()) return -1;
    }
    
    return x;
}


//--------------------------------------------------------------
void ofApp::setup(){
    

    img.loadImage("test");
    
    


}

//--------------------------------------------------------------
void ofApp::update(){
    
    

    
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    while (column < img.getWidth()-1) {
       img.grabScreen(0,0,1024,768);
        sortColumn();
        column++;
        img.draw(0,0);
        
        
        
        
    }
       while (row < img.height-1) {
           img.grabScreen(0,0,1024,768);

        sortRow();
        row++;
           img.draw(0,0);

    }

    
}



void ofApp::sortRow(){
    
    int x = 0;
    int y = row;
    int xend = 0;
    
    
    
    while (xend < img.getWidth()-1) {
        
        switch(myState) {
            case '0':
                x = getFirstNotBlackX(x, y);
                xend = getNextBlackX(x, y);
                break;
            case '1':
                x = getFirstBrightX(x, y);
                xend = getNextDarkX(x, y);
                break;
            case '2':
                x = getFirstNotWhiteX(x, y);
                xend = getNextWhiteX(x, y);
                break;
            default:
                break;
        }
        
        if (x < 0) break;
        
        int sortLength = xend-x;
        
        color[] unsorted = new color[sortLength];
        color[] sorted = new color[sortLength];
        
        for (int i=0; i<sortLength; i++) {
            unsorted[i] = img.pixels[x + i + y * img.width];
        }
        
        sorted = sort(unsorted);
        
        for (int i=0; i<sortLength; i++) {
            img.pixels[x + i + y * img.width] = sorted[i];
        }
        
        x = xend+1;
    }
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
