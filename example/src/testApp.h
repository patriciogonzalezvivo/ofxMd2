#include	"ofMain.h"
#include	"ofxMd2.h"

class testApp : public ofBaseApp{
public:
		//MD2
		ofxMd2	frog;
		ofxMd2	paper;
	
		//Test with keys
		float		angle;
		float		angle2;
		//int			frame;
		int			timeSpeed;
		//int			interval;
		bool		light;
		bool		texture;
		int			scale;
		float		yTraslate;
	
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
};


