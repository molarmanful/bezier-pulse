#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	anim = 0;
	lerp = 0;
	interval = ofGetWidth() / 100;
	time = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::drawLine(){
	for(ofVec2f &v : segments){
		int x = (v.x + .5) * interval;
		int x0 = v.x * interval;
		int x1 = (v.x + 1) * interval;
		ofVec2f l = ofVec2f(x, 0).getInterpolated(ofVec2f(x, v.y), lerp);
		path.bezierTo(x0, 0, x0, l.y, x, l.y);
		path.moveTo(l);
		path.bezierTo(x1, l.y, x1, 0, x1, 0);
		path.moveTo(x1, 0);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ptime = time;
	time = ofGetElapsedTimef();

	ofSetBackgroundColor(ofColor::black);

	path.clear();
	path.moveTo(0, 0);

	switch(anim){
		case 1:
			drawLine();

			if(lerp >= 1) anim = 2, lerp = 1;
			else lerp += .1;

			break;

		case 2:
			drawLine();

			if(lerp <= 0) anim = 0, lerp = 0;
			else lerp -= .1;

			break;

		default:
			path.lineTo(ofGetWidth(), 0);
			if(time != ptime){
				anim = 1;
				int i = 0;
				int s = ofRandom(1) > .5 ? 1 : -1;
				for(ofVec2f &v : segments){
					v.set(i, s * ofRandom(ofGetHeight() / 4));
					i++;
					s = -s;
				}
			}

			break;
	}

	path.close();

	path.setStrokeWidth(2);
	path.setStrokeColor(ofColor::white);
	path.setFilled(false);

	path.draw(0, ofGetHeight() / 2);
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
