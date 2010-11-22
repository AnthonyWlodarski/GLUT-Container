/* 
 * File:   main.cpp
 * Author: Anthony Wlodarski, oneofthosed3afmutes@yahoo.com
 *
 * This file is the main container to get a OpenGL based window up and running.
 * Please visit http://www.opengl.org/documentation/red_book/ for more information
 * in regards to the OpenGL API.
 * 
 * The MIT License
 *
 * Copyright (c) 2010 Anthony Wlodarski, oneofthosed3afmutes@yahoo.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER

 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * Created on November 22, 2010, 9:09 AM
 */

#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>
using namespace std;

// Our initialization function that takes care of setting OpenGL state options
// upon creation
void init(void);

// A simple display function please put all your rendering code in this function
void display(void);

// A simple reshape function to handle reshaping of the window
void reshape(int, int);

// A function to handle keyboard input
void keyboard(unsigned char, int, int);

// A function to handle mouse input
void mouse(int, int, int, int);

/*
 * The driver of the application.
 */
int main(int argc, char** argv) {
    // Initialize the glut library with any command line arguments
    glutInit(&argc, argv);
    // Initialize the display mode, please read the doctumentation for more flags to set
    // remember OpenGL is a giant state machine!
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // set the window size
    glutInitWindowSize(250,250);
    // set the window position
    glutInitWindowPosition(100,100);
    // with this call we will create a window, but please remember that the window will
    // not be displayed till the main loop has been called.
    glutCreateWindow("FREEGLUT Container");
    // Call our own initialization functionw which sets options in the state engine
    init();
    // register our display function with glut
    glutDisplayFunc(display);
    // register our window reshape function
    glutReshapeFunc(reshape);
    // register our keyboard handler
    glutKeyboardFunc(keyboard);
    // register our mouse function
    glutMouseFunc(mouse);
    // Call the glut main loop function
    glutMainLoop();
    return 0;
}


// Our initialization function that takes care of setting OpenGL state options
// upon creation
void init(void) {
    // set the clear color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // setup some basic viewing rules
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

// A simple display function please put all your rendering code in this function
void display(void) {
    // clear the bit plane that contains the pixels to be drawn
    glClear(GL_COLOR_BUFFER_BIT);
    // set the color that the next object should be drawn in
    glColor3f(1.0, 1.0, 1.0);
    // begin a polygon drawing chain
    glBegin(GL_POLYGON);
        glVertex3f(0.25, 0.25, 0.0);
        glVertex3f(0.75, 0.25, 0.0);
        glVertex3f(0.75, 0.75, 0.0);
        glVertex3f(0.25, 0.75, 0.0);
    glEnd();
    // force the buffered routines in OpenGL to start
    glFlush();
}

// A simple reshape function to handle reshaping of the window
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

// A function to handle keyboard input
void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        // ascii key code for escape key on keyboard
        case 27 :
            exit(0);
        break;
        default: break;
    }
}

// A function to handle mouse input
void mouse(int button, int state, int x, int y) {
    
}