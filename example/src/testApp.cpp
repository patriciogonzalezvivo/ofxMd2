#include "testApp.h"

void testApp::setup(){
	ofSetWindowTitle( "MD2 Viewer" );
	glClearColor( 0.0, 0.0, 0.0, 0.0 );// color used to clear the window
	glShadeModel( GL_SMOOTH );// smoothing polygons
	glEnable( GL_DEPTH_TEST );// enable depth test
	glEnable( GL_TEXTURE_2D );// enable texture mapping
	glDisable( GL_LIGHTING );// opengl lighting initialization
	
	glEnable( GL_LIGHT0 );
	float lightpos[]	= { 10.0, 10.0, 100.0 };
	float lightcolor[]	= { 1.0, 1.0, 1.0, 1.0 };
	glLightfv( GL_LIGHT0, GL_POSITION, lightpos );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, lightcolor );
	glLightfv( GL_LIGHT0, GL_SPECULAR, lightcolor );
	glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, 30.f);
	
	ofSetVerticalSync(true);
	
	frog.loadModel("obj1.md2", "obj1.tga", 180, 23);
	paper.loadModel("obj2.md2", "obj2.tga", 180, 23);
	
	angle=0.0;
	yTraslate=0.0;

	light=true;
	texture=true;
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(50,50,50);
	
	// 2D
	glPushMatrix();
	glDisable( GL_DEPTH_TEST ); // On 2D and paint
	glTranslatef( 0.0, 0.0, 0.0 );
	
		// see velocity
		ofSetColor(0xffffff);
		ofDrawBitmapString("FrameRate: "+ofToString(ofGetFrameRate(), 0), 10,18);

	glEnable( GL_DEPTH_TEST ); // On 3D and paint
	glPopMatrix();
			
	// 3D
	glPushMatrix();
	glLoadIdentity();
	
	// Variables para el visor, para girar el objeto
	if( angle < 0.0 ) angle += 360.0;
	if( angle > 360.0 )	angle -= 360.0;
	
	if( angle2 < 0.0 ) angle2 += 360.0;
	if( angle2 > 360.0 ) angle2 -= 360.0;
	
	//cambio del angulo de la luz
	if( frog.g_angle > 360.0 ) frog.g_angle -= 360.0;
	if( frog.g_angle < 0.0 ) frog.g_angle += 360.0;
	
	if( paper.g_angle > 360.0 ) paper.g_angle -= 360.0;
	if( paper.g_angle < 0.0 ) paper.g_angle += 360.0;
	
	glTranslatef (0.0f, yTraslate, -120.0f);
	glRotatef( angle, 0.0, 1.0, 0.0 );
	glRotatef( angle2, 1.0, 0.0, 0.0 );
	
	frog.draw();
	paper.draw();
	
	glPopMatrix();
	
}



//--------------------------------------------------------------
void testApp::keyPressed  (int key){

	switch (key){
		case 'l': //light?
			if (light) glDisable( GL_LIGHTING );
			else glEnable( GL_LIGHTING );
			light = !light;

			break;
		case 'p': //only points?
			glPolygonMode( GL_FRONT_AND_BACK, GL_POINT );
			break;
		
		case 'n': //standar?
			glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
			break;

		case 'w': //wireframe?
			glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
			break;
		
		case 't': //not texture?
			if (texture) glDisable( GL_TEXTURE_2D );
			else glEnable( GL_TEXTURE_2D );
			texture = !texture;
			break;

		case 's': //size -?
			yTraslate=yTraslate - 0.8;
			scale=scale+4;
			frog.scaleModel( scale );
			paper.scaleModel( scale );
			break;

		case 'd': //size +?
			yTraslate=yTraslate + 0.8;
			scale=scale-4;
			frog.scaleModel( scale );
			paper.scaleModel( scale );
		break;

		case OF_KEY_RIGHT: //rotate?
			angle += 5.0;
			break;

		case OF_KEY_LEFT: //rotate 2?
			angle2 += 5.0;
			break;
			
		case OF_KEY_UP: //rotate light?
			frog.g_angle += 10.0;
			paper.g_angle += 10.0;
			break;
			
		case '0': frog.setAnim(0); paper.setAnim(0); break;
		case '1': frog.setAnim(1); paper.setAnim(1); break;
		case '2': frog.setAnim(2); paper.setAnim(2); break;
		case '3': frog.setAnim(3); paper.setAnim(3); break;
		case '4': frog.setAnim(4); paper.setAnim(4); break;
		case '5': frog.setAnim(5); paper.setAnim(5); break;
		case '6': frog.setAnim(6); paper.setAnim(6); break;
		case '7': frog.setAnim(7); paper.setAnim(7); break;
		case '8': frog.setAnim(8); paper.setAnim(8); break;
		case '9': frog.setAnim(9); paper.setAnim(9); break;
	}

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void testApp::exit(){
}