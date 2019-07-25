/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void display();

int main(int argc,char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 800);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutCreateWindow("First");
    glutDisplayFunc(display);
    glutMainLoop();
}

float i;

void display()
{

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glRotatef((GLfloat)i,0,0,1);

    //glColor3f(1.0,1.0,1.0);

    glBegin(GL_LINES);
        glColor3f(1,0,0);

            glVertex2f(-.4, 0);
            glVertex2f(0, .2);

            glVertex2f(0,.2);
            glVertex2f(.4, 0);

            glVertex2f(.4, 0);
            glVertex2f(0, -.2);

            glVertex2f(0, -.2);
            glVertex2f(-.4, 0);


    glEnd();
    glFlush();
    glutPostRedisplay();
    i = i + 0.050;



}
