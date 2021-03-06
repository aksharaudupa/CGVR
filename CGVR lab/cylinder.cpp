#include <GL/glut.h>
#include<stdio.h>
void draw_pixel(GLint cx, GLint cy)
{
glBegin(GL_POINTS);
glVertex2i(cx,cy);
glEnd();
}
void plotpixels(GLint h, GLint k, GLint x, GLint y)
{
//glColor3f(1.0,0.0,0.0);
draw_pixel(x+h,y+k);
draw_pixel(y+h,x+k);

//glColor3f(0.0,1.0,0.0);
draw_pixel(-x+h,y+k);
draw_pixel(-y+h,x+k);

//glColor3f(0.0,0.0,1.0);
draw_pixel(x+h,-y+k);
draw_pixel(y+h,-x+k);


//glColor3f(1.0,1.0,0.0);
draw_pixel(-x+h,-y+k);
draw_pixel(-y+h,-x+k);
}
void Circle_draw(GLint h, GLint k, GLint r) // Midpoint Circle Drawing Algorithm
{
GLint d = 1-r, x=0, y=r;
while(y > x)
 {
plotpixels(h,k,x,y);
if(d < 0)
 d+=2*x+3;
else
 {
 d+=2*(x-y)+5;
 --y;
 }
 ++x;
 }
plotpixels(h,k,x,y);
}
void Cylinder_draw()
{
GLint xc=100, yc=100, r=50, i,n=50;
glColor3f(0.0,0.0,1.0);
Circle_draw(xc,yc,r);
for(i=1;i<n;i+=3){
	glColor3f(1.0,0.0,0.0);
Circle_draw(xc,yc+i,r);
}
glColor3f(0.0,1.0,0.0);
Circle_draw(xc,yc+i,r);
}
void parallelepiped(int x1,int x2,int y1,int y2)
{
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_LINE_LOOP);
 glVertex2i(x1,y1);
glVertex2i(x2,y1);
glVertex2i(x2,y2);
glVertex2i(x1,y2);
glEnd();
}
void parallelepiped_draw()
{
int x1=200,x2=300,y1=100,y2=175, i, n=40;
for(i=0;i<n;i+=2)
parallelepiped(x1+i,x2+i,y1+i,y2+i);
}
void init(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,400.0,0.0,300.0);
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
Cylinder_draw();
parallelepiped_draw();
glFlush();
}

void mouseFuncCylinder(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		display();
		//glutDisplayFunc(display);
	}
}

void drawingCircle(){}

void main(int argc, char **argv)
{
	int choice;
	printf("Enter 1 for mouse,2 for keyboard\n");
	scanf("%d",&choice);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(400,300); 
glutCreateWindow("Cylinder,parallelePiped Disp by Extruding Circle &Quadrilaterl ");
init();

switch(choice)
	{
	case 1:
		{
			glutMouseFunc(mouseFuncCylinder);
			glutDisplayFunc(drawingCircle);
			//myInit();
			break;
		}
	case 2:
		{
			char ch;
			printf("Enter key to draw\n");
			scanf("%s",&ch);
			if(ch=='D')
			glutDisplayFunc(display);
			else printf("Wrong input");
			break;
		}
	default: break;
	}
//glutDisplayFunc(display);
glutMainLoop();
}
