// CS3241Lab3.cpp : Defines the entry point for the console application.
//#include <cmath>
#include "math.h"
#include <iostream>
#include <fstream>

#ifdef _WIN32
#include <Windows.h>
#include "GL\freeglut.h"
#define M_PI 3.141592654
#elif __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>
#endif

// global variable

bool m_Smooth = false;
bool m_Highlight = false;
GLfloat angle = 0;   /* in degrees */
GLfloat angle2 = 0;   /* in degrees */
GLfloat zoom = 1.5;
GLfloat field_of_view = 40.0;
GLfloat x_translation = 0.0;
GLfloat z_near = 1.0;
GLfloat z_far = 80.0;

int mouseButton = 0;
int moving, startx, starty;

#define NO_OBJECT 4;
int current_object = 0;

using namespace std;

void setupLighting()
{
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);

	// Lights, material properties
	GLfloat	ambientProperties[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat	diffuseProperties[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat	specularProperties[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat lightPosition[] = { -100.0f, 100.0f, 100.0f, 1.0f };

	glClearDepth(1.0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientProperties);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseProperties);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularProperties);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 0.0);

	// Default : lighting
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

}

float no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
float no_shininess = 0.0f;
void drawSphere(double r, float mat_ambient[], float mat_diffuse[], float mat_emission[], float mat_shininess, float mat_specular[])
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	if (m_Highlight)
	{
		// your codes for highlight here
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
	}
	else {
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialf(GL_FRONT, GL_SHININESS, no_shininess);
	}
	int i, j;
	int n = 20;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2 * n; j++)
			if (m_Smooth)
			{
				glBegin(GL_POLYGON);
				// the normal of each vertex is actaully its own coordinates normalized for a sphere
				// your normal here	
				glNormal3d(sin(i*M_PI / n)*cos(j*M_PI / n), cos(i*M_PI / n)*cos(j*M_PI / n), sin(j*M_PI / n));
				glVertex3d(r*sin(i*M_PI / n)*cos(j*M_PI / n), r*cos(i*M_PI / n)*cos(j*M_PI / n), r*sin(j*M_PI / n));
				// your normal here
				glNormal3d(sin((i + 1)*M_PI / n)*cos(j*M_PI / n), cos((i + 1)*M_PI / n)*cos(j*M_PI / n), sin(j*M_PI / n));
				glVertex3d(r*sin((i + 1)*M_PI / n)*cos(j*M_PI / n), r*cos((i + 1)*M_PI / n)*cos(j*M_PI / n), r*sin(j*M_PI / n));
				// your normal here
				glNormal3d(sin((i + 1)*M_PI / n)*cos((j + 1)*M_PI / n), cos((i + 1)*M_PI / n)*cos((j + 1)*M_PI / n), sin((j + 1)*M_PI / n));
				glVertex3d(r*sin((i + 1)*M_PI / n)*cos((j + 1)*M_PI / n), r*cos((i + 1)*M_PI / n)*cos((j + 1)*M_PI / n), r*sin((j + 1)*M_PI / n));
				// your normal here
				glNormal3d(sin(i*M_PI / n)*cos((j + 1)*M_PI / n), cos(i*M_PI / n)*cos((j + 1)*M_PI / n), sin((j + 1)*M_PI / n));
				glVertex3d(r*sin(i*M_PI / n)*cos((j + 1)*M_PI / n), r*cos(i*M_PI / n)*cos((j + 1)*M_PI / n), r*sin((j + 1)*M_PI / n));
				glEnd();
			}
			else {
				glBegin(GL_POLYGON);
				// Explanation: the normal of the whole polygon is the coordinate of the center of the polygon for a sphere
				glNormal3d(sin((i + 0.5)*M_PI / n)*cos((j + 0.5)*M_PI / n), cos((i + 0.5)*M_PI / n)*cos((j + 0.5)*M_PI / n), sin((j + 0.5)*M_PI / n));
				glVertex3d(r*sin(i*M_PI / n)*cos(j*M_PI / n), r*cos(i*M_PI / n)*cos(j*M_PI / n), r*sin(j*M_PI / n));
				glVertex3d(r*sin((i + 1)*M_PI / n)*cos(j*M_PI / n), r*cos((i + 1)*M_PI / n)*cos(j*M_PI / n), r*sin(j*M_PI / n));
				glVertex3d(r*sin((i + 1)*M_PI / n)*cos((j + 1)*M_PI / n), r*cos((i + 1)*M_PI / n)*cos((j + 1)*M_PI / n), r*sin((j + 1)*M_PI / n));
				glVertex3d(r*sin(i*M_PI / n)*cos((j + 1)*M_PI / n), r*cos(i*M_PI / n)*cos((j + 1)*M_PI / n), r*sin((j + 1)*M_PI / n));
				glEnd();
			}
	}
}
void drawCircularCone(double r, double h)
{
	float no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float mat_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	float mat_diffuse[] = { 0.8f, 0.5f, 0.2f, 1.0f };
	float mat_emission[] = { 0.3f, 0.2f, 0.2f, 0.0f };
	float no_shininess = 0.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	if (m_Highlight)
	{
		float mat_shininess = 50.0f;
		float mat_specular[] = { 0.7f, 0.7f, 0.7f, 0.5f };
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
	}
	else {
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialf(GL_FRONT, GL_SHININESS, no_shininess);
	}

	int i, j;
	int n = 20;
	int m = 15;
	double normal_h = h / sqrt(h * h + r * r);
	double normal_r = r / (2 * sqrt(h * h + r * r));
	glPushMatrix();
	glTranslatef(0, 0, -0.2*h);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2 * m; j++)
			if (m_Smooth)
			{
				glBegin(GL_POLYGON);
				// the normal of each vertex is like in a equicrural triangle to compute the normal of the bevel edge
				//this equicrural triangle, height is h, bottom margin is r, so the normal's z is h/sqrt(h^2 + r^2 / 4)
				//and sqrt(x^2 + y^2) = r / (2 * sqrt(h^2 + r^2 / 4)) more exactly it depends on theta.
				glNormal3d(normal_r * cos(j * M_PI / m), normal_r * sin(j * M_PI / m), normal_h);
				glVertex3d(r * i / n * cos(j * M_PI / m), r * i / n * sin(j * M_PI / m), h - h * i / n);
				glNormal3d(normal_r * cos(j * M_PI / m), normal_r * sin(j * M_PI / m), normal_h);
				glVertex3d(r * (i + 1) / n * cos(j * M_PI / m), r * (i + 1) / n * sin(j * M_PI / m), h - h * (i + 1) / n);
				glNormal3d(normal_r * cos((j + 1) * M_PI / m), normal_r * sin((j + 1) * M_PI / m), normal_h);
				glVertex3d(r * (i + 1) / n * cos((j + 1) * M_PI / m), r * (i + 1) / n * sin((j + 1) * M_PI / m), h - h * (i + 1) / n);
				glNormal3d(normal_r * cos((j + 1) * M_PI / m), normal_r * sin((j + 1) * M_PI / m), normal_h);
				glVertex3d(r * i / n * cos((j + 1) * M_PI / m), r * i / n * sin((j + 1) * M_PI / m), h - h * i / n);
				glEnd();
			}
			else {
				glBegin(GL_POLYGON);
				glNormal3d(normal_r * cos((j + 0.5) * M_PI / m), normal_r * sin((j + 0.5) * M_PI / m), normal_h);
				glVertex3d(r * i / n * cos(j * M_PI / m), r * i / n * sin(j * M_PI / m), h - h * i / n);
				glVertex3d(r * (i + 1) / n * cos(j * M_PI / m), r * (i + 1) / n * sin(j * M_PI / m), h - h * (i + 1) / n);
				glVertex3d(r * (i + 1) / n * cos((j + 1) * M_PI / m), r * (i + 1) / n * sin((j + 1) * M_PI / m), h - h * (i + 1) / n);
				glVertex3d(r * i / n * cos((j + 1) * M_PI / m), r * i / n * sin((j + 1) * M_PI / m), h - h * i / n);
				glEnd();
			}
	}
	glBegin(GL_POLYGON);
	glNormal3d(0.0, 0.0, -1.0);
	for (i = 0; i < 180; i++)
		glVertex3d(r * cos(i * M_PI / 90), r * sin(i * M_PI / 90), 0);
	glEnd();
	glPopMatrix();
}
void drawAtom(float second)
{
	glPushMatrix();
	float mat_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	//color for electron
	float mat_diffuse0[] = { 0.1f, 0.3f, 0.8f, 1.0f };
	//color for nucleus
	float mat_diffuse1[] = { 0.1f, 0.8f, 0.5f, 1.0f };
	float mat_diffuse2[] = { 0.8f, 0.2f, 0.2f, 1.0f };
	float mat_diffuse3[] = { 0.8f, 0.3f, 0.8f, 1.0f };
	float mat_diffuse4[] = { 0.8f, 0.5f, 0.2f, 1.0f };
	float mat_emission[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float mat_shininess = 50.0f;
	float mat_specular[] = { 0.7f, 0.7f, 0.7f, 0.5f };
	//light
	if (m_Highlight)
	{
		float mat_shininess = 50.0f;
		float mat_specular[] = { 0.7f, 0.7f, 0.7f, 0.5f };
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
	}
	else {
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialf(GL_FRONT, GL_SHININESS, no_shininess);
	}
	glScalef(0.05, 0.05, 0.05);
	glRotatef(90, 1.0, 1.0, 1.0);
	glTranslatef(0, 5 * sqrt(6) / 2.0, 0);
	drawSphere(5, mat_ambient, mat_diffuse1, mat_emission, mat_shininess, mat_specular);
	glTranslatef(5, -20.0 / sqrt(6), -5 / sqrt(3));
	drawSphere(5, mat_ambient, mat_diffuse2, mat_emission, mat_shininess, mat_specular);
	glTranslatef(-10, 0, 0);
	drawSphere(5, mat_ambient, mat_diffuse3, mat_emission, mat_shininess, mat_specular);
	glTranslatef(5, 0, 5 * sqrt(3));
	drawSphere(5, mat_ambient, mat_diffuse4, mat_emission, mat_shininess, mat_specular);
	//electron
	glTranslatef(0, 20.0 / sqrt(6) - 5 * sqrt(6) / 2.0, 5 / sqrt(3) - 5 * sqrt(3));
	second /= 300.0;
	float r, h;
	r = 23; h = 0.5;
	glTranslatef(r * cos(second), r * sin(second), 0);
	drawSphere(2, mat_ambient, mat_diffuse0, mat_emission, mat_shininess, mat_specular);
	glTranslatef(-r * cos(second), -r * sin(second) + r * cos(second + 120), r * sin(second + 120));
	drawSphere(2, mat_ambient, mat_diffuse0, mat_emission, mat_shininess, mat_specular);
	glTranslatef(-r * sin(second - 120), -r * cos(second + 120), -r * sin(second + 120) - r * cos(second - 120));
	drawSphere(2, mat_ambient, mat_diffuse0, mat_emission, mat_shininess, mat_specular);
	glTranslatef(r * sin(second - 120), 0, +r * cos(second - 120));
	for (int x = 0; x < 3; x++)
	{
		for (int i = 0; i < 360; i += 10)
			for (int j = 0; j < 360; j += 20)
			{
				//it's circle too, so, it's easy to compute my normal.
				glBegin(GL_POLYGON);
				glNormal3d(cos(i * M_PI / 180), 0, sin(i * M_PI / 180));
				glVertex3f((h * cos((j + 20) * M_PI / 180) + r) * cos(i * M_PI / 180), h * sin((j + 20) * M_PI / 180), (h * cos((j + 20) * M_PI / 180) + r) * sin(i * M_PI / 180));
				glVertex3f((h * cos(j * M_PI / 180) + r) * cos(i * M_PI / 180), h * sin(j * M_PI / 180) + 0, (h * cos(j * M_PI / 180) + r) * sin(i * M_PI / 180));
				if (m_Smooth)
					glNormal3d(cos((i + 10) * M_PI / 180), 0, sin((i + 10) * M_PI / 180));
				glVertex3f((h * cos(j * M_PI / 180) + r) * cos((i + 10) * M_PI / 180), h * sin(j * M_PI / 180), (h * cos(j * M_PI / 180) + r) * sin((i + 10) * M_PI / 180));
				glVertex3f((h * cos((j + 20) * M_PI / 180) + r) * cos((i + 10) * M_PI / 180), h * sin((j + 20) * M_PI / 180), (h * cos((j + 20) * M_PI / 180) + r) * sin((i + 10) * M_PI / 180));
				glEnd();
			}
		if (x == 1)
			glRotatef(90, 1.0, 0, 0);
		else glRotatef(90, 0, 0, 1.0);
	}
	glPopMatrix();
}
void drawCylinder(float r, float h)
{
	int i, j;
	int n = 20;
	for (i = 0; i < 2 * n; i++)
	{
		for (j = 0; j < n; j++)
			if (m_Smooth)
			{
				glBegin(GL_POLYGON);
				glNormal3d(0, sin(i*M_PI / n), cos(i*M_PI / n));
				glVertex3d(h * j / n, r*cos(i*M_PI / n), r*sin(i*M_PI / n));
				glNormal3d(0, sin((i + 1)*M_PI / n), cos((i + 1)*M_PI / n));
				glVertex3d(h * j / n, r*cos((i + 1)*M_PI / n), r*sin((i + 1)*M_PI / n));
				glVertex3d(h * (j + 1) / n, r*cos((i + 1)*M_PI / n), r*sin((i + 1)*M_PI / n));
				glNormal3d(0, sin(i*M_PI / n), cos(i*M_PI / n));
				glVertex3d(h * (j + 1) / n, r*cos(i*M_PI / n), r*sin(i*M_PI / n));
				glEnd();
			}
			else {
				glBegin(GL_POLYGON);
				glNormal3d(0, sin((i + 0.5)*M_PI / n), cos((i + 0.5)*M_PI / n));
				glVertex3d(h * j / n, r*cos(i*M_PI / n), r*sin(i*M_PI / n));
				glVertex3d(h * j / n, r*cos((i + 1)*M_PI / n), r*sin((i + 1)*M_PI / n));
				glVertex3d(h * (j + 1) / n, r*cos((i + 1)*M_PI / n), r*sin((i + 1)*M_PI / n));
				glVertex3d(h * (j + 1) / n, r*cos(i*M_PI / n), r*sin(i*M_PI / n));
				glEnd();
			}
	}
	glNormal3d(1, 0, 0);
	glBegin(GL_POLYGON);
	for (i = 0; i < 2 * n; i++)
		glVertex3d(h, r*cos(i*M_PI / n), r*sin(i*M_PI / n));
	glEnd();
	glNormal3d(-1, 0, 0);
	glBegin(GL_POLYGON);
	for (i = 0; i < 2 * n; i++)
		glVertex3d(0, r*cos(i*M_PI / n), r*sin(i*M_PI / n));
	glEnd();
}
void drawOnlySphere(float r)
{
	int i, j;
	int n = 20;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2 * n; j++)
			if (m_Smooth)
			{
				glBegin(GL_POLYGON);
				glNormal3d(sin(i*M_PI / n)*cos(j*M_PI / n), cos(i*M_PI / n)*cos(j*M_PI / n), sin(j*M_PI / n));
				glVertex3d(r*sin(i*M_PI / n)*cos(j*M_PI / n), r*cos(i*M_PI / n)*cos(j*M_PI / n), r*sin(j*M_PI / n));
				glNormal3d(sin((i + 1)*M_PI / n)*cos(j*M_PI / n), cos((i + 1)*M_PI / n)*cos(j*M_PI / n), sin(j*M_PI / n));
				glVertex3d(r*sin((i + 1)*M_PI / n)*cos(j*M_PI / n), r*cos((i + 1)*M_PI / n)*cos(j*M_PI / n), r*sin(j*M_PI / n));
				glNormal3d(sin((i + 1)*M_PI / n)*cos((j + 1)*M_PI / n), cos((i + 1)*M_PI / n)*cos((j + 1)*M_PI / n), sin((j + 1)*M_PI / n));
				glVertex3d(r*sin((i + 1)*M_PI / n)*cos((j + 1)*M_PI / n), r*cos((i + 1)*M_PI / n)*cos((j + 1)*M_PI / n), r*sin((j + 1)*M_PI / n));
				glNormal3d(sin(i*M_PI / n)*cos((j + 1)*M_PI / n), cos(i*M_PI / n)*cos((j + 1)*M_PI / n), sin((j + 1)*M_PI / n));
				glVertex3d(r*sin(i*M_PI / n)*cos((j + 1)*M_PI / n), r*cos(i*M_PI / n)*cos((j + 1)*M_PI / n), r*sin((j + 1)*M_PI / n));
				glEnd();
			}
			else {
				glBegin(GL_POLYGON);
				glNormal3d(sin((i + 0.5)*M_PI / n)*cos((j + 0.5)*M_PI / n), cos((i + 0.5)*M_PI / n)*cos((j + 0.5)*M_PI / n), sin((j + 0.5)*M_PI / n));
				glVertex3d(r*sin(i*M_PI / n)*cos(j*M_PI / n), r*cos(i*M_PI / n)*cos(j*M_PI / n), r*sin(j*M_PI / n));
				glVertex3d(r*sin((i + 1)*M_PI / n)*cos(j*M_PI / n), r*cos((i + 1)*M_PI / n)*cos(j*M_PI / n), r*sin(j*M_PI / n));
				glVertex3d(r*sin((i + 1)*M_PI / n)*cos((j + 1)*M_PI / n), r*cos((i + 1)*M_PI / n)*cos((j + 1)*M_PI / n), r*sin((j + 1)*M_PI / n));
				glVertex3d(r*sin(i*M_PI / n)*cos((j + 1)*M_PI / n), r*cos(i*M_PI / n)*cos((j + 1)*M_PI / n), r*sin((j + 1)*M_PI / n));
				glEnd();
			}
	}
}
void drawPeople(float a, float r, int second, float mat_diffuse[])
{
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	float b = 10;
	float c = 1.0;//the connection between body and leg
	int time = 2000;
	if (second % time <= time / 2)
		c = c * (second % time) / (time / 2);
	else
		c = c * (time - (second % time)) / (time / 2);
	c = (c - 0.5) * 2;
	float h = r / 2;
	//leg 1
	glPushMatrix();
	glRotatef(a - b, 0.0, 0.0, 1.0);
	glTranslatef(r * 0.95, 0, 0);
	glRotatef(2 * b + atan((sin(b * M_PI / 180) - c - 0.125) / ((1.5 - cos(b * M_PI / 180)))), 0.0, 0.0, 1.0);
	drawCylinder(r / 12, h);
	glPopMatrix();
	//leg 2
	glPushMatrix();
	glRotatef(a + b, 0.0, 0.0, 1.0);
	glTranslatef(r * 0.95, 0, 0);
	glRotatef(-2 * b - atan((sin(b * M_PI / 180) + c - 0.125) / ((1.5 - cos(b * M_PI / 180)))), 0.0, 0.0, 1.0);
	drawCylinder(r / 12, h);
	glPopMatrix();
	//body
	float l1, l2, l3;
	l1 = r / 2.2; l2 = r / 6; l3 = r / 12;
	glPushMatrix();
	glRotatef(a, 0.0, 0.0, 1.0);
	glTranslatef(r * 1.40, -c * r / 32, 0);
	//arm 1
	h = 0.78 * r;
	glPushMatrix();
	glTranslatef(0.8 * l1, l2, 0);
	glRotatef(90 + b, 0.0, 0.0, -1.0);
	drawCylinder(r / 13, h);
	glPopMatrix();
	//arm 2
	glPushMatrix();
	glTranslatef(0.8 * l1, -l2, 0);
	glRotatef(90 + b, 0.0, 0.0, 1.0);
	drawCylinder(r / 13, h);
	glPopMatrix();
	//body_continue
	glBegin(GL_POLYGON);
	glNormal3d(0, 0, 1); glVertex3d(0, l2, l3); glVertex3d(0, -l2, l3); glVertex3d(l1, -l2, l3); glVertex3d(l1, l2, l3);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3d(0, 0, -1); glVertex3d(0, l2, -l3); glVertex3d(0, -l2, -l3); glVertex3d(l1, -l2, -l3); glVertex3d(l1, l2, -l3);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3d(1, 0, 0); glVertex3d(l1, l2, -l3); glVertex3d(l1, -l2, -l3); glVertex3d(l1, -l2, l3); glVertex3d(l1, l2, l3);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3d(-1, 0, 0); glVertex3d(0, l2, -l3); glVertex3d(0, -l2, -l3); glVertex3d(0, -l2, l3); glVertex3d(0, l2, l3);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3d(0, 1, 0); glVertex3d(0, l2, -l3); glVertex3d(0, l2, l3); glVertex3d(l1, l2, l3); glVertex3d(l1, l2, -l3);
	glEnd();
	glBegin(GL_POLYGON);
	glNormal3d(0, -1, 0); glVertex3d(0, -l2, -l3); glVertex3d(0, -l2, l3); glVertex3d(l1, -l2, l3); glVertex3d(l1, -l2, -l3);
	glEnd();
	//head
	glTranslatef(l1 + 0.14 * r, 0, 0);
	drawOnlySphere(0.14 * r);
	glPopMatrix();
}
void drawTree(float r, float mat_diffuse1[], float mat_diffuse2[])
{
	glPushMatrix();
	glTranslatef(0.6 * r, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
	drawCylinder(r / 6, r);
	glTranslatef(r, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
	drawOnlySphere(r / 3);
	glPopMatrix();
}
void drawEarth(float second)
{
	//glClearColor(20 / 255.0, 40 / 255.0, 66 / 255.0, 1.0);
	float no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float mat_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float mat_diffuse[] = { 0.1f, 0.3f, 0.8f, 1.0f };
	float mat_emission[] = { 0.3f, 0.2f, 0.2f, 0.0f };
	float no_shininess = 0.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	if (m_Highlight)
	{
		float mat_shininess = 100.0f;
		float mat_specular[] = { 0.7f, 0.7f, 0.7f, 0.5f };
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
	}
	else {
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialf(GL_FRONT, GL_SHININESS, no_shininess);
	}
	float mat_diffuse9[9][4];
	mat_diffuse9[0][0] = 224 / 255.0f; mat_diffuse9[0][1] = 225 / 255.0f; mat_diffuse9[0][2] = 226 / 255.0f; mat_diffuse9[0][3] = 1.0f;
	mat_diffuse9[1][0] = 254 / 255.0f; mat_diffuse9[1][1] = 242 / 255.0f; mat_diffuse9[1][2] = 223 / 255.0f; mat_diffuse9[1][3] = 1.0f;
	mat_diffuse9[2][0] = 253 / 255.0f; mat_diffuse9[2][1] = 218 / 255.0f; mat_diffuse9[2][2] = 202 / 255.0f; mat_diffuse9[2][3] = 1.0f;
	mat_diffuse9[3][0] = 224 / 255.0f; mat_diffuse9[3][1] = 173 / 255.0f; mat_diffuse9[3][2] = 135 / 255.0f; mat_diffuse9[3][3] = 1.0f;
	mat_diffuse9[4][0] = 171 / 255.0f; mat_diffuse9[4][1] = 103 / 255.0f; mat_diffuse9[4][2] = 29 / 255.0f; mat_diffuse9[4][3] = 1.0f;
	mat_diffuse9[5][0] = 137 / 255.0f; mat_diffuse9[5][1] = 54 / 255.0f; mat_diffuse9[5][2] = 8 / 255.0f; mat_diffuse9[5][3] = 1.0f;
	mat_diffuse9[6][0] = 107 / 255.0f; mat_diffuse9[6][1] = 21 / 255.0f; mat_diffuse9[6][2] = 5 / 255.0f; mat_diffuse9[6][3] = 1.0f;
	mat_diffuse9[7][0] = 31 / 255.0f; mat_diffuse9[7][1] = 16 / 255.0f; mat_diffuse9[7][2] = 3 / 255.0f; mat_diffuse9[7][3] = 1.0f;
	mat_diffuse9[8][0] = 0 / 255.0f; mat_diffuse9[8][1] = 0 / 255.0f; mat_diffuse9[8][2] = 0 / 255.0f; mat_diffuse9[8][3] = 1.0f;
	float r = 0.8;
	for (int i = 0; i < 9; i++)
		drawPeople(i * 40, r, second, mat_diffuse9[i]);
	//the two ends are empty
	//so, draw tree =.=
	float mat_diffuse1[] = { 160 / 255.0f, 130 / 255.0f, 80 / 255.0f, 1.0f };
	float mat_diffuse2[] = { 34 / 255.0f, 139 / 255.0f, 34 / 255.0f, 1.0f };
	glPushMatrix();
	for (int i = 0; i < 6; i++)
	{
		glRotatef(45, 0.0, 1.0, 0.0);
		drawTree(r, mat_diffuse1, mat_diffuse2);
		if (i == 2)
			glRotatef(45, 0.0, 1.0, 0.0);
	}
	glRotatef(45, 0.0, 1.0, 0.0);
	glRotatef(90, 0.0, 0.0, 1.0);
	for (int i = 0; i < 6; i++)
	{
		glRotatef(45, 0.0, 1.0, 0.0);
		drawTree(r, mat_diffuse1, mat_diffuse2);
		if (i == 2)
			glRotatef(45, 0.0, 1.0, 0.0);
	}
	glPopMatrix();
	//draw earth
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	drawOnlySphere(r);
}
void display(void)
{//Add Projection tool and Camera Movement somewhere here

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(field_of_view, 1.0, z_near, z_far);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//int upVector = 1;
	gluLookAt(x_translation, 0, 5, 0, 0, 0, 0, 1, 0);

	glPushMatrix();
	glTranslatef(0, 0, -6);
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);

	glScalef(zoom, zoom, zoom);


	//get time
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	float second = sys.wHour * 3600 * 1000 + sys.wMinute * 60 * 1000 + sys.wSecond * 1000 + sys.wMilliseconds;

	float mat_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	float mat_diffuse[] = { 0.1f, 0.8f, 0.5f, 1.0f };
	float mat_emission[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float mat_shininess = 50.0f;
	float mat_specular[] = { 0.7f, 0.7f, 0.7f, 0.5f };
	switch (current_object) {
	case 0:
		drawSphere(1, mat_ambient, mat_diffuse, mat_emission, mat_shininess, mat_specular);
		break;
	case 1:
		// draw your second primitive object here
		drawCircularCone(1, 1);
		break;
	case 2:
		// draw your first composite object here
		glTranslatef(-12, -12, 12);
		for (int i = 0; i < 9; i++)
		{
			drawAtom(second);
			glTranslatef(3, 3, -3);
		}
		break;
	case 3:
		// draw your second composite object here
		drawEarth(second);
		glTranslatef(0, 20, -60);
		drawEarth(second);
		break;
	default:
		break;
	};
	glPopMatrix();
	glutSwapBuffers();
}


void resetCamera() {
	//fill in values below.
	angle = 0;
	angle2 = 0;
	zoom = 1.5;
	field_of_view = 40.0;
	x_translation = 0.0;
	z_near = 1.0;
	z_far = 80.0;
	// include resetting of gluPerspective & gluLookAt.

	/*I use idle...so it is no use here*/

	//glMatrixMode(GL_PROJECTION);
	//gluPerspective(field_of_view, 1.0, z_near, z_far);
	//glMatrixMode(GL_MODELVIEW);
	////int upVector = 1;
	//gluLookAt(x_translation, 0, 5, 0, 0, 0, 0, 1, 0);
	return;
}

void setCameraBestAngle() {
	//fill in values below
	angle = -13;
	angle2 = -29;
	zoom = 1.5;
	field_of_view = 40.0;
	x_translation = 0.0;
	z_near = 1.0;
	z_far = 80.0;
	//TIPS: Adjust gluLookAt function to change camera position

	/*I use idle...so it is no use here*/

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluPerspective(field_of_view, 1.0, z_near, z_far);
	//glMatrixMode(GL_MODELVIEW);
	//int upVector = 1;
	//gluLookAt(x_translation, 0, 5, 0, 0, 0, 0, 1, 0);
	return;
}

void keyboard(unsigned char key, int x, int y)
{//add additional commands here to change Field of View and movement
	switch (key) {
	case 'p':
	case 'P':
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	case 'w':
	case 'W':
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	case 'v':
	case 'V':
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		break;
	case 's':
	case 'S':
		m_Smooth = !m_Smooth;
		break;
	case 'h':
	case 'H':
		m_Highlight = !m_Highlight;
		break;

	case 'n':
		// -Insert code to adjust Near-
		if (z_near > 0.1)
			z_near -= 0.1;
		break;

	case 'N':
		// -Insert code to adjust Near-
		z_near += 0.1;
		break;

	case 'f':
		// -Insert code to adjust Far-
		if (z_far > 10)
			z_far -= 10.0;
		else if (z_far > 1)
			z_far -= 1.0;
		break;

	case 'F':
		// -Insert code to adjust Far-
		if (z_far > 10)
			z_far += 10.0;
		else z_far += 1.0;
		break;

	case 'o':
		// -Insert code to adjust Fovy-
		field_of_view -= 1.0;
		break;

	case 'O':
		// -Insert code to adjust Fovy-
		field_of_view += 1.0;
		break;

	case 'r':
		resetCamera();
		break;

	case 'R':
		setCameraBestAngle();
		break;

	case '1':
	case '2':
	case '3':
	case '4':
		current_object = key - '1';
		break;

	case 27:
		exit(0);
		break;

	default:
		break;
	}

	glutPostRedisplay();
}



void
mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN) {
		mouseButton = button;
		moving = 1;
		startx = x;
		starty = y;
	}
	if (state == GLUT_UP) {
		mouseButton = button;
		moving = 0;
	}
}

