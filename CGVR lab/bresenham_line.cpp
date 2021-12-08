//#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<gl/glut.h>
#include<math.h>

//using namespace std;

int x1,x2,yc1,y2,flag=0;

void myInit()                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  

{
	glClearColor(1.0,1.0,1.0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-250,250,-250,250);
}

void drawPixel(int x,int y)
{
	glColor3f(0,0,1);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

void drawLine()
{
	int dx,dy,i,e;
	int incx=1,incy=1,inc1,inc2;
	int x,y;
	dx=x2-x1;
	dy=y2-yc1;
	if(dx==0)
	{
		for(i=0;i<=dy;i++)
			drawPixel(x1,yc1+i);
		return;
	}
	if(dy==0)
	{
		for(i=0;i<=dx;i++)
			drawPixel(x1+i,yc1);
		return;
	}
	if(dx<0)
		dx=-dx;
	if(dy<0)
		dy=-dy;
	if(x2<x1)
		incx=-1;
	if(y2<yc1)
		incy=-1;
	x=x1;
	y=yc1;
	if(dx>dy)
	{
		drawPixel(x,y);
		e=2*dy-dx;
		inc1=2*(dy-dx);
		inc2=2*dy;
		for(i=0;i<dx;i++)
		{
			if(e>0)
			{
				y+=incy;
				e+=inc1;
			}
			else
				e+=inc2;
			x+=incx;
			drawPixel(x,y);
		}
	}
	else
	{
		drawPixel(x,y);
		e=2*dx-dy;
		inc1=2*(dx-dy);
		inc2=2*dx;
		for(i=0;i<dy;i++)
		{
			if(e>0)
			{
				x+=incx;
				e+=inc1;
			}
			else
				e+=inc2;
			y+=incy;
			drawPixel(x,y);
		}
	}
	glFlush();
}



void mouseFunc(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		if(flag==0)
		{
			printf("x1,y1:");
			x1=x-250;
			yc1=250-y;
			flag++;
			printf("%d,%d\n",x1,yc1);
		}
		else
		{
			printf("x2,y2:");
			x2=x-250;
			y2=250-y;
			flag=0;
			printf("%d,%d\n",x2,y2);
			drawLine();
		}
	}
}

void display() {}

void main(int argc,char *argv[])
{
	int choice;
	printf("Enter 1 for keyboard,2 for mouse\n");
	scanf("%d",&choice);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,200);
	glutCreateWindow("Bresenham line drawing");
	myInit();

	if(choice==2)
		glutMouseFunc(mouseFunc);
	if(choice==1)
	{
		printf("enter x1:");
		scanf("%d",&x1);
		printf("enter y1:");
		scanf("%d",&yc1);
		printf("enter x2:");
		scanf("%d",&x2);
		printf("enter y2:");
		scanf("%d",&y2);
		printf("line:%d,%d to %d,%d\n",x1,yc1,x2,y2);
		drawLine();
	}
	glutDisplayFunc(display);
	glutMainLoop();
}