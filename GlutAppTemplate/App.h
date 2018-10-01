#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
public:
    // Constructor, to initialize state

    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
};

class Rect {

	// x - y coordinates of left hand corner 
	float xLC;
	float yLC;

	//mouse stuff
	float mx, my;

	// width and height
	float width;
	float height;

	//color tracker 
	float r;
	float g;
	float b;

public: 

	Rect(float xLC, float yLC, float width, float height);
	~Rect();

	void setXLC(float xLC);
	void setYLC(float yLC);
	void setWidth(float width);
	void setHeight(float height);

	float getXLC();
	float getYLC();
	float getWidth();
	float getHeight();

	void draw();
	void keyPress(unsigned char key);
	void mouseDown(float x, float y);
	void mouseDrag(float x, float y);

	bool contains(float x, float y);

};

#endif
