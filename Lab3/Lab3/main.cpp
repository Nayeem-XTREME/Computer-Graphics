#include <math.h>
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
using namespace std;

void display();

int main(int argc,char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutCreateWindow("Second");
    glutDisplayFunc(display);
    glutMainLoop();
}

float mat[] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, .5, .6, .4, 1};

void display()
{
    gluLookAt(0.6, 0.7, 0.2, 0, 0.1, 0.2, 0.7, 0.5, 0.2);
    glMultMatrixf(mat);//rotate or transform instead of modelViewMatrix!
    glutSolidSphere(.5, 50, 2);
    glFlush();

}
