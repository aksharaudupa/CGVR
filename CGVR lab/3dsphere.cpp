#include<stdio.h>
#include<stdlib.h>
#include<gl/glut.h>
#include<math.h>

void sphere()
{
	double c=3.14/180,phi,x,y,z,theta;
	for(phi=-80.0;phi<80.0;phi+=5.0)
	{
		glBegin(GL_QUAD_STRIP);
		for(theta=-180.0;theta<=180.0;theta+=5.0)
		{
			x=sin(c*theta)*cos(c*phi);
			y=cos(c*theta)*cos(c*phi);
			z=sin(c*phi);
			glVertex3d(x,y,z);

			x=sin(c*theta)*cos(c*(phi+5.0));
			y=cos(c*theta)*cos(c*(phi+5.0));
			z=sin(c*(phi+5.0));
			glVertex3d(x,y,z);
		}
		glEnd();
	}

	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0.0,0.0,1.0);
	z=sin(c*80.0);
	for(theta=-180.0;theta<=180.0;theta+=5.0)
	{
		x=sin(c*theta)*cos(c*80.0);
		y=cos(c*theta)*cos(c*80.0);
		glVertex3d(x,y,z);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3d(0.0,0.0,-1.0);
	z=-sin(c*80.0);
	for(theta=-180.0;theta<=180.0;theta+=5.0)
	{
		x=sin(c*theta)*cos(c*80.0);
		y=cos(c*theta)*cos(c*80.0);
		glVertex3d(x,y,z);
	}
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-1);
	glRotatef(-90.0,1.0,1.0,1.0);
	sphere();
	glFlush();
}

void myInit()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  

{
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0,0,1.0);
	glPointSize(1.0);
	gluOrtho2D(-1,1,-1,1);
}

void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("3d sphere");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}