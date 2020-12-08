#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>
int xc,yc,r;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void putpixel(int x,int y)
{
  glPointSize(5.0);
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);
  glVertex2i(xc-x, yc-y);
  glVertex2i(xc-y, yc-x);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc-y, yc+x);
  glEnd();
}
void display()
{
	int x,y;
	x=0;
	y=r;
	int p0=3-2*r;
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
	putpixel(x,y);
	while(x<=y)
	{
		x++;
		if(p0<0)
		{
			p0=p0+4*x+6;
		}
		else
		{
			p0=p0+4*x-4*y+10;
			y--;
		}
		putpixel(x,y);
	}
	glFlush();
}
void init()
{
	glClearColor(0.7,0.7,0.7,0.7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20,20,-20,20);
}
int main(int argc, char *argv[]) {
	printf("Enter the coordinates of the circle's centre:");
	scanf("%d %d",&xc,&yc);
	printf("Enter the radius of the circle:");
	scanf("%d",&r);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(200,100);
	glutCreateWindow("Bresenham's Circle");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
