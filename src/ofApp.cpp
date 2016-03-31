#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    arm.load("armPink.png");
    cX =200;
    cY = 300;
    x1=300;
    y1=300;
    radius = 80;
    

    
    whiteBall.x = cX;
    whiteBall.y = cY;
    whiteBall.vx = ofRandom(-10,10);
    whiteBall.vy = ofRandom(-10,10);
}

//--------------------------------------------------------------
void ofApp::update(){

    
    whiteBall.x = whiteBall.x + whiteBall.vx;
    whiteBall.y = whiteBall.y + whiteBall.vy;
    
    
    if (whiteBall.x<0 || whiteBall.x > ofGetWidth()) {
        whiteBall.vx = -whiteBall.vx;
    }
    
    if (whiteBall.y<0 || whiteBall.y > ofGetHeight()) {
        whiteBall.vy = -whiteBall.vy;
    }
    
    
    //find the new rotated x
    nX= cos(angle+M_PI)*(cX-(x1+arm.getWidth()/2))-sin(angle+M_PI)*(cY-y1)+x1;
    nY= sin(angle+M_PI)*(cX-(x1+arm.getWidth()/2))-cos(angle+M_PI)*(cY-y1)+y1;
    
    //find the closestX
    if(whiteBall.x<x1){
        closestX == x1;
    }else if(whiteBall.x>x1+arm.getWidth()){
        closestX == x1+arm.getWidth();
    }else{
        closestX ==whiteBall.x;
    }
    //find the closestY
    if(whiteBall.y<y1){
        closestY ==y1;
    }else if(whiteBall.y> y1+arm.getHeight()){
        closestY == y1+arm.getHeight();
    }else{
        closestY==whiteBall.y;
    }
    
    newCircleCenter.x=whiteBall.x;
    newCircleCenter.y=whiteBall.y;
    
    closePoint.set(closestX,closestY);
    distance1=newCircleCenter.distance(closePoint);
    distance2 = findDistance(nX, nY, closestX, closestY);
    if(distance1/5<radius){
        ofSetColor(255,0,0);
        ofDrawBitmapString("succeed", 800,450);
        whiteBall.vx=-whiteBall.vx;
        //whiteBall.vy = -whiteBall.vy;
    }else{
        // ofSetColor(255,0,0);
        // ofDrawBitmapString("Naaa...", 800,450);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    

   // ofEnableSmoothing();
    drawArm(x1, y1);
    ofPushStyle();
    ofSetColor(100);
    ofDrawCircle(cX, cY,radius);
    ofPopStyle();
    
    
    
    if(distance2<radius){
        ofSetColor(0,255,0);
        ofDrawBitmapString("succeed", 800,450);
    }else{
        // ofSetColor(255,0,0);
        // ofDrawBitmapString("Naaa...", 800,450);
    }
    
    //draw data on the screen
    ofPushStyle();
    ofSetColor(100);
    ofDrawBitmapString("rotating angle" + ofToString(angle+M_PI), 800,100);
    ofDrawBitmapString("new X" + ofToString(nX), 800,150);
    ofDrawBitmapString("new Y" + ofToString(nY), 800,200);
    ofDrawBitmapString("new circle: " + ofToString(newCircleCenter), 800,350);
    ofDrawBitmapString("close: " + ofToString(closePoint), 800,400);
    
    ofDrawBitmapString("distance1/3: " + ofToString(distance1/5), 800,250);
    ofDrawBitmapString("distance2" + ofToString(distance2), 800,300);
    //ofDrawBitmapString("new Y" + ofToString(nY), 800,200);
    
    ofPopStyle();
   
   
    
    ofSetColor(0, 255, 255);
    ofCircle(whiteBall.x, whiteBall.y, radius);
    
}
//-------------rect 1---

void ofApp::drawArm(float x, float y){
    
 
    angle = atan2(mouseY - y,  mouseX-x);
  ofPushMatrix();
  ofTranslate(x, y);
    arm.setAnchorPercent(1, 0.5);
    ofRotate(ofRadToDeg(angle - HALF_PI));
    arm.draw(0,0);
 ofPopMatrix();

    
}
//-------------rect 2---

/*void ofApp::drawC(float x, float y, float r){
    x2 = x;
    y2 = y;
    r1 = r;
    ofSetColor(10,200,200);
    ofDrawCircle(x2, y2, r);
}*/

//----- detect collision
//bool ofApp:: isCollision(){
    
//}
//-----find distance
double ofApp::findDistance(double fromX, double fromY, double toX, double toY){
    double a = abs(fromX - toX);
    double b = abs(fromY - toY);
    
    return sqrt((a * a) + (b * b));
}
//-----------------------------------------------------------

void ofApp::keyPressed(int key){
    
    if(key ==OF_KEY_UP){
        cY-=5;
    }
    if(key ==OF_KEY_DOWN){
        cY+=5;
    }
    if(key ==OF_KEY_LEFT){
        cX-=5;
    }
    if(key ==OF_KEY_RIGHT){
        cX+=5;
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
