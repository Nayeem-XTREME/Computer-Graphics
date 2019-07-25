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
    glRotatef((GLfloat)i,1,1,1);

    glColor3f(1.0,1.0,1.0);


    glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-0.7, -0.3);
        glVertex2f(-0.7, 0.3);

        glVertex2f(-0.7, 0.3);
        glVertex2f(-0.5, -0.3);

        glVertex2f(-0.5, -0.3);
        glVertex2f(-0.5, 0.3);

        glVertex2f(-0.45, -0.3);
        glVertex2f(-0.4, 0.3);

        glVertex2f(-0.4, 0.3);
        glVertex2f(-0.35, -0.3);

        glVertex2f(-0.425, 0);
        glVertex2f(-0.375, 0);

        glVertex2f(-0.35, 0.3);
        glVertex2f(-0.25, 0);

        glVertex2f(-0.25, 0);
        glVertex2f(-0.15, 0.3);

        glVertex2f(-0.25, 0);
        glVertex2f(-0.25, -0.3);

        glVertex2f(-0.1, 0.3);
        glVertex2f(-0.1, -0.3);

        glVertex2f(-0.1, 0.3);
        glVertex2f(0.05, 0.3);

        glVertex2f(-0.1, -0.3);
        glVertex2f(0.05, -0.3);

        glVertex2f(-0.1, 0);
        glVertex2f(0.05, 0);

        glVertex2f(0.1, 0.3);
        glVertex2f(0.1, -0.3);

        glVertex2f(0.1, 0.3);
        glVertex2f(0.25, 0.3);

        glVertex2f(0.1, -0.3);
        glVertex2f(0.25, -0.3);

        glVertex2f(0.1, 0);
        glVertex2f(0.25, 0);

        glVertex2f(0.3, -0.3);
        glVertex2f(0.3, 0.3);

        glVertex2f(0.3, 0.3);
        glVertex2f(0.4, 0);

        glVertex2f(0.4, 0);
        glVertex2f(0.5, 0.3);

        glVertex2f(0.5, 0.3);
        glVertex2f(0.5, -0.3);


    glEnd();
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
    i = i + 0.050;

}
