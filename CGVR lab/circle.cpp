#include<stdio.h>
#include<stdlib.h>
#include<gl/glut.h>
#include<math.h>

//using namespace std;

int xc,yc,r;
int p1_x,p1_y,p2_x,p2_y;
int point1_done=0;

void drawCircle(int xc,int yc,int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(xc+x,yc+y);
	glVertex2i(xc-x,yc+y);
	glVertex2i(xc+x,yc-y);
	glVertex2i(xc-x,yc-y);
	glVertex2i(xc+y,yc+x);
	glVertex2i(xc-y,yc+x);
	glVertex2i(xc+y,yc-x);
	glVertex2i(xc-y,yc-x);
	glEnd();
}

void circleBres()
{
	glClear(GL_COLOR_BUFFER_BIT);
	int x=0,y=r;
	int d=3-2*r;
	while(x<=y)
	{
		drawCircle(xc,yc,x,y);
		x++;
		if(d<0)
			d=d+ 4*x +6;
		else{
			y--;
			d=d+ 4*(x-y) +10;
		}
		drawCircle(xc,yc,x,y);
	}
	glFlush();
}

void mouseFuncCircle(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && point1_done==0)
	{
		p1_x=x-250;
		p1_y=250-y;
		point1_done=1;
	}
	else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		float exp;
		p2_x=x-250;
		p2_y=250-y;
		xc=p1_x;
		yc=p1_y;
		exp=(p2_x-p1_x)*(p2_x-p1_x) + (p2_y-p1_y)*(p2_y-p1_y);
		r=(int)(exp);
		circleBres();
		point1_done=0;
	}
}

void drawingCircle(){}

void myInit()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  

{
	glClearColor(1.0,1.0,1.0,1.0);
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,1.0,0.0);
	glPointSize(3.0);
	gluOrtho2D(-250,250,-250,250);
}


void display() {}

void main(int argc,char *argv[])
{
	int choice;
	printf("Enter 1 for mouse,2 for keyboard\n");
	scanf("%d",&choice);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Bresenham line drawing circle and ellipse");
	myInit();

	switch(choice)
	{
	case 1:
		{
			glutMouseFunc(mouseFuncCircle);
			glutDisplayFunc(drawingCircle);
			myInit();
			break;
		}
	case 2:
		{
			printf("Enter coordinates of center of circle and radius\n");
			scanf("%d %d %d",&xc,&yc,&r);
			glutDisplayFunc(circleBres);
			break;
		}
	default: break;
	}
	myInit();
	glutMainLoop();
}