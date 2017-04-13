// CS3241Lab4.cpp : Defines the entry point for the console application.
//#include <cmath>
#include "math.h"
#include <iostream>
#include <fstream>

/* Include header files depending on platform */
#ifdef _WIN32
	#include "GL\freeglut.h"
	#define M_PI 3.14159
#elif __APPLE__
	#include <OpenGL/gl.h>
	#include <GLUT/GLUT.h>
#endif

#define MAXPTNO 1000
#define NLINESEGMENT 32
#define NOBJECTONCURVE 8

using namespace std;

// Global variables that you can use
struct Point {
	int x,y;
};
struct DoublePoint {
	double x, y;
};

// Storage of control points
int nPt = 0;
Point ptList[MAXPTNO];

// Display options
bool displayControlPoints = true;
bool displayControlLines = true;
bool displayTangentVectors = false;
bool displayObjects = false;
bool C1Continuity = false;
	
void drawRightArrow()
{
	glColor3f(0,1,0);
	glBegin(GL_LINE_STRIP);
		glVertex2f(0,0);
		glVertex2f(100,0);
		glVertex2f(95,5);
		glVertex2f(100,0);
		glVertex2f(95,-5);
	glEnd();
}
double binomial(int n, int i, double t)
{
	int j;
	double result = 1.0;
	for (j = 0; j < i; j++)
		result = result * t * (n - j) / (i - j);
	for (; j < n; j++)
		result = result * (1 - t);
	return result;
}
DoublePoint coordinate(int n, double t, int number)
{
	DoublePoint a;
	a.x = 0.0; a.y = 0.0;
	for (int k = 0; k < 4; k++)
	{
		if (k != 1)
		{
			a.x += binomial(n, k, t) * ptList[3 * number + k].x;
			a.y += binomial(n, k, t) * ptList[3 * number + k].y;
		}
	}
	if (!C1Continuity || number == 0)
	{
		a.x += binomial(n, 1, t) * ptList[3 * number + 1].x;
		a.y += binomial(n, 1, t) * ptList[3 * number + 1].y;
	}
	else
	{
		a.x += binomial(n, 1, t) * (2 * ptList[3 * number].x - ptList[3 * number - 1].x);
		a.y += binomial(n, 1, t) * (2 * ptList[3 * number].y - ptList[3 * number - 1].y);
	}
	return a;
}
double derivative(int n, int i, double t)
{
	int j;
	double result1 = 1.0, result2 = 1.0;
	double result;
	result1 *= -(n - i);
	for (j = 0; j < n - i - 1; j++)
		result1 *= (1 - t);
	for (j = 0; j < i; j++)
		result1 *= t;
	result2 *= i;
	for (j = 0; j < i - 1; j++)
		result2 *= t;
	for (j = 0; j < n - i; j++)
		result2 *= (1 - t);

	result = result1 + result2;
	for (j = 0; j < i; j++)
		result = result * (n - j) / (i - j);

	return result;
}
DoublePoint tangent(int n, double t, int number)
{
	DoublePoint a;
	a.x = 0.0; a.y = 0.0;
	for (int k = 0; k < 4; k++)
	{
		if (k != 1)
		{
			a.x += derivative(n, k, t) * ptList[3 * number + k].x;
			a.y += derivative(n, k, t) * ptList[3 * number + k].y;
		}
	}
	if (!C1Continuity || number == 0)
	{
		a.x += derivative(n, 1, t) * ptList[3 * number + 1].x;
		a.y += derivative(n, 1, t) * ptList[3 * number + 1].y;
	}
	else
	{
		a.x += derivative(n, 1, t) * (2 * ptList[3 * number].x - ptList[3 * number - 1].x);
		a.y += derivative(n, 1, t) * (2 * ptList[3 * number].y - ptList[3 * number - 1].y);
	}
	return a;
}
void Objects()
{
	//flower
	//petal
	float zoom = 1.5;
	glScaled(zoom, zoom, zoom);
	for (int i = 0; i < 5; i++)
	{
		glRotated(72, 0, 0, 1);
		glColor3f(1, 0.9, 0.9);
		glBegin(GL_POLYGON);
		for (int j = 90; j < 130; j = j + 10)
		{
			glVertex2d(6 * cos((j - 60) * M_PI / 180), 10 + 6 * sin((j - 60) * M_PI / 180));
		}
		glVertex2d(0, 13);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2d(0, 13);
		for (int j = 20; j <= 60; j = j + 10)
		{
			glVertex2d(6 * cos((90 + j) * M_PI / 180), 10 + 6 * sin((90 + j) * M_PI / 180));
		}
		glEnd();
		for (int j = 60; j < 120; j = j + 2)
		{
			glColor3f(1, 1.1 - j / 300.0, 1.1 - j / 300.0);
			glBegin(GL_POLYGON);
			glVertex2d(6 * cos((90 + j) * M_PI / 180), 10 + 6 * sin((90 + j) * M_PI / 180));
			glVertex2d(6 * cos((95 + j) * M_PI / 180), 10 + 6 * sin((95 + j) * M_PI / 180));
			glVertex2d(6 * cos((85 - j) * M_PI / 180), 10 + 6 * sin((85 - j) * M_PI / 180));
			glVertex2d(6 * cos((90 - j) * M_PI / 180), 10 + 6 * sin((90 - j) * M_PI / 180));
			glEnd();
		}
	}
	for (int j = 120; j < 300; j = j + 1)
	{
		glColor3f(1, 1.1 - j / 300.0, 1.1 - j / 300.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 5; i++)
		{
			glVertex2d((14.5 - j / 21.0) * sin((36 + i * 72) * M_PI / 180), (14.5 - j / 21.0) * cos((36 + i * 72) * M_PI / 180));
		}
		glEnd();
	}
	glColor3f(0, 0, 0);
	for (int i = 0; i < 5; i++)
	{
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j < 130; j = j + 10)
		{
			glVertex2d(6 * cos((j - 60) * M_PI / 180), 10 + 6 * sin((j - 60) * M_PI / 180));
		}
		glVertex2d(0, 13);
		for (int j = 20; j < 150; j = j + 10)
		{
			glVertex2d(6 * cos((90 + j) * M_PI / 180), 10 + 6 * sin((90 + j) * M_PI / 180));
		}
		glEnd();
		glRotated(72, 0, 0, 1);
	}
	//stamen
	for (int i = 0; i < 12; i++)
	{
		glRotated(30, 0, 0, 1);
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j < 50; j = j + 2)
		{
			glVertex2d(- 7 * cos(25 * M_PI / 180) + 7 * cos((j - 25) * M_PI / 180), 7 * sin(25 * M_PI / 180) + 7 * sin((j - 25) * M_PI / 180));
		}
		glEnd();
		glBegin(GL_POLYGON);
		for (int j = 0; j < 360; j = j + 10)
		{
			glVertex2d(0.5 * cos(j * M_PI / 180), 16 * sin(25 * M_PI / 180) + 0.5 * sin(j * M_PI / 180));
		}
		glEnd();
	}
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	if(displayControlPoints)
	{
		glPointSize(5);
		glBegin(GL_POINTS);
		for(int i=0;i<nPt; i++)
		{
			if (C1Continuity && (i % 3 == 1) && i != 1)
				glColor3f(0.7, 0.7, 0.7);
			else glColor3f(0, 0, 0);
			glVertex2d(ptList[i].x,ptList[i].y);
		}
		if (C1Continuity)
		{
			for (int i = 1; i < (nPt + 1) / 3; i++)
			{
				glColor3f(1, 0, 0);
				glVertex2d(2 * ptList[3 * i].x - ptList[3 * i - 1].x, 2 * ptList[3 * i].y - ptList[3 * i - 1].y);
			}
		}
		glEnd();
		glPointSize(1);
	}

	if(displayControlLines)
	{
		glColor3f(0,1,0);
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < nPt; i++)
		{
			if (C1Continuity && (i % 3 == 1) && i != 1)
				glVertex2d(2 * ptList[i - 1].x - ptList[i - 2].x, 2 * ptList[i - 1].y - ptList[i - 2].y);
			else glVertex2d(ptList[i].x, ptList[i].y);
		}
		glEnd();
	}

	//Draw Curve
	double t;
	DoublePoint a;
	glColor3f(0, 0, 1);
	for (int i = 0; i < (nPt - 1) / 3; i++)
	{
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j <= NLINESEGMENT; j++)
		{
			t = 1.0 * j / NLINESEGMENT;
			a = coordinate(3, t, i);
			glVertex2d(a.x, a.y);
		}
		glEnd();
	}
	//Draw Tangents
	double alpha;
	DoublePoint b;
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	int second = sys.wHour * 3600 * 1000 + sys.wMinute * 60 * 1000 + sys.wSecond * 1000 + sys.wMilliseconds;
	if (displayObjects)
	{
		for (int i = 0; i < (nPt - 1) / 3; i++)
		{
			for (int j = 0; j <= NOBJECTONCURVE; j++)
			{
				glPushMatrix();
				t = 1.0 * j / NOBJECTONCURVE + second % 20000 / 20000.0;
				while (t > 1)
					t--;
				a = coordinate(3, t, i);
				glTranslated(a.x, a.y, 0);
				b = tangent(3, t, i);
				alpha = asin(b.y / sqrt(b.x * b.x + b.y * b.y)) / M_PI * 180;
				if (b.x < 0)
					alpha = 180 - alpha;
				glRotated(alpha, 0, 0, 1);
				Objects();
				glPopMatrix();
			}
		}
	}
	if (displayTangentVectors)
	{
		for (int i = 0; i < (nPt - 1) / 3; i++)
		{
			for (int j = 0; j <= NOBJECTONCURVE; j++)
			{
				glPushMatrix();
				t = 1.0 * j / NOBJECTONCURVE;
				a = coordinate(3, t, i);
				glTranslated(a.x, a.y, 0);
				b = tangent(3, t, i);
				alpha = asin(b.y / sqrt(b.x * b.x + b.y * b.y)) / M_PI * 180;
				if (b.x < 0)
					alpha = 180 - alpha;
				glRotated(alpha, 0, 0, 1);
				drawRightArrow();
				glPopMatrix();
			}
		}
	}
	glPopMatrix();
	glutSwapBuffers ();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,w,h,0);  
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}

void init(void)
{
	glClearColor (1.0,1.0,1.0, 1.0);
}

void readFile()
{

	std::ifstream file;
    file.open("savefile.txt");
	file >> nPt;

	if(nPt>MAXPTNO)
	{
		cout << "Error: File contains more than the maximum number of points." << endl;
		nPt = MAXPTNO;
	}

	for(int i=0;i<nPt;i++)
	{
		file >> ptList[i].x;
		file >> ptList[i].y;
	}
    file.close();// is not necessary because the destructor closes the open file by default
}

void writeFile()
{
	std::ofstream file;
    file.open("savefile.txt");
    file << nPt << endl;

	for(int i=0;i<nPt;i++)
	{
		file << ptList[i].x << " ";
		file << ptList[i].y << endl;
	}
    file.close();// is not necessary because the destructor closes the open file by default
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key) {
		case 'r':
		case 'R':
			readFile();
		break;

		case 'w':
		case 'W':
			writeFile();
		break;

		case 'T':
		case 't':
			displayTangentVectors = !displayTangentVectors;
		break;

		case 'o':
		case 'O':
			displayObjects = !displayObjects;
		break;

		case 'p':
		case 'P':
			displayControlPoints = !displayControlPoints;
		break;

		case 'L':
		case 'l':
			displayControlLines = !displayControlLines;
		break;

		case 'C':
		case 'c':
			C1Continuity = !C1Continuity;
		break;

		case 'e':
		case 'E':
			// Do something to erase all the control points added
			nPt = 0;
		break;

		case 27:
			exit(0);
		break;

		default:
		break;
	}

	glutPostRedisplay();
}



void mouse(int button, int state, int x, int y)
{
	/*button: GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, or GLUT_RIGHT_BUTTON */
	/*state: GLUT_UP or GLUT_DOWN */
	enum
	{
		MOUSE_LEFT_BUTTON = 0,
		MOUSE_MIDDLE_BUTTON = 1,
		MOUSE_RIGHT_BUTTON = 2,
		MOUSE_SCROLL_UP = 3,
		MOUSE_SCROLL_DOWN = 4
	};
	if((button == MOUSE_LEFT_BUTTON)&&(state == GLUT_UP))
	{
		if(nPt==MAXPTNO)
		{
			cout << "Error: Exceeded the maximum number of points." << endl;
			return;
		}
		ptList[nPt].x=x;
		ptList[nPt].y=y;
		nPt++;
	}
	glutPostRedisplay();
}
void idle()
{
	glutPostRedisplay();
}
int main(int argc, char **argv)
{
	cout<<"CS3241 Lab 4"<< endl<< endl;
	cout << "Left mouse click: Add a control point"<<endl;
	cout << "ESC: Quit" <<endl;
	cout << "P: Toggle displaying control points" <<endl;
	cout << "L: Toggle displaying control lines" <<endl;
	cout << "E: Erase all points (Clear)" << endl;
	cout << "C: Toggle C1 continuity" <<endl;	
	cout << "T: Toggle displaying tangent vectors" <<endl;
	cout << "O: Toggle displaying objects" <<endl;
	cout << "R: Read in control points from \"savefile.txt\"" <<endl;
	cout << "W: Write control points to \"savefile.txt\"" <<endl;
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (50, 50);
	glutCreateWindow ("CS3241 Assignment 4");
	init ();
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}
