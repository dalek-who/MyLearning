// CS3241Lab1.cpp : Defines the entry point for the console application.
#include <cmath>
#include <iostream>

/* Include header files depending on platform */
#ifdef _WIN32
	#include "GL\freeglut.h"
	#define M_PI 3.14159
#elif __APPLE__
	#include <OpenGL/gl.h>
	#include <GLUT/GLUT.h>
#endif

using namespace std;

float alpha = 0.0, k=1;
float tx = 0.0, ty=0.0;

void drawcircle(float x, float y, int a, int b, float length)
{
	if(a < b)
		for (int i = a; i <= b; i++)
		{
			glVertex2f(x + length * cos(i *  M_PI / 180), y + length * sin(i *  M_PI / 180));
		}
	else
		for (int i = a; i >= b; i--)
		{
			glVertex2f(x + length * cos(i *  M_PI / 180), y + length * sin(i *  M_PI / 180));
		}
}
void profile()
{
	glColor3f(0, 0, 0);
	//body
	glBegin(GL_LINE_LOOP);
		drawcircle(-4.9, 7.5, 240, 0, 3.6);
		drawcircle(0, 0, 100, 67.2, 7.6);
		glVertex2f(2.95, 7);
		drawcircle(6.0, 5.3, 150.9, -90, 3.5);
		glVertex2f(6, 1.8);
		drawcircle(0, -0.4, 20, -40, 6.4);
		glVertex2f(6, -6);
		drawcircle(4.3, -7, 30, -90, 2);
		drawcircle(-1, -33.5, 78, 102, 25);
		drawcircle(-6.3, -7, 270, 150, 2);
		glVertex2f(-7, -3.5);
		drawcircle(-3.2, -0.4, 215, 150, 5);
	glEnd();
	//right ear
	glBegin(GL_LINE_STRIP);
		drawcircle(7, 3.4, 150, 15, 2.3);
	glEnd();
	//left ear
	glBegin(GL_LINE_STRIP);
		drawcircle(-5.8, 5.94, 0, 240, 1.8);
	glEnd();
	//left hand
	glBegin(GL_LINE_LOOP);
		drawcircle(-5, -3.8, 0, 360, 0.8);
	glEnd();
	//right hand
	glBegin(GL_LINE_LOOP);
		drawcircle(3, -4.5, 0, 360, 0.8);
	glEnd();
	//nose
	glBegin(GL_LINE_STRIP);
		drawcircle(-1, 0.5, -60, -150, 0.6);
		drawcircle(-1, 0.55, -150, -60, 0.6);
		drawcircle(-1, 0.6, -60, -150, 0.6);
	glEnd();
	//left foot
	glBegin(GL_LINE_LOOP);
		drawcircle(-1, -33.5, 100, 102, 25);
		drawcircle(-6.3, -7, 270, 220, 2);
		drawcircle(-7.8, -8.8, 105, 300, 0.8);
	glEnd();
	//right foot
	glBegin(GL_LINE_LOOP);
		drawcircle(4.3, -7, -35, -80, 2);
		drawcircle(5.8, -9, -140, 60, 0.8);
	glEnd();
	//tail
	glBegin(GL_LINE_LOOP);
		drawcircle(4.3, -7, 15, -10, 2);
		drawcircle(6.3, -6.8, -100, 110, 0.6);
	glEnd();
	//mouth
	glBegin(GL_LINE_STRIP);
		drawcircle(-7.5, -3.8, 60, 110, 4);
	glEnd();
	glBegin(GL_LINE_STRIP);
		drawcircle(-6.5, -5.2, 80, 125, 4);
	glEnd();
	glBegin(GL_LINE_STRIP);
		drawcircle(4.2, -6.5, 65, 100, 5);
	glEnd();
	glBegin(GL_LINE_STRIP);
		drawcircle(3.6, -6, 50, 90, 3.5);
	glEnd();
	glBegin(GL_LINE_STRIP);
		drawcircle(-2, -1.5, 120, 270, 0.8);
		drawcircle(-1.4, -2.3, 180, 0, 0.2);
		drawcircle(-1, 0.2, 270, 300, 2.5);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glVertex2f(-1.6, -2.3);
		glVertex2f(-1.4, -3.2);
		glVertex2f(-1.2, -2.3);
	glEnd();
}
void yellow()
{
	glColor3f(1, 1, 0.85);
	//body
	glBegin(GL_POLYGON);
		drawcircle(-4.9, 7.5, 240, 0, 3.6);
		drawcircle(-4.9, 7.5, 240, 0, 3.6);
		drawcircle(0, 0, 100, 67.2, 7.6);
		glVertex2f(2.95, 7);
		glVertex2f(6, 1.8);
		drawcircle(0, -0.4, 20, -40, 6.4);
		glVertex2f(6, -6);
		glVertex2f(-7, -3.5);
		drawcircle(-3.2, -0.4, 215, 150, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(6, -6);
		drawcircle(4.3, -7, 30, -90, 2);
		drawcircle(-1, -33.5, 78, 102, 25);
		drawcircle(-6.3, -7, 270, 150, 2);
		glVertex2f(-7, -3.5);
	glEnd();
}
void orange()
{
	glColor3f(1, 0.5, 0);
	//head & left ear
	glBegin(GL_POLYGON);
		glVertex2f(-2.5, 6.8);
		drawcircle(-4.9, 7.5, 240, 0, 3.6);
		drawcircle(0, 0, 100, 67.2, 7.6);
		glVertex2f(2.95, 7);
		glVertex2f(6, 1.8);
		drawcircle(0, -0.4, 20, 0, 6.4);
		drawcircle(7.8, 11, 250, 180, 11);
	glEnd();
	//right ear
	glBegin(GL_POLYGON);
		glVertex2f(2.95, 7);
		drawcircle(6.0, 5.3, 150.9, -90, 3.5);
		glVertex2f(6, 1.8);
	glEnd();
	//right body
	glBegin(GL_POLYGON);
		glVertex2f(4.7, -4.7);
		glVertex2f(4.9, -4.5);
		glVertex2f(6, -6);
		drawcircle(4.3, -7, 30, 20, 2);
	glEnd();
	//left body
	glBegin(GL_POLYGON);
		drawcircle(-6.3, -7, 160, 150, 2);
		glVertex2f(-7, -3.5);
		glVertex2f(-6.8, -3.8);
	glEnd();
}
void pink()
{
	glColor3f(1, 0.85, 0.85);
	//left ear
	glBegin(GL_POLYGON);
		glVertex2f(-5.8 + 1.8, 5.94);
		drawcircle(-5.8, 5.94, 0, 240, 1.8);
	glEnd();
	//right ear
	glBegin(GL_POLYGON);
		drawcircle(7, 3.4, 150, 15, 2.3);
		drawcircle(6.0, 5.3, -22, -90, 3.5);
		glVertex2f(6, 1.8);
	glEnd();
	//left hand
	glBegin(GL_POLYGON);
		drawcircle(-5, -3.8, 0, 360, 0.8);
	glEnd();
	//right hand
	glBegin(GL_POLYGON);
		drawcircle(3, -4.5, 0, 360, 0.8);
	glEnd();
	//nose
	glBegin(GL_POLYGON);
		glVertex2f(-1, 0.3);
		drawcircle(-1, 0.6, -60, -150, 0.6);
	glEnd();
	//left foot
	glBegin(GL_POLYGON);
		drawcircle(-1, -33.5, 100, 102, 25);
		drawcircle(-6.3, -7, 270, 220, 2);
		drawcircle(-7.8, -8.8, 105, 300, 0.8);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1, 1, 0.85);
		drawcircle(-1, -33.5, 100, 102, 25);
		drawcircle(-6.3, -7, 270, 210, 2);
		glColor3f(1, 0.85, 0.85);
	glEnd();
	//right foot
	glBegin(GL_POLYGON);
		drawcircle(4.3, -7, -35, -80, 2);
		drawcircle(5.8, -9, -140, 60, 0.8);
	glEnd();
	//tail
	glBegin(GL_POLYGON);
		drawcircle(4.3, -7, 15, -10, 2);
		drawcircle(6.3, -6.8, -100, 110, 0.6);
	glEnd();
	//mouth
	glBegin(GL_POLYGON);
		drawcircle(-1.4, -2.3, 180, 0, 0.2);
		glVertex2f(-1.4, -3.2);
	glEnd();
}
void eye()
{
	//black part
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
		drawcircle(-4, 2, 0, 360, 1.8);
	glEnd();
	glBegin(GL_POLYGON);
		drawcircle(3, 1, 0, 360, 1.8);
	glEnd();
	//white part
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
		drawcircle(-3.6, 2.4, 0, 360, 0.9);
	glEnd();
	glBegin(GL_POLYGON);
		drawcircle(2.6, 1.4, 0, 360, 0.9);
	glEnd();
	glBegin(GL_POLYGON);
		drawcircle(-4.8, 1.2, 0, 360, 0.5);
	glEnd();
	glBegin(GL_POLYGON);
		drawcircle(3.8, 0.2, 0, 360, 0.5);
	glEnd();
	glBegin(GL_POLYGON);
		drawcircle(-5, 2.2, 0, 360, 0.3);
	glEnd();
	glBegin(GL_POLYGON);
		drawcircle(4, 1.2, 0, 360, 0.3);
	glEnd();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();

	//controls transformation
	glScalef(k, k, k);	
	glTranslatef(tx, ty, 0);	
	glRotatef(alpha, 0, 0, 1);
	
	//draw your stuff here
	glScalef(0.5f, 0.5f, 0.5f);
	yellow();
	orange();
	pink();
	eye();
	profile();

	glPopMatrix();
	glFlush ();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init(void)
{
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glShadeModel (GL_SMOOTH);
}



void keyboard (unsigned char key, int x, int y)
{
	//keys to control scaling - k
	//keys to control rotation - alpha
	//keys to control translation - tx, ty
	switch (key) {

		case 'a':
			alpha+=10;
			glutPostRedisplay();
		break;

		case 'd':
			alpha-=10;
			glutPostRedisplay();
		break;

		case 'q':
			k+=0.1;
			glutPostRedisplay();
		break;

		case 'e':
			if(k>0.1)
				k-=0.1;
			glutPostRedisplay();
		break;

		case 'z':
			tx-=0.1;
			glutPostRedisplay();
		break;

		case 'c':
			tx+=0.1;
			glutPostRedisplay();
		break;

		case 's':
			ty-=0.1;
			glutPostRedisplay();
		break;

		case 'w':
			ty+=0.1;
			glutPostRedisplay();
		break;
			
		case 27:
			exit(0);
		break;

		default:
		break;
	}
}

int main(int argc, char **argv)
{
	cout<<"CS3241 Lab 1\n\n";
	cout<<"+++++CONTROL BUTTONS+++++++\n\n";
	cout<<"Scale Up/Down: Q/E\n";
	cout<<"Rotate Clockwise/Counter-clockwise: A/D\n";
	cout<<"Move Up/Down: W/S\n";
	cout<<"Move Left/Right: Z/C\n";
	cout <<"ESC: Quit\n";

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (50, 50);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}
