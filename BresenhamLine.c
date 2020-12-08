#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
int x1,y1,x2,y2;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void init()
{
glClearColor(0.7,0.7,0.7,0.7);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-20,20,-20,20);
}
void display()
{
float x,y,dx,dy,m,b;
dy=y2-y1;
dx=x2-x1;
m=dy/dx;
b=y1-m*x1;
x=x1;
y=y1;
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2i(-20,0);
glVertex2i(20,0);
glEnd();
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2i(0,-20);
glVertex2i(0,20);
glEnd();
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2i(x,y);
int p0=2*dy-dx;
while(x<=x2)
{
	x=x+1;
	if(p0<0)
	{
		p0=p0+2*dy;
	}
	else
	{
		p0=p0+2*dy-2*dx;
		y++;
	}
}
glVertex2i(x,y);
glEnd();
glFlush();
}
int main(int argc, char *argv[]) 
{
printf("Enter the value of x1:");
scanf("%d",&x1);
printf("Enter the value of y1:");
scanf("%d",&y1);
printf("Enter the value of x2:");
scanf("%d",&x2);
printf("Enter the value of y2:");
scanf("%d",&y2);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
glutInitWindowSize(500,500);
glutInitWindowPosition(200,100);
glutCreateWindow("Bresenham's line Algorithm");
init();
glutDisplayFunc(display);
glutMainLoop();
}
