#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>
float xc,yc,a,b; //xc and yc are centres and a and b are the major and minor radius respectively.
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void putpixel(int x,int y)
{
  glPointSize(5.0);
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc-x, yc-y);
  glVertex2i(xc-x, yc+y);
  glEnd();
}
void display()
{
	float x,y;
	x=0;
	y=b;
	float p10=(2*b*b)/(a*a)-2*b+1;
	float px=0;
	float py=2*a*a*y;
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
	while(px<py)
	{
		x++;
		px=px+2*b*b;
		if(p10<0)
		{
			p10=p10+(b*b*(4*x+6))/(a*a);
		}
		else
		{
			p10=p10+(b*b*(4*x+6))/(a*a)-4*y+4;
			y--;
			py=py-2*a*a;
		}
		putpixel(x,y);
	}
	float p20=2*a*a*(1-((y-1)*(y-1))/(b*b))-x*x-(x+1)*(x+1);
	while(y>0)
	{
		y--;
		py=py-2*a*a;
		if(p20<0)
		{
			x++;
			p20=p20+(a*a*(4*y-6))/(b*b)+4*x-4;
			
			px=px+2*b*b;
		}
		else
		{
			
			
			p20=p20+(a*a*(4*y-6))/(b*b);
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
	scanf("%f %f",&xc,&yc);
	printf("Enter the major and minor radius of the circle:");
	scanf("%f %f",&a,&b);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(200,100);
	glutCreateWindow("Jalaj Dwivedi(R103218210):-Breseham's Ellipse");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
