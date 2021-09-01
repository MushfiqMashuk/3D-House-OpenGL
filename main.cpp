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

float angle = 0;
bool keyUp = true;

void reshapeFunc(int width, int height)
{
 glViewport(0,0, width, height); // 0,0 because I want to draw the object in the centre
 glMatrixMode(GL_PROJECTION); //Matrix mode for for working with the console. we have to tell the program that, now we are working on projecting the object.
 glLoadIdentity(); // this is the reason we use Matrix or identity matrix
 gluPerspective(45.0,(double)width/(double)height, 1.00,100.0);

}


void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // have to change the Matrix mode, because now we are going to work with the object.
    glLoadIdentity();

/*
    // ambient light
    GLfloat ambColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambColor);

// light 1
    GLfloat lightCol0[] = {1.0f, 1.0f, 0.92f, 1.0f}; // last value is the intensity max-1, min-0
    GLfloat lightPos0[] = {1.0f, 2.0f, 1.0f, 1.0f}; // for position- last param is the z index. max=1, min= -1
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightCol0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    // light 2
    GLfloat lightCol1[] = {0.82f, 0.82f, 0.82f, 5.0f};
    GLfloat lightPos1[] = {10.0f, 10.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightCol1);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos1);
*/

    glTranslated(0, -4, -20);
    glRotated(angle, 0 ,1 , 0);

// 1st Door

    glPushMatrix();
        glBegin(GL_QUADS);
        glColor3f(1,0.270, 0);

          glVertex3f(1, 4, 4);
          glVertex3f(1, 1, 4);
          glVertex3f(-1, 1, 4);
          glVertex3f(-1, 4, 4);
    glEnd();
    glPopMatrix();

    // 2nd Door

    glPushMatrix();
        glBegin(GL_QUADS);
        glColor3f(1,0.270, 0);

          glVertex3f(3, 4, 1);
          glVertex3f(3, 4, -1);
          glVertex3f(3, 1, -1);
          glVertex3f(3, 1, 1);
    glEnd();
    glPopMatrix();


// left hood

    glPushMatrix();
    glColor3f(1,0.270, 0);
    glBegin(GL_QUADS);

          glVertex3f(-5, 5, -5);
          glVertex3f(0, 8.2, -4.5);
          glVertex3f(0, 8.2, 4.5);
          glVertex3f(-5, 5, 5);
    glEnd();
    glPopMatrix();

    // right hood

    glPushMatrix();
    glColor3f(1,0.270, 0);
    glBegin(GL_QUADS);

          glVertex3f(0, 8.2, -4.5);
          glVertex3f(5, 5, -5);
          glVertex3f(5,5,5);
          glVertex3f(0, 8.2, 4.5);
    glEnd();
    glPopMatrix();


// front side
    glPushMatrix();
    glColor3f(1, 0.549 , 0);
    glBegin(GL_POLYGON);

          glVertex3f(0, 8, 4);
          glVertex3f(3, 6, 4);
          glVertex3f(3, 0, 4);
          glVertex3f(-3, 0, 4);
          glVertex3f(-3, 6, 4);
    glEnd();

    glPopMatrix();


// back side
    glPushMatrix();
   glColor3f(1, 0.549 , 0);
    glBegin(GL_POLYGON);

          glVertex3f(0, 8, -4);
          glVertex3f(3, 6, -4);
          glVertex3f(3, 0, -4);
          glVertex3f(-3, 0, -4);
          glVertex3f(-3, 6, -4);
    glEnd();
    glPopMatrix();

//right side
    glPushMatrix();
    glColor3f(1, 0.549 , 0);
    glBegin(GL_QUADS);

          glVertex3f(3, 6, 4);
          glVertex3f(3, 6, -4);
          glVertex3f(3, 0,-4);
          glVertex3f(+3,+0,+4);
    glEnd();
    glPopMatrix();

// left side
    glPushMatrix();
    glColor3f(1, 0.549 , 0);
    glBegin(GL_QUADS);

          glVertex3f(-3, 6, -4);
          glVertex3f(-3, 6, 4);
          glVertex3f(-3, 0, 4);
          glVertex3f(-3, 0, -4);
    glEnd();
    glPopMatrix();


// top right side

    glPushMatrix();
    glColor3f(1, 0.549 , 0);
    glBegin(GL_QUADS);

          glVertex3f(0, 8, 4);
          glVertex3f(0, 8, -4);
          glVertex3f(3, 6, -4);
          glVertex3f(3, 6, 4);
    glEnd();
    glPopMatrix();

// top left side
    glPushMatrix();
   glColor3f(1, 0.549 , 0);
    glBegin(GL_QUADS);

          glVertex3f(0, 8, -4);
          glVertex3f(0, 8, 4);
          glVertex3f(-3, 6, 4);
          glVertex3f(-3, 6, -4);
    glEnd();
    glPopMatrix();


    glutSwapBuffers();

}

void rotateObj(){
    angle = angle + 0.1;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    switch(button){
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN && keyUp){
                glutIdleFunc(rotateObj);
                keyUp = false;
            }
            else if(state == GLUT_DOWN && !keyUp){
                glutIdleFunc(NULL);
                keyUp = true;
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_DOWN){
                glutIdleFunc(NULL);
            }
            break;
        default:
            break;
    }
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("CSE 064 07578");
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(reshapeFunc);
    //lightRendering();
    glutDisplayFunc(myDisplay);

    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}
