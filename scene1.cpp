/*
 * Elize Geldenhuys
 * Scene 1
 * CG Spring 2017
 *
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
const int screenHeight = 480; //sets screen height to 480 px
const int screenWidth = 640; //sets screen width to 640px

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); //makes the window background white
    glEnable(GL_DEPTH_TEST);
    glColor3f(0.0f, 0.0f, 0.0f); //makes the generated color black
    glPointSize(10.0); //point size is 10x10 px
    glLineWidth(4.0); //line width is 4px
    glMatrixMode(GL_PROJECTION); //enables camera changes
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //sets the camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);
}

//creates the point
void point(void)
{
    glClear(GL_COLOR_BUFFER_BIT); //Clears the window

    //uses the primitive of point to create the point
    glBegin(GL_POINTS);
        glVertex2f(0,0);
    glEnd();
    glFlush();
}

//creates the line
void line(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //uses the primitive of linestip
    glBegin(GL_LINES);
        glVertex2f(-.5,0);
        glVertex2f(.5, 0);
    glEnd();
    glFlush();
}

//creates the triangle
void triangle(void)
{
    glClear(GL_COLOR_BUFFER_BIT); //clears the window

    //uses the primitive of triangle to create the shape
    glBegin(GL_TRIANGLES);
        glVertex2f(-.25, 0);
        glVertex2f(.25, 0);
        glVertex2f(0, .5);
    glEnd();
    glFlush();
}

//creates the square
void square(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
        glVertex2f(-.25, .25);
        glVertex2f(.25, .25);
        glVertex2f(.25, -.25);
        glVertex2f(-.25, -.25);
    glEnd();
    glFlush();

}

//creates the hexagon
void hexagon(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
        glVertex2f(.25, -.25);
        glVertex2f(.5, -.5);
        glVertex2f(.25, -.75);
        glVertex2f(-.25, -.75);
        glVertex2f(-.5, -.5);
        glVertex2f(-.25, -.25);
    glEnd();
    glFlush();
}

//creates the circle
void circle(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    const static int n = 50;
    const static GLfloat R = 0.5f;
    const static GLfloat Pi = 3.14159;

    glBegin(GL_POLYGON);
        for(int i = 0; i < n; i++)
        {
            glVertex2f(R*cos(2*Pi/n*i), R*sin(2*Pi/n*i));
        }

    glEnd();
    glFlush();
}

//creats the cube
void cube(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    #define Edge 2
 
    GLfloat point1[] = {0, 0, 0};
    GLfloat point2[] = {Edge, 0, 0};
    GLfloat point3[] = {Edge, Edge, 0};
    GLfloat point4[] = {0, Edge, 0};
    GLfloat point5[] = {0, 0, Edge};
    GLfloat point6[] = {Edge, 0, Edge};
    GLfloat point7[] = {Edge, Edge, Edge};
    GLfloat point8[] = {0, Edge, Edge};


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0f, 1, 1, 20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5, 5, 10, 0, 0, 0, 0, 1, 0);

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 1.0f, 0.0f); //sets color to green
        glVertex3fv(point1);
        glVertex3fv(point2);
        glVertex3fv(point3);
        glVertex3fv(point4);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3fv(point2);
        glVertex3fv(point3);
        glVertex3fv(point7);
        glVertex3fv(point6);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 0.0f, 0.); //sets color to red
        glVertex3fv(point3);
        glVertex3fv(point4);
        glVertex3fv(point8);
        glVertex3fv(point7);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3fv(point1);
        glVertex3fv(point4);
        glVertex3fv(point8);
        glVertex3fv(point5);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3fv(point5);
        glVertex3fv(point6);
        glVertex3fv(point7);
        glVertex3fv(point8);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3fv(point1);
        glVertex3fv(point5);
        glVertex3fv(point6);
        glVertex3fv(point2);
    glEnd();

    glFlush();
}

//Keyboard entry
void makeShape(unsigned char key, int mouseX, int mouseY)
{
    switch(key)
    {
        case 'p':
        case 'P':
            point();
        break;
        case 'l':
        case 'L':
            line();
        break;
        case 't':
        case 'T':
            triangle();
        break;
        case 's':
        case 'S':
            square();
        break;
        case 'h':
        case 'H':
            hexagon();
        break;
        case 'c':
        case 'C':
            circle();
        break;
        case 'u':
        case 'U':
            {
                cube();
                myInit();
            }
        break;
        case 'q':
        case 'Q':
            exit(-1);
        default:
        break;
    }
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

}

//Main Function
int main(int argc, char** argv)
{
    glutInit(&argc, argv); //initializes
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //sets parameters
    glutInitWindowSize(screenWidth, screenHeight); //sets window size
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Elize Geldenhuys - Scene 1"); //Titles the window
    //Calls for keyboard entry
    glutDisplayFunc(myDisplay);
        glutKeyboardFunc(makeShape);
    myInit(); //initializes my parameters
    glutMainLoop(); //infinite loop awaiting event
}