void motion(int x, int y)
{
	if (moving) {
		if (mouseButton == GLUT_LEFT_BUTTON)
		{
			angle = angle + (x - startx);
			angle2 = angle2 + (y - starty);
		}
		else zoom += ((y - starty)*0.01);
		startx = x;
		starty = y;
		glutPostRedisplay();
	}

}
void idle()
{
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	cout << "CS3241 Lab 3" << endl << endl;

	cout << "1-4: Draw different objects" << endl;
	cout << "S: Toggle Smooth Shading" << endl;
	cout << "H: Toggle Highlight" << endl;
	cout << "W: Draw Wireframe" << endl;
	cout << "P: Draw Polygon" << endl;
	cout << "V: Draw Vertices" << endl;
	cout << "n, N: Reduce or increase the distance of the near plane from the camera" << endl;
	cout << "f, F: Reduce or increase the distance of the far plane from the camera" << endl;
	cout << "o, O: Reduce or increase the distance of the povy plane from the camera" << endl;
	cout << "r: Reset camera to the initial parameters when the program starts" << endl;
	cout << "R: Change camera to another setting that is has the best viewing angle for your object" << endl;
	cout << "ESC: Quit" << endl << endl;


	cout << "Left mouse click and drag: rotate the object" << endl;
	cout << "Right mouse click and drag: zooming" << endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("CS3241 Assignment 3");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glMatrixMode(GL_PROJECTION);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);
	setupLighting();
	glDisable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	//REMOVE FROM THIS SECTION

	//   glMatrixMode(GL_PROJECTION);
	//   glLoadIdentity();
	//   gluPerspective( /* field of view in degree */ 40.0,
	// /* aspect ratio */ 1.0,
	//   /* Z near */ 1.0, /* Z far */ 80.0);
	//glMatrixMode(GL_MODELVIEW);
	//int upVector = 1;
	//gluLookAt(1, 1, 1, 1, 1, -1, 0, 1, 0);
	//TO THIS SECTION, after implementation of Projection and Camera movement tools
	//Hint: Transfer these functions over into void display(void), then add other variables

	glutMainLoop();

	return 0;
}