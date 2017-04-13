// CS3241Lab2.cpp : Defines the entry point for the console application.
#include <cmath>
#include <iostream>
#include <windows.h>
#include <stdio.h> 
/* Include header files depending on platform */
#ifdef _WIN32
    #include "GL\freeglut.h"
	#define M_PI 3.14159
#elif __APPLE__
	#include <OpenGL/gl.h>
	#include <GLUT/GLUT.h>
#endif

using namespace std;

#define numStars 100
#define numPlanets 9
class planet
{
public:
	float distFromRef;
	float angularSpeed;
	float autoSpeed;
	float autoangle;
	GLfloat color[3];
	float size;
	float angle;
	float count;//satellite

	planet()
	{
		distFromRef = 0;
		angularSpeed = 0;
		autoSpeed = 0;
		color[0] = color[1] = color[2] = 0;
		size = 0;
		autoangle = 0;
		angle = 0;
		count = 0;
	}
};

float alpha = 0.0, k=1;
float tx = 0.0, ty=0.0;
planet planetList[numPlanets];
int flag = 0;
float transparency1 = 1, transparency2 = 0;
GLuint TextFont;

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
	glClearColor (0.0, 33 / 255.0, 66 / 255.0, 1.0);
	glShadeModel (GL_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void init_planet(void)
{
	//loading characters
	TextFont = glGenLists(128);
	wglUseFontBitmaps(wglGetCurrentDC(), 0, 128, TextFont);

	//Sun Mercury Venus Earth Mars Jupiter Saturn Uranus Neptune
	planetList[0].distFromRef = 0; planetList[1].distFromRef = 12; planetList[2].distFromRef = 16;
	planetList[3].distFromRef = 21; planetList[4].distFromRef = 26; planetList[5].distFromRef = 40;
	planetList[6].distFromRef = 49; planetList[7].distFromRef = 57; planetList[8].distFromRef = 64;
	//planetList[0].distFromRef = 0; planetList[1].distFromRef = 58; planetList[2].distFromRef = 108;
	//planetList[3].distFromRef = 150; planetList[4].distFromRef = 228; planetList[5].distFromRef = 778;
	//planetList[6].distFromRef = 1427; planetList[7].distFromRef = 2870; planetList[8].distFromRef = 4497;

	planetList[0].angularSpeed = 0; planetList[1].angularSpeed = 365.0 / 88; planetList[2].angularSpeed = 365.0 / 225;
	planetList[3].angularSpeed = 1; planetList[4].angularSpeed = 365.0 / 687; planetList[5].angularSpeed = 365.0 / 4333;
	planetList[6].angularSpeed = 365.0 / 10760; planetList[7].angularSpeed = 365.0 / 30685; planetList[8].angularSpeed = 365.0 / 60190;

	planetList[0].autoSpeed = 12.0 / (365.0 * 1610); planetList[1].autoSpeed = 12.0 / 59; planetList[2].autoSpeed = - 12.0 / 243;
	planetList[3].autoSpeed = 12.0 / 1; planetList[4].autoSpeed = 12.0 / 1; planetList[5].autoSpeed = 12.0 / 0.4;
	planetList[6].autoSpeed = 12.0 / 0.5; planetList[7].autoSpeed = 0 * 12.0 / 0.7; planetList[8].autoSpeed = 12.0 / 0.6;

	planetList[0].size = 10; planetList[1].size = 1; planetList[2].size = 2;
	planetList[3].size = 2.5; planetList[4].size = 1.5; planetList[5].size = 4.5;
	planetList[6].size = 4; planetList[7].size = 3.5; planetList[8].size = 3;
	//planetList[0].size = 1300000; planetList[1].size = 0.056; planetList[2].size = 0.86;
	//planetList[3].size = 1; planetList[4].size = 0.15; planetList[5].size = 1317;
	//planetList[6].size = 745; planetList[7].size = 65; planetList[8].size = 57;

	planetList[0].color[0] = 1; planetList[0].color[1] = 0; planetList[0].color[2] = 0;
	planetList[1].color[0] = 213 / 255.0; planetList[1].color[1] = 172 / 255.0; planetList[1].color[2] = 10 / 255.0;
	planetList[2].color[0] = 0.8; planetList[2].color[1] = 0.2; planetList[2].color[2] = 0;
	planetList[3].color[0] = 0.2; planetList[3].color[1] = 0.2; planetList[3].color[2] = 1;
	planetList[4].color[0] = 0.8; planetList[4].color[1] = 0.1; planetList[4].color[2] = 0.1;
	planetList[5].color[0] = 0.8; planetList[5].color[1] = 0.6; planetList[5].color[2] = 0.2;
	planetList[6].color[0] = 0.8; planetList[6].color[1] = 0.5; planetList[6].color[2] = 0;
	planetList[7].color[0] = 0.4; planetList[7].color[1] = 0.4; planetList[7].color[2] = 0.5;
	planetList[8].color[0] = 0.1; planetList[8].color[1] = 0.1; planetList[8].color[2] = 1;

	planetList[0].count = 0; planetList[1].count = 0; planetList[2].count = 0;
	planetList[3].count = 1; planetList[4].count = 2; planetList[5].count = 6;
	planetList[6].count = 5; planetList[7].count = 4; planetList[8].count = 3;
	//planetList[0].count = 0; planetList[1].count = 0; planetList[2].count = 0;
	//planetList[3].count = 1; planetList[4].count = 2; planetList[5].count = 63;
	//planetList[6].count = 47; planetList[7].count = 27; planetList[8].count = 8;
}
void drawcircle(float x, float y, float z, float size, float a, float b, float t)
{
	for (int j = 0; j < 180; j++)
	{
		glColor4f(x + j * 0.5 / 255.0, y + j * 0.5 / 255.0, z + j * 0.5 / 255.0, t);
		glBegin(GL_POLYGON);
		glVertex2f(a + size * cos(j *  M_PI / 180), b + size * sin(j *  M_PI / 180));
		glVertex2f(a + size * cos((j + 1) *  M_PI / 180), b + size * sin((j + 1) *  M_PI / 180));
		glVertex2f(a + size * cos(-(j + 1) *  M_PI / 180), b + size * sin(-(j + 1) *  M_PI / 180));
		glVertex2f(a + size * cos(-j *  M_PI / 180), b + size * sin(-j *  M_PI / 180));
		glEnd();
	}
}
void satellite(int i, float second, float t)
{
	float r, d, s;
	for (int j = 0; j < planetList[i].count; j++)
	{
		r = rand() % 46 / 100.0;
		d = rand() % 100 / 99.0;
		glPushMatrix();
		glRotatef(j * 360.0 / planetList[i].count, 0, 0, 1);
		glRotatef(365.0 / 28.0 * second, 0, 0, 1);//the period of revolution is based on moon
		glTranslatef((planetList[i].size + d), 0, 0);
		drawcircle(0.6, 0.6, 0.5, r, 0, 0, t);
		glPopMatrix();
	}
}
void yantuanzi(int k, float second)
{
	glPushMatrix();
	int i, period = 50;
	i = second / 50;
	float t, height = 10;
	float size = planetList[k].size - 1;
	if (second - i * period < period / 2)
		t = second - i * period;
	else t = period - (second - i * period);
	glRotatef(planetList[k].angle, 0, 0, 1);
	glTranslatef(planetList[k].size + size * 0.85 + t / (period / 2) * height, 0, 0);
	glColor4f(1, 1, 1, transparency1);
	glBegin(GL_POLYGON);
		for (int j = 0; j < 360; j++)
			glVertex2f(size * 0.85 * cos(j *  M_PI / 180), size * sin(j *  M_PI / 180));
	glEnd();
	glColor4f(0, 0, 0, transparency1);
	glBegin(GL_LINE_LOOP);
		for (int j = 0; j < 360; j++)
			glVertex2f(size * 0.85 * cos(j *  M_PI / 180), size * sin(j *  M_PI / 180));
	glEnd();
	//eye
	glBegin(GL_POLYGON);
		for (int j = 0; j < 360; j++)
			glVertex2f(size * 0.2 + size * 0.12 * cos(j *  M_PI / 180), size * -0.4 + size * 0.12 * sin(j *  M_PI / 180));
	glEnd();
	glBegin(GL_POLYGON);
		for (int j = 0; j < 360; j++)
			glVertex2f(size * 0.2 + size * 0.12 * cos(j *  M_PI / 180), size * 0.4 + size * 0.12 * sin(j *  M_PI / 180));
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(size * 0.4, size * 0.3);
		glVertex2f(size * 0.35, size * 0.3);
		glVertex2f(size * 0.45, size * 0.5);
		glVertex2f(size * 0.5, size * 0.5);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(size * 0.4, size * -0.3);
		glVertex2f(size * 0.35, size * -0.3);
		glVertex2f(size * 0.45, size * -0.5);
		glVertex2f(size * 0.5, size * -0.5);
	glEnd();
	//mouth
	glBegin(GL_POLYGON);
		glVertex2f(size * 0.1, size * 0.1);
		glVertex2f(size * -0.1, size * 0);
		glVertex2f(size * -0.15, size * 0);
		glVertex2f(size * 0.1, size * 0.15);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(size * 0.1, size * -0.1);
		glVertex2f(size * -0.1, size * -0);
		glVertex2f(size * -0.15, size * -0);
		glVertex2f(size * 0.1, size * -0.15);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(size * 0.05, size * -0.08);
		glVertex2f(size * 0.05, size * 0.08);
		glVertex2f(size * 0.02, size * 0.07);
		glVertex2f(size * 0.02, size * -0.07);
	glEnd();
	//face blush
	glColor4f(1, 0.5, 0.5, transparency1);
	glBegin(GL_POLYGON);
		for (int j = 0; j < 360; j++)
			glVertex2f(size * -0.05 + size * 0.08 * cos(j *  M_PI / 180), size * 0.7 + size * 0.05 * sin(j *  M_PI / 180));
	glEnd();
	glBegin(GL_POLYGON);
	for (int j = 0; j < 360; j++)
		glVertex2f(size * -0.1 + size * 0.07 * cos(j *  M_PI / 180), size * 0.5 + size * 0.05 * sin(j *  M_PI / 180));
	glEnd();
	glBegin(GL_POLYGON);
	for (int j = 0; j < 360; j++)
		glVertex2f(size * -0.05 + size * 0.08 * cos(j *  M_PI / 180), size * -0.7 + size * 0.05 * sin(j *  M_PI / 180));
	glEnd();
	glBegin(GL_POLYGON);
	for (int j = 0; j < 360; j++)
		glVertex2f(size * -0.1 + size * 0.07 * cos(j *  M_PI / 180), size * -0.5 + size * 0.05 * sin(j *  M_PI / 180));
	glEnd();
	glPopMatrix();
}
void drawplanet(int i, float second, float c1, float c2)
{
	glPushMatrix();
	planetList[i].autoangle = second * planetList[i].autoSpeed;
	planetList[i].angle = second * planetList[i].angularSpeed;
	glTranslatef(planetList[i].distFromRef * c1 * cos(planetList[i].angle *  M_PI / 180), planetList[i].distFromRef * c2 * sin(planetList[i].angle *  M_PI / 180), 0);
	glRotatef(planetList[i].autoangle, 0, 0, 1);
	drawcircle(planetList[i].color[0], planetList[i].color[1], planetList[i].color[2], planetList[i].size, 0, 0, transparency1);
	glRotatef(-planetList[i].autoangle, 0, 0, 1);
	if (i == 6)//ring of Saturn
	{
		float x, y, a, b;
		for (int j = 49; j > -229; j--)
		{
			glColor4f(0.7, 0.4, 0, transparency1);
			x = (planetList[i].size + 0.2) * 1.2;
			a = (planetList[i].size + 0.2) * 0.4;
			y = (planetList[i].size + 1.5) * 1.2;
			b = (planetList[i].size + 1.5) * 0.4;
			glBegin(GL_POLYGON);
			glVertex2f(x * cos(j *  M_PI / 180),a * sin(j *  M_PI / 180));
			glVertex2f(x * cos((j + 1) *  M_PI / 180), a * sin((j + 1) *  M_PI / 180));
			glVertex2f(y * cos((j + 1) *  M_PI / 180), b * sin((j + 1) *  M_PI / 180));
			glVertex2f(y * cos(j *  M_PI / 180), b * sin(j *  M_PI / 180));
			glEnd();
		}
	}
	if (i == 5)
	{
		yantuanzi(i, second);
	}
	satellite(i, second, transparency1);
	glPopMatrix();
}
void asteroid_belt(float second)
{
	glPushMatrix();
	glRotatef(365.0 / 2000 * second, 0, 0, 1);
	float x, y, r;
	for (int i = 0; i < 360;)
	{
		r = rand() % 50 / 100.0;
		x = (30 + rand() % 50 / 10.0) * cos(i *  M_PI / 180);
		y = (30 + rand() % 50 / 10.0) * sin(i *  M_PI / 180);
		drawcircle(0.8, 0.8, 0.8, r, x, y, 1);
		i = i + (rand() % 3);
	}
	glPopMatrix();
}
void stars(int second)
{
	float x, y, r, d;
	int t;
	for (int i = 0; i < 81; i++)
	{
		x = rand() % 133 - 66;
		y = rand() % 133 - 66;
		r = rand() % 100 / 100.0;
		d = rand() % 100 / 99.0;
		t = rand() % 200 + 50;
		if ((second % t) <= (t / 2))
			d = (d * (second % t)) / (t / 2);
		else d = (d * (t - second % t)) / (t / 2);
		glColor4f(1, 1, 1, d);
		glBegin(GL_POLYGON);
		for (int j = 0; j < 360; j += 30)
			glVertex2f(x + r * cos(j *  M_PI / 180), y + r * sin(j *  M_PI / 180));
		glEnd();
	}
}
void showchar(char *str)
{
	for (; *str != '\0'; *str++)
		glCallList(TextFont + *str);
}
void clock(float second)
{
	for (int i = 5; i < 8; i++)
	{
		glColor4f(1, 1, 1, 0.1 * transparency2);
		glBegin(GL_LINE_LOOP);
		for (int j = 0; j <= 359; j++)
			glVertex2f(planetList[i].distFromRef * cos(j *  M_PI / 180), planetList[i].distFromRef * sin(j *  M_PI / 180));
		glEnd();
	}

	int i = 0;
	drawcircle(planetList[i].color[0], planetList[i].color[1], planetList[i].color[2], planetList[i].size, 0, 0, transparency2);

	i = second;
	glColor4f(1, 0.8, 0, transparency2);
	glRasterPos2f(-5.8 / k, - 1.0 / k);
	char str[10];
	sprintf_s(str, 10, "%02d:%02d:%02d", i / 18000 % 24, i / 300 % 60, i / 50 % 60);
	showchar(str);

	i = 7;
	glPushMatrix();
	planetList[i].angle = 90 - second * 360 / (50 * 60);
	glTranslatef(planetList[i].distFromRef * cos(planetList[i].angle *  M_PI / 180), planetList[i].distFromRef * sin(planetList[i].angle *  M_PI / 180), 0);
	drawcircle(planetList[i].color[0], planetList[i].color[1], planetList[i].color[2], planetList[i].size, 0, 0, transparency2);
	satellite(i, second, transparency2);
	glPopMatrix();
	i = 6;
	glPushMatrix();
	planetList[i].angle = 90 - second * 360 / (50 * 60 * 60);
	glTranslatef(planetList[i].distFromRef * cos(planetList[i].angle *  M_PI / 180), planetList[i].distFromRef * sin(planetList[i].angle *  M_PI / 180), 0);
	drawcircle(planetList[i].color[0], planetList[i].color[1], planetList[i].color[2], planetList[i].size, 0, 0, transparency2);
	satellite(i, second, transparency2);
	glPopMatrix();
	i = 5;
	glPushMatrix();
	planetList[i].angle = 90 - second * 360 / (50 * 60 * 60 * 12);
	glTranslatef(planetList[i].distFromRef * cos(planetList[i].angle *  M_PI / 180), planetList[i].distFromRef * sin(planetList[i].angle *  M_PI / 180), 0);
	drawcircle(planetList[i].color[0], planetList[i].color[1], planetList[i].color[2], planetList[i].size, 0, 0, transparency2);
	satellite(i, second, transparency2);
	glPopMatrix();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();

	//controls transformation
	glScalef(k, k, k);	
	glTranslatef(tx, ty, 0);	
	glRotatef(alpha, 0, 0, 1);

	//draw stuff here!
	glScalef(0.15, 0.15, 0.15);
	srand(0);
	//get time
	SYSTEMTIME sys;
	GetLocalTime(&sys);

	float second = (sys.wHour * 3600 * 1000 + sys.wMinute * 60 * 1000 + sys.wSecond * 1000 + sys.wMilliseconds) / 20.0;

	stars((int)second);
	asteroid_belt(second);
	
	if (flag)
	{
		if(transparency1 > 0)
			transparency1 = transparency1 - 0.02;
		else if(transparency2 < 1)
			transparency2 = transparency2 + 0.02;
	}
	else
	{
		if(transparency2 > 0)
			transparency2 = transparency2 - 0.02;
		else if (transparency1 < 1)
			transparency1 = transparency1 + 0.02;
	}

	if (transparency2 > 0)
		clock(second);

	float c1, c2;
	if (transparency1 > 0)
	{
		for (int i = 0; i < 9; i++)
		{
			glColor4f(1, 1, 1, 0.1 * transparency1);
			c1 = (rand() % 20 + 90) / 100.0;
			c2 = (rand() % 40 + 80) / 100.0;
			glBegin(GL_LINE_LOOP);
			for (int j = 0; j <= 359; j++)
				glVertex2f(planetList[i].distFromRef * c1 * cos(j *  M_PI / 180), planetList[i].distFromRef * c2 * sin(j *  M_PI / 180));
			glEnd();
			drawplanet(i, second, c1, c2);
		}
	}
	
	glPopMatrix();
	glFlush ();
}

void idle()
{
	//update animation here
	
	glutPostRedisplay();	//after updating, draw the screen again
}

void keyboard (unsigned char key, int x, int y)
{
	//keys to control scaling - k
	//keys to control rotation - alpha
	//keys to control translation - tx, ty
	switch (key) {
		case 't':
			flag = 1 - flag;
			glutPostRedisplay();
		break;

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
	cout<<"CS3241 Lab 2\n\n";
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
	init_planet();
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);	
	//glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}
