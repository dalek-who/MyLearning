// CS3241Lab5.cpp
#include <cmath>
#include <iostream>
#include "vector3D.h"
#include <chrono>


/* Include header files depending on platform */
#ifdef _WIN32
#include "GL\freeglut.h"
#define M_PI 3.14159
#elif __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>
#endif

using namespace std;

#define WINWIDTH 600
#define WINHEIGHT 400
#define NUM_OBJECTS 4
#define MAX_RT_LEVEL 50
#define NUM_SCENE 3

float* pixelBuffer = new float[WINWIDTH * WINHEIGHT * 3];

class Ray { // a ray that start with "start" and going in the direction "dir"
public:
	Vector3 start, dir;
};

class RtObject {

public:
	virtual double intersectWithRay(Ray, Vector3& pos, Vector3& normal) = 0; // return a -ve if there is no intersection. Otherwise, return the smallest postive value of t

																			 // Materials Properties
	double ambiantReflection[3];
	double diffusetReflection[3];
	double specularReflection[3];
	double speN = 300;


};
class Sphere : public RtObject {

	Vector3 center_;
	double r_;
public:
	Sphere(Vector3 c, double r) { center_ = c; r_ = r; };
	Sphere() {};
	void set(Vector3 c, double r) { center_ = c; r_ = r; };
	double intersectWithRay(Ray, Vector3& pos, Vector3& normal);
};

class Conics : public RtObject {

	Vector3 top_, axis_;
	double r_, h_;
public:
	Conics(Vector3 c, Vector3 n, double r, double h) { top_ = c; axis_ = n; axis_.normalize(); r_ = r; h_ = h; };
	Conics() {};
	void set(Vector3 c, Vector3 n, double r, double h) { top_ = c; axis_ = n; axis_.normalize(); r_ = r; h_ = h; };
	double intersectWithRay(Ray, Vector3& pos, Vector3& normal);
};

RtObject **objList; // The list of all objects in the scene


					// Global Variables
					// Camera Settings
Vector3 cameraPos(0, 0, -500);

// assume the the following two vectors are normalised
Vector3 lookAtDir(0, 0, 1);
Vector3 upVector(0, 1, 0);
Vector3 leftVector(1, 0, 0);
float focalLen = 500;

// Light Settings

Vector3 lightPos(900, 1000, -1500);
double ambiantLight[3] = { 0.4,0.4,0.4 };
double diffusetLight[3] = { 0.7,0.7, 0.7 };
double specularLight[3] = { 0.5,0.5, 0.5 };


double bgColor[3] = { 0.1,0.1,0.4 };

