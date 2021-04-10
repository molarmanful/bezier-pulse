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
	switch(anim){
		case 1:
			if(lerp >= 1) anim = 2;
			else lerp += .1;
			break;

		case 2:
			if(lerp <= 0) anim = 0;
			else lerp -= .1;
			break;

		default:
			if(time != ptime){
				anim = 1;
				lerp = 0;

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
}

//--------------------------------------------------------------
void ofApp::draw(){
	ptime = time;
	time = ofGetElapsedTimef();

	ofSetBackgroundColor(ofColor::black);

	path.clear();
	path.moveTo(0, 0);

	for(ofVec2f &v : segments){
		int x = (v.x + .5) * interval;
		int x0 = v.x * interval;
		int x25 = (v.x + .25) * interval;
		int x75 = (v.x + .75) * interval;
		int x1 = (v.x + 1) * interval;
		ofVec2f l = ofVec2f(x, 0).getInterpolated(ofVec2f(x, v.y), ofClamp(lerp, 0, 1));
		path.bezierTo(x0, 0, x25, l.y, x, l.y);
		path.moveTo(l);
		path.bezierTo(x75, l.y, x1, 0, x1, 0);
		path.moveTo(x1, 0);
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
