#include <math.h>
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

float R = 0.5;
float G = 0.5;
float B = 0.5;

// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 0.0f, z = 10.0f;

float Move = 0;

void computePos(float Move)
{
    x = x + Move * lx * 0.1f;
    z = z + Move * lz * 0.1f;

}

void pressKey(int key, int xx, int yy)
{
    switch (key) {
		case GLUT_KEY_UP :
			Move = 0.5f;
			break;
		case GLUT_KEY_DOWN :
			Move = -0.5f;
			break;
	}
}

void releaseKey(int key, int x, int y)
{

	switch (key) {
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN :
			Move = 0;
			break;
	}
}

void drawCone() {

    glColor3f(R, G, B);
    glRotatef(-90.0f,1.0f, 0.0f, 0.0f);
    glutSolidCone(0.6f, 2.5f, 50, 50);

}

void changeSize(int w, int h)
{
    if (h==0)
        h = 1;
    float ratio = w * 1.0 / h;
    printf("%d %d\n", w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);

    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    if (Move) {
        computePos(Move);
    }


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(	x, 1.1f, z,
				x+lx, 1.0f,  z+lz,
				0.0f, 1.0f,  0.0f);

    glColor3f(0.9, 0.9, 0.9);

    //draw quads
    glBegin(GL_QUADS);
        glVertex3f(-100.0f, 0.0f, -100.0f);
        glVertex3f(-100.0f, 0.0f, 100.0f);
        glVertex3f(100.0f, 0.0f, 100.0f);
        glVertex3f(100.0f, 0.0f, -100.0f);
    glEnd();

    //draw road
    glColor3f(0.0, 0.5, 0.5);
    glBegin(GL_QUADS);
        glVertex3f(5.0f, 0.0f, 100.0f);
        glVertex3f(-5.0f, 0.0f, 100.0f);
        glVertex3f(-5.0f, 0.0f, -100.0f);
        glVertex3f(5.0f, 0.0f, -100.0f);
    glEnd();


    //draw 40 cone
    for (int i = -2; i <= 2; i++) {
        if (i != 0)
            for (int j = -10; j < 10; j++) {
                glPushMatrix();
                glTranslatef(i*7.0, 0, j*8.0);
                drawCone();
                glPopMatrix();
            }
    }


    glutSwapBuffers();
}


int main(int argc,char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Last Work");
    glutReshapeFunc(changeSize);
    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutSpecialFunc(pressKey);

    glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);

    glutMainLoop();
}

