#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<windows.h>
#include<gl/glut.h>

int m,n;
int wx=500,wy=500;
static float intx[10]={0};
float x[100],y[100];
using namespace std;

void drawLine(float x1,float y1,float x2,float y2)
{
	Sleep(100);
	glColor3f(0,0,1);
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
	glFlush();
}

void edgeDetect(float x1,float y1,float x2,float y2,int scanline)
{
	float temp;
	if(y2<y1)
	{
		temp=x1;x1=x2;x2=temp;
		temp=y1;y1=y2;y2=temp;
	}
	if(scanline>y1 && scanline<y2)
		intx[m++] =x1+(scanline-y1)*(x2-x2)/(y2-y1);
}

void scanFill(float x[],float y[])
{
	for(int s1=0;s1<=wy;s1++)
	{
		m=0;
		for(int i=0;i<n;i++)
			edgeDetect(x[i],y[i],x[(i+1)%n],y[(i+1)%n],s1);
		sort(intx,(intx+m));
		if(m>=2)
			for(int i=0;i<m;i+=2)
				drawLine(intx[i],s1,intx[i+1],s1);
	}
}

void myInit()
{
	glClearColor(1,1,1,1);
	glColor3f(0,0,1);
	glPointSize(1);
	gluOrtho2D(0,wx,0,wy);
}

void displayFilledPolygon()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<n;i++)
		glVertex2f(x[i],y[i]);
	glEnd();
	scanFill(x,y);
}

void main(int argc, char **argv)
{
	printf("Enter no of sides\n");
	scanf("%d",&n);
	printf("Enter coord of vertices\n");
	for(int i=0;i<n;i++)
	{
		printf("X  , Y  ");
		scanf("%f %f",&x[i],&y[i]);
	}
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500,500); 
glutCreateWindow("Scanline fill");
myInit();
glutMainLoop();
}