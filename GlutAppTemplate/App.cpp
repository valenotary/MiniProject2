#include "App.h"

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
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

Rect::Rect(float xLC, float yLC, float width, float height)
{

}

Rect::~Rect()
{
}

void Rect::setXLC(float xLC)
{
	this->xLC = xLC;
}

void Rect::setyLC(float yLC)
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
