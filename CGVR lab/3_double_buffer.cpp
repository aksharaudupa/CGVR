#include<gl/glut.h>
#include<stdio.h>
float wid1,wid2,t;
void initgl();
void display1(void);
void mouse1(int button,int state,int x,int y);
void spindisplay(void);
static GLfloat spin=0.0;
void main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitWindowSize(500,500);
  wid1=glutCreateWindow("Single\n");
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutDisplayFunc(display1);
  glutMouseFunc(mouse1);
  glutInitWindowSize(500,500);
  wid1=glutCreateWindow("Double\n");
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
  t=wid1;
  glutDisplayFunc(display1);
  glutMouseFunc(mouse1);
  initgl();
  glutMainLoop();
}
void initgl()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
  glClearColor(1.0,1.0,1.0,1.0);
  glColor3f(1.0,0.0,0.0);
}
void display1()
{
  glutSetWindow(t);
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glLoadIdentity();
  glRotatef(spin,0.0,0.0,1.0);
  glBegin(GL_POLYGON);
  glVertex3f(-0.25,-0.25,0.25);
   glVertex3f(0.25,-0.25,0.25);
  glVertex3f(0.25,0.25,0.25);
  glVertex3f(-0.25,0.25,0.25);
  glEnd();
  glPopMatrix();
  if(t==wid1){
    glFlush();
    t=wid2;}
  else{
    glutSwapBuffers();
    t=wid1;
  }}
void spinDisplay(void){
    spin+=0.02;
    glutPostRedisplay();
  }
  void mouse1(int button, int state, int x, int y)
  {
    switch(button)
    {
    case GLUT_LEFT_BUTTON: {if(state==GLUT_DOWN)
                             glutIdleFunc(spinDisplay);
      break;}
    case GLUT_RIGHT_BUTTON: {if(state==GLUT_DOWN)
                             glutIdleFunc(NULL);
      break;}
    default : break;
    }
  }
