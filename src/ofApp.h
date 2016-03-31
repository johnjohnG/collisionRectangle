#pragma once

#include "ofMain.h"
struct Ball {
    int x;
    int y;
    int vx;
    int vy;
};
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
    void drawArm(float x, float y1);
    void drawC(float x, float y, float r);
    double findDistance(double fromX, double fromY, double toX, double toY);
  //  bool isCollision();
    int x1, y1, cX, cY, r1, kX,kY;
    double angle;
    float nX, nY,closestX, closestY, distance1, distance2, radius;
    ofImage arm;
   ofVec2f newCircleCenter;
    ofVec2f closePoint;
    
    Ball whiteBall;
    

};
