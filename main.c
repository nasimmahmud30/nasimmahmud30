#include <GL/gl.h>
#include <GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y1,y2;
void display(void)
{
glColor3ub (255, 255, 255);
glBegin(GL_LINES);
glVertex2d(-1000,0);
glVertex2d(1000,0);
glVertex2d(0,-1000);
glVertex2d(0,1000);
glEnd();
float dy,dx,x,y,i,p;
dx=x2-x1;
dy=y2-y1;
p= ((2*dy) - dx);
x=x1;
y=y1;
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
for (i=0 ; i<dx; i++)
{
if(p<0)
{
x = x+1;
p = (p+(2*dy));
}
else
{
x = x+1;
y = y+1;
p = (p+(2*dy)-(2*dx));
}
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
glFlush();
}
void init(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-1000,1000,-1000,1000);
}
int main(int argc, char** argv)
{
printf("Enter The Value of X1 : ");
scanf("%f",&x1);
printf("Enter The Value of Y1 : ");
scanf("%f",&y1);
printf("Enter The Value of X2 : ");
scanf("%f",&x2);
printf("Enter The Value of Y2 : ");
scanf("%f",&y2);
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("Bresenham's Line Algorithm ID_182-15-11381");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