int sceneNo = 0;
/*==============================
Modify Section Here
Hint: Add additional methods to help you in solving equations
==============================*/
double Sphere::intersectWithRay(Ray r, Vector3& intersection, Vector3& normal)
// return a -ve if there is no intersection. Otherwise, return the smallest postive value of t
{// Step 1
	double a, b, c, t;
	a = dot_prod(r.dir, r.dir);
	b = 2 * dot_prod(r.dir, r.start - center_);
	c = dot_prod(r.start - center_, r.start - center_) - r_ * r_;
	double delta;
	delta = b * b - 4 * a * c;
	if (delta <= 0)
		return -1;
	else
	{
		if (a * c < 0)
			t = (-b + sqrt(delta)) / (2 * a);
		else if (a * c > 0)
			t = (-b - sqrt(delta)) / (2 * a);
		else return -1;
		intersection = r.start + r.dir * t;
		normal = intersection - center_;
		normal.normalize();
		return t;
	}
}
double Conics::intersectWithRay(Ray r, Vector3& intersection, Vector3& normal)
{
	double a, b, c, t1, t2;
	Vector3 M, N, L, center_;
	double p, q, s, delta;
	//t1 part circle:
	//axis_ * ((r.start + r.dir * t1) - (top_ + axis_ * h_)) = 0 ---1
	//|(r.start + r.dir * t1) - (top_ + axis_ * h_)| <= r_ ---2
	//from 1. t1 = (axis_t * (top_ + axis_ * h - r.start)) / (axis_ * r.dir) 
	//t1 = dot_prod(axis_, top_ + axis_ * h_ - r.start) / dot_prod(axis_, r.dir);
	//L = r.start + r.dir * t1 - (top_ + axis_ * h_);
	//if (dot_prod(L, L) >= r_ * r_)
	//	t1 = -1;
	//t1 part Sphere
	center_ = top_ + axis_ * h_;
	a = dot_prod(r.dir, r.dir);
	b = 2 * dot_prod(r.dir, r.start - center_);
	c = dot_prod(r.start - center_, r.start - center_) - r_ * r_;
	delta = b * b - 4 * a * c;
	if (delta > 0)
	{
		Vector3 A, B;
		if (a * c < 0)
		{
			t1 = (-b + sqrt(delta)) / (2 * a);
			A = top_ - (r.start + r.dir * t1);
			if (h_ * h_ + r_ * r_ - (dot_prod(A, A)) > 0)
				t1 = -1;
		}
		else if (a * c > 0)
		{
			t1 = (-b - sqrt(delta)) / (2 * a);
			A = top_ - (r.start + r.dir * t1);
			if (h_ * h_ + r_ * r_ - (dot_prod(A, A)) > 0)
			{
				t1 = (-b + sqrt(delta)) / (2 * a);
				A = top_ - (r.start + r.dir * t1);
				if (h_ * h_ + r_ * r_ - (dot_prod(A, A)) > 0)
					t1 = -1;
			}
		}
		else t1 = -1;
	}
	else t1 = -1;
	//t2 part:
	//|(r.start + r.dir * t2) - (top_ + axis_ * s)| = r_ / h_ * s ---3
	//axis_ * ((r.start + r.dir * t2) - (top_ + axis_ * s)) = 0 ---4
	//from 4. s = (axis * (r.start + r.dir * t2 - top_)) / (axis_ * axis_)
	//axis_ * axis_ = 1
	//so s = axis * (r.start + r.dir * t2 - top_)
	//3. |(r.start + r.dir * t2) - (top_ + axis_ * (axis * (r.start + r.dir * t2 - top_))| = r_ / h_ * (axis * (r.start + r.dir * t2 - top_))
	//3. |Mt + N| = pt + q;
	//M = r.dir - axis_ * (axis_ * r.dir)
	//N = r.start - top_ - axis_ * (axis_ * (r.start - top_))
	//p = r_ / h_ * axis_ * r.dir
	//q = r_ / h_ * axis * (r.start - top_)
	M = r.dir - axis_ * dot_prod(axis_, r.dir);
	N = r.start - top_ - axis_ * dot_prod(axis_, r.start - top_);
	p = r_ / h_ * dot_prod(axis_, r.dir);
	q = r_ / h_ * dot_prod(axis_, r.start - top_);
	a = dot_prod(M, M) - p * p;
	b = 2 * dot_prod(M, N) - 2 * p * q;
	c = dot_prod(N, N) - q * q;
	if (a < 0)
	{
		a = -a;
		b = -b;
		c = -c;
	}
	delta = b * b - 4 * a * c;
	if (delta > 0)
	{
		if (a * c < 0)
			t2 = (-b + sqrt(delta)) / (2 * a);
		else if (a * c > 0)
			t2 = (-b - sqrt(delta)) / (2 * a);
		else if (a * c == 0)
		{
			if (a == 0 && b != 0)
				t2 = c / b;
			else if (c == 0 && a != 0)
				t2 = b / a;
			else t2 = -1;
		}
		s = dot_prod(axis_, r.start + r.dir * t2 - top_);
		if (s > h_ || s <= 0)
			t2 = -1;
	}
	else t2 = -1;

	if (t1 <= 0 && t2 <= 0)
		return -1;
	if (t2 <= 0 || (t1 <= t2 && t1 > 0))
	{
		//normal = axis_;
		//normal.normalize();
		//intersection = r.start + r.dir * t1;
		intersection = r.start + r.dir * t1;
		normal = intersection - center_;
		normal.normalize();
		return t1;
	}
	else
	{
		s = s * (r_ * r_ / h_ / h_ + 1);
		intersection = r.start + r.dir * t2;
		normal = (intersection - (top_ + axis_ * s));
		normal.normalize();
		return t2;
	}

}
void addAnotherScene(int i) {
	//Step 5: Modify objList here
	if (i == 1)
	{
		((Sphere*)objList[0])->set(Vector3(70, 0, -300), 20);
		((Sphere*)objList[1])->set(Vector3(70, 20, -100), 80);
		((Sphere*)objList[2])->set(Vector3(-50, 10, -280), 50);
		((Sphere*)objList[3])->set(Vector3(0, -260, -100), 200);
	}
	else
	{
		for (int i = 0; i < NUM_OBJECTS; i++)
			delete objList[i];
		objList[0] = new Conics();
		objList[1] = new Conics();
		objList[2] = new Conics();
		objList[3] = new Conics();
		((Conics*)objList[0])->set(Vector3(100, 60, -170), Vector3(-1, -1, 0), 25, 60);
		((Conics*)objList[1])->set(Vector3(20, 40, -240), Vector3(-0.2, -1, 0.2), 20, 40);
		((Conics*)objList[2])->set(Vector3(-90, 70, -120), Vector3(1, -1, -1), 30, 80);
		((Conics*)objList[3])->set(Vector3(0, -180, -100), Vector3(0, 1, -0.5), 70, 160);
	}



	objList[0]->ambiantReflection[0] = 0.2;
	objList[0]->ambiantReflection[1] = 0.5;
	objList[0]->ambiantReflection[2] = 0.5;
	objList[0]->diffusetReflection[0] = 0;
	objList[0]->diffusetReflection[1] = 1;
	objList[0]->diffusetReflection[2] = 1;
	objList[0]->specularReflection[0] = 0.4;
	objList[0]->specularReflection[1] = 0.4;
	objList[0]->specularReflection[2] = 0.4;
	objList[0]->speN = 300;

	objList[1]->ambiantReflection[0] = 0.7;
	objList[1]->ambiantReflection[1] = 0.7;
	objList[1]->ambiantReflection[2] = 0.3;
	objList[1]->diffusetReflection[0] = 1;
	objList[1]->diffusetReflection[1] = 1;
	objList[1]->diffusetReflection[2] = 0;
	objList[1]->specularReflection[0] = 0.0;
	objList[1]->specularReflection[1] = 0.0;
	objList[1]->specularReflection[2] = 0.0;
	objList[1]->speN = 50;

	objList[2]->ambiantReflection[0] = 0.2;
	objList[2]->ambiantReflection[1] = 0.7;
	objList[2]->ambiantReflection[2] = 0.2;
	objList[2]->diffusetReflection[0] = 0.1;
	objList[2]->diffusetReflection[1] = 1;
	objList[2]->diffusetReflection[2] = 0.1;
	objList[2]->specularReflection[0] = 0.3;
	objList[2]->specularReflection[1] = 0.3;
	objList[2]->specularReflection[2] = 0.3;
	objList[2]->speN = 650;

	objList[3]->ambiantReflection[0] = 0.4;
	objList[3]->ambiantReflection[1] = 0.4;
	objList[3]->ambiantReflection[2] = 0.4;
	objList[3]->diffusetReflection[0] = 0.7;
	objList[3]->diffusetReflection[1] = 0.7;
	objList[3]->diffusetReflection[2] = 0.7;
	objList[3]->specularReflection[0] = 0.6;
	objList[3]->specularReflection[1] = 0.6;
	objList[3]->specularReflection[2] = 0.6;
	objList[3]->speN = 650;
}
void rayTrace(Ray ray, double& r, double& g, double& b, int fromObj = -1 ,int level = 0)
{
	// Step 4
	// Checks if it reaches MAX_RT_LEVEL
	if (level < MAX_RT_LEVEL)
		level++;
	else 
	{
		r = 0.0; g = 0.0; b = 0.0;
		return;
	}

	int goBackGround = 1, i = 0;
	double inColor[3];

	Vector3 intersection, normal;
	Vector3 lightV;
	Vector3 viewV;
	Vector3 lightReflectionV;
	Vector3 rayReflectionV;

	Ray newRay, lightRay;
	double mint = DBL_MAX, t;

	double fatt = 1;
	double x1, x2;
	double flag;
	Vector3 intersection_, normal_;
	for (i = 0; i < NUM_OBJECTS; i++)
	//Remove above loop comment after step 1
	if(i != fromObj)
	{
		t = objList[i]->intersectWithRay(ray, intersection, normal);
		if (t > 0 && t < mint)
		{
			mint = t;
			//r = g = b = 1.0; 			// Step 2
			r = ambiantLight[0] * objList[i]->ambiantReflection[0];
			g = ambiantLight[1] * objList[i]->ambiantReflection[1];
			b = ambiantLight[2] * objList[i]->ambiantReflection[2];
			// Step 3
			goBackGround = 0;
			lightV = (-intersection + lightPos);
			lightV.normalize();
			viewV = -ray.dir;
			viewV.normalize();
			lightReflectionV = normal * dot_prod(normal, lightV) * 2 - lightV;
			//shadow
			lightRay.start = intersection;
			lightRay.dir = lightPos - intersection;
			lightRay.dir.normalize();
			flag = 1;
			for (int j = 0; j < NUM_OBJECTS; j++)
			{
				if (j != i)
				{
					if (objList[j]->intersectWithRay(lightRay, intersection_, normal_) > 0)
					{
						flag = 0;
						break;
					}
				}
					
			}
			if (flag)
			{
				x1 = dot_prod(normal, lightV);
				x2 = pow(dot_prod(lightReflectionV, viewV), objList[i]->speN);
				r += fatt * objList[i]->diffusetReflection[0] * x1;
				g += fatt * objList[i]->diffusetReflection[1] * x1;
				b += fatt * objList[i]->diffusetReflection[2] * x1;
				r += fatt * objList[i]->specularReflection[0] * x2;
				g += fatt * objList[i]->specularReflection[1] * x2;
				b += fatt * objList[i]->specularReflection[2] * x2;
			}
			rayReflectionV = normal * dot_prod(normal, viewV) * 2 - viewV;
			newRay.start = intersection;
			newRay.dir = rayReflectionV;
			rayTrace(newRay, inColor[0], inColor[1], inColor[2], i, level);
			r += inColor[0] * objList[i]->specularReflection[0];
			g += inColor[1] * objList[i]->specularReflection[1];
			b += inColor[2] * objList[i]->specularReflection[2];
			
		}
	}

	if (goBackGround)
	{
		r = bgColor[0];
		g = bgColor[1];
		b = bgColor[2];
	}

}
/*==============================
End of Section,
IT IS NOT RECOMMENDED TO CHANGE ANYTHING BELOW
==============================*/



void drawInPixelBuffer(int x, int y, double r, double g, double b)
{
	pixelBuffer[(y*WINWIDTH + x) * 3] = (float)r;
	pixelBuffer[(y*WINWIDTH + x) * 3 + 1] = (float)g;
	pixelBuffer[(y*WINWIDTH + x) * 3 + 2] = (float)b;
}

void renderScene()
{
	int x, y;
	Ray ray;
	double r, g, b;

	cout << "Rendering Scene " << sceneNo << " with resolution " << WINWIDTH << "x" << WINHEIGHT << "........... ";
	__int64 time1 = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count(); // marking the starting time

	ray.start = cameraPos;

	Vector3 vpCenter = cameraPos + lookAtDir * focalLen;  // viewplane center
	Vector3 startingPt = vpCenter + leftVector * (-WINWIDTH / 2.0) + upVector * (-WINHEIGHT / 2.0);
	Vector3 currPt;

	for (x = 0; x<WINWIDTH; x++)
		for (y = 0; y < WINHEIGHT; y++)
		{
			currPt = startingPt + leftVector*x + upVector*y;
			ray.dir = currPt - cameraPos;
			ray.dir.normalize();
			rayTrace(ray, r, g, b);
			drawInPixelBuffer(x, y, r, g, b);
		}

	__int64 time2 = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count(); // marking the ending time

	cout << "Done! \nRendering time = " << time2 - time1 << "ms" << endl << endl;
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_DOUBLEBUFFER);
	glDrawPixels(WINWIDTH, WINHEIGHT, GL_RGB, GL_FLOAT, pixelBuffer);
	glutSwapBuffers();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void setScene(int i = 0)
{
	if (i > NUM_SCENE)
	{
		cout << "Warning: Invalid Scene Number" << endl;
		return;
	}

	if (i == 0)
	{
		for (int i = 0; i < NUM_OBJECTS; i++)
			delete objList[i];

		objList[0] = new Sphere();
		objList[1] = new Sphere();
		objList[2] = new Sphere();
		objList[3] = new Sphere();
		((Sphere*)objList[0])->set(Vector3(-130, 80, 120), 100);
		((Sphere*)objList[1])->set(Vector3(130, -80, -80), 100);
		((Sphere*)objList[2])->set(Vector3(-130, -80, -80), 100);
		((Sphere*)objList[3])->set(Vector3(130, 80, 120), 100);
		

		objList[0]->ambiantReflection[0] = 0.1;
		objList[0]->ambiantReflection[1] = 0.4;
		objList[0]->ambiantReflection[2] = 0.4;
		objList[0]->diffusetReflection[0] = 0;
		objList[0]->diffusetReflection[1] = 1;
		objList[0]->diffusetReflection[2] = 1;
		objList[0]->specularReflection[0] = 0.2;
		objList[0]->specularReflection[1] = 0.4;
		objList[0]->specularReflection[2] = 0.4;
		objList[0]->speN = 300;

		objList[1]->ambiantReflection[0] = 0.6;
		objList[1]->ambiantReflection[1] = 0.6;
		objList[1]->ambiantReflection[2] = 0.2;
		objList[1]->diffusetReflection[0] = 1;
		objList[1]->diffusetReflection[1] = 1;
		objList[1]->diffusetReflection[2] = 0;
		objList[1]->specularReflection[0] = 0.0;
		objList[1]->specularReflection[1] = 0.0;
		objList[1]->specularReflection[2] = 0.0;
		objList[1]->speN = 50;

		objList[2]->ambiantReflection[0] = 0.1;
		objList[2]->ambiantReflection[1] = 0.6;
		objList[2]->ambiantReflection[2] = 0.1;
		objList[2]->diffusetReflection[0] = 0.1;
		objList[2]->diffusetReflection[1] = 1;
		objList[2]->diffusetReflection[2] = 0.1;
		objList[2]->specularReflection[0] = 0.3;
		objList[2]->specularReflection[1] = 0.7;
		objList[2]->specularReflection[2] = 0.3;
		objList[2]->speN = 650;

		objList[3]->ambiantReflection[0] = 0.3;
		objList[3]->ambiantReflection[1] = 0.3;
		objList[3]->ambiantReflection[2] = 0.3;
		objList[3]->diffusetReflection[0] = 0.7;
		objList[3]->diffusetReflection[1] = 0.7;
		objList[3]->diffusetReflection[2] = 0.7;
		objList[3]->specularReflection[0] = 0.6;
		objList[3]->specularReflection[1] = 0.6;
		objList[3]->specularReflection[2] = 0.6;
		objList[3]->speN = 650;

	}

	if (i >= 1)
	{

		// Step 5
		addAnotherScene(i);
	}
}

void keyboard(unsigned char key, int x, int y)
{
	//keys to control scaling - k
	//keys to control rotation - alpha
	//keys to control translation - tx, ty
	switch (key) {
	case 's':
	case 'S':
		sceneNo = (sceneNo + 1) % NUM_SCENE;
		setScene(sceneNo);
		renderScene();
		glutPostRedisplay();
		break;
	case 'q':
	case 'Q':
		exit(0);

	default:
		break;
	}
}

int main(int argc, char **argv)
{


	cout << "<<CS3241 Lab 5>>\n\n" << endl;
	cout << "S to go to next scene" << endl;
	cout << "Q to quit" << endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WINWIDTH, WINHEIGHT);

	glutCreateWindow("CS3241 Lab 5: Ray Tracing");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutKeyboardFunc(keyboard);

	objList = new RtObject*[NUM_OBJECTS];

	// create four spheres
	objList[0] = new Sphere(Vector3(-130, 80, 120), 100);
	objList[1] = new Sphere(Vector3(130, -80, -80), 100);
	objList[2] = new Sphere(Vector3(-130, -80, -80), 100);
	objList[3] = new Sphere(Vector3(130, 80, 120), 100);

	setScene(0);

	setScene(sceneNo);
	renderScene();

	glutMainLoop();

	for (int i = 0; i < NUM_OBJECTS; i++)
		delete objList[i];
	delete[] objList;

	delete[] pixelBuffer;

	return 0;
}
