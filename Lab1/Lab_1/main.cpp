
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
    glRotatef((GLfloat)i,1,1,1); //i = angle, Rotate with respect to (0,0,0) to (1,1,1)

    glColor3f(1.0,1.0,1.0);

    glBegin(GL_LINES);
        glColor3f(1,0,0);

            glVertex2f(0.0,0.0);
            glVertex2f(-0.1, 0.5);

            glVertex2f(-0.1, 0.5);
            glVertex2f(0.0, 1.0);

            glVertex2f(0.0, 1.0);
            glVertex2f(0.1,0.5);

            glVertex2f(0.1,0.5);
            glVertex2f(0.0, 0.0);



            glVertex2f(0.0,0.0);
            glVertex2f(0.5, 0.1);

            glVertex2f(0.5, 0.1);
            glVertex2f(1.0, 0.0);

            glVertex2f(1.0, 0.0);
            glVertex2f(0.5, -0.1);

            glVertex2f(0.5, -0.1);
            glVertex2f(0.0, 0.0);


            glVertex2f(0.0,0.0);
            glVertex2f(-0.5, -0.1);

            glVertex2f(-0.5, -0.1);
            glVertex2f(-1.0, 0.0);

            glVertex2f(-1.0, 0.0);
            glVertex2f(-0.5,0.1);

            glVertex2f(-0.5,0.1);
            glVertex2f(0.0, 0.0);



            glVertex2f(0.0,0.0);
            glVertex2f(0.1, -0.5);

            glVertex2f(0.1, -0.5);
            glVertex2f(0.0, -1.0);

            glVertex2f(0.0, -1.0);
            glVertex2f(-0.1, -0.5);

            glVertex2f(-0.1, -0.5);
            glVertex2f(0.0, 0.0);

            glVertex2f(1.0, 0.0);
            glVertex2f(-1.0, 0.0);

            glVertex2f(0, 1.0);
            glVertex2f(0, -1.0);

    glEnd();
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
    i+=0.06;

}
