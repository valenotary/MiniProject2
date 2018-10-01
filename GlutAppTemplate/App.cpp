#include "App.h"
#include <vector>

using namespace std;

// Create the rectangle objects, rectangle pointers, and then the vector of rectangle pointers
Rect rect1(0.0, 0.4, 0.15, 0.25);
Rect rect2(0.25, -0.25, 0.25, 0.25);
Rect rect3(-0.15, -0.25, 0.3, 0.4);

Rect* foo = &rect1;
Rect* bar = &rect2;
Rect* gnu = &rect3;

vector<Rect *> rects;


float re = 1.0;
float gb = 0.0;
float bb = 1.0;

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
	my = 0.0;
	/*
	

	Rect * foo = &rect1;
	Rect * bar = &rect2;
	Rect * gnu = &rect3;

	std::vector<Rect *> rects;

	rects.push_back(foo);
	rects.push_back(bar);
	rects.push_back(gnu);*/


	//initialize the rectangular pointer list
	rects.push_back(foo);
	rects.push_back(bar);
	rects.push_back(gnu);
}

void App::draw() {

	
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Set Color
    glColor3d(1.0, 1.0, 1.0);
    
    // Draw some points
    glBegin(GL_POINTS);
    
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    
    glEnd();
    
    // Draw a yellow cross
    glColor3d(1.0, 1.0, 0.0);
    
    glBegin(GL_LINES);
    
    glVertex2f(mx - 0.05f, my);
    glVertex2f(mx + 0.05f, my);
    
    glVertex2f(mx, my - 0.05f);
    glVertex2f(mx, my + 0.05f);

    glEnd();

	//draw the rectangles from the list of rect pointers
	for (int i = 0; i < rects.size(); i++) {
		rects[i]->draw1();
	}
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    // Redraw the scene

	//checks through each rectangle inside the list of pointers; if a certain rectangle
	//in the ith position contains the mouse pointer, it changes the r value of that rectangle to 0
	for (int i = 0; i < rects.size(); i++) {
		if (rects[i]->contains(mx, my)) {
			rects[i]->r = 0.0;
		}
		else {
			rects[i]->r = 1.0;
		}
	}

	
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
	
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}


//The Rectangle constructor; stores the left corner x-y coordinates, width, height, and values that control its color.
Rect::Rect(float xLC, float yLC, float width, float height)
{

	setXLC(xLC);
	setYLC(yLC);
	setWidth(width);
	setHeight(height);

	r = re;
	g = gb;
	b = bb;

}


//this destructor will destroy the pointers, freeing up memory in the heap after the program is finished. You have to manually loop through each 
//element using a for loop because you cant delete an entire vector with one delete keyword
Rect::~Rect()
{
	for (int i = 0; i < rects.size(); i++) {
		delete rects[i];
	}
}

//simple get-set methods; the set methods set the respective variable's value, and the get method returns it for another method's usage

void Rect::setXLC(float xLC)
{
	this->xLC = xLC;
}

void Rect::setYLC(float yLC)
{
	this->yLC = yLC;
}

void Rect::setWidth(float width)
{
	this->width = width;
}

void Rect::setHeight(float height)
{
	this->height = height;
}

float Rect::getXLC()
{
	return xLC;
}

float Rect::getYLC()
{
	return yLC;
}

float Rect::getWidth()
{
	return width;
}

float Rect::getHeight()
{
	return width;
}

void Rect::draw1()
{
	// sets how to draw each rectangle, but by itself, doesnt show the rectangle visually
	//this is handled in the App::Draw() method; this draw1() method is called above to show each rectangle
	glColor3d(r, g, b);

	glBegin(GL_POLYGON);

	glVertex2d(xLC, yLC);
	glVertex2d(xLC, yLC - height);
	glVertex2d(xLC + width, yLC - height);
	glVertex2d(xLC + width, yLC);

	glEnd();

}

//this method checks to see if the mouse pointer (mx and my) is inside a specific rectangle
bool Rect::contains(float x, float y)
{
	return (((x >= getXLC()) && (x <= (getXLC() + width))) && ((y <= getYLC()) && (y >= (getYLC() - height))));
}
