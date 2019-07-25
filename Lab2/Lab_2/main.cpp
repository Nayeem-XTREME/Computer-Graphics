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

float points[4][2];
int n;
int flag = 1;

bool mat[9];

void drawO(float x, float y)
{
    float r = 0.12;
    float p1, p2, q1, q2;

    glBegin(GL_LINES);
    glColor3f(1,0,0);

    p1 = x + r*cos(0.0);
    q1 = y + r*sin(0.0);

    for (float i = 1; i <= 360; i++) {
        p2 = x + r*cos(i);
        q2 = y + r*sin(i);

        glVertex2f(p1, q1);
        glVertex2f(p2, q2);

        p1 = p2;
        q1 = q2;
    }

    glEnd();
    glFlush();
    //glutSwapBuffers();
}

void drawX(float x, float y)
{
    glBegin(GL_LINES);
        glColor3f(1,0,0);

        glVertex2f(x-0.1, y-0.1);
        glVertex2f(x+0.1, y+0.1);

        glVertex2f(x+0.1, y-0.1);
        glVertex2f(x-0.1, y+0.1);

    glEnd();
    glFlush();
    //glutSwapBuffers();
}

void display();
void keyboard(unsigned char key, int x, int y)
{
    cout << key << endl;

    if (flag == 1) {
        if (key == '1') {
            drawO((-1-0.4)/2, (1+0.4)/2);
            //mat[0] = true;
        }
        else if (key == '2' && mat[1] == false) {
            drawO(0, (1+0.4)/2);
            //mat[1] = true;
        }
        else if (key == '3' && mat[2] == false) {
            drawO((1+0.4)/2, (1+0.4)/2);
            //mat[2] = true;
        }
        else if (key == '4' && mat[3] == false) {
            drawO((-1-0.4)/2, 0);
            //mat[3] = true;
        }
        else if (key == '5' && mat[4] == false) {
            drawO(0, 0);
            //mat[4] = true;
        }
        else if (key == '6' && mat[5] == false) {
            drawO((0.4+1)/2, 0);
            //mat[5] = true;
        }
        else if (key == '7' && mat[6] == false) {
            drawO((-1-0.4)/2, (-1-0.4)/2);
            //mat[6] = true;
        }
        else if (key == '8' && mat[7] == false) {
            drawO(0, (-1-0.4)/2);
            //mat[7] = true;
        }
        else if (key == '9' && mat[8] == false) {
            drawO((1+0.4)/2, (-1-0.4)/2);
            //mat[8] = true;
        }

        flag = flag*(-1);
    }

    else if (flag == -1 && mat[0] == false) {
        if (key == '1') {
            drawX((-1-0.4)/2, (1+0.4)/2);
            //mat[0] = true;
        }
        else if (key == '2' && mat[1] == false) {
            drawX(0, (1+0.4)/2);
            //mat[1] = true;
        }
        else if (key == '3' && mat[2] == false) {
            drawX((1+0.4)/2, (1+0.4)/2);
            //mat[2] = true;
        }
        else if (key == '4' && mat[3] == false) {
            drawX((-1-0.4)/2, 0);
            //mat[3] = true;
        }
        else if (key == '5' && mat[4] == false) {
            drawX(0, 0);
            //mat[4] = true;
        }
        else if (key == '6' && mat[5] == false) {
            drawX((0.4+1)/2, 0);
            //mat[5] = true;
        }
        else if (key == '7' && mat[6] == false) {
            drawX((-1-0.4)/2, (-1-0.4)/2);
            //mat[6] = true;
        }
        else if (key == '8' && mat[7] == false) {
            drawX(0, (-1-0.4)/2);
            //mat[7] = true;
        }
        else if (key == '9' && mat[8] == false) {
            drawX((1+0.4)/2, (-1-0.4)/2);
            //mat[8] = true;
        }

        flag = flag*(-1);
    }


}

int main(int argc,char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutCreateWindow("Second");
    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);
    glutIdleFunc(display);

    glutMainLoop();
}

void display()
{

    glBegin(GL_LINES);
        glColor3f(1,0,0);

            glVertex2f(1, 0.4);
            glVertex2f(-1, 0.4);

            glVertex2f(1, -0.4);
            glVertex2f(-1, -0.4);

            glVertex2f(0.4, 1);
            glVertex2f(0.4, -1);

            glVertex2f(-0.4, 1);
            glVertex2f(-0.4, -1);


    glEnd();
    glFlush();


    points[0][0] = 0.4, points[0][1] = 0.4;
    points[1][0] = -0.4, points[1][1] = 0.4;
    points[2][0] = -0.4, points[2][1] = -0.4;
    points[3][0] = 0.4, points[3][1] = -0.4;

}

//Pending........... COMPLETE THE GAME!
