#include <windows.h>
#include <GL/glut.h>
#include <math.h>
void inicio()
{
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-100,100,-100,100);
glClearColor(1.0,1.0,1.0,1.0);
}
void pantalla()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
GLUquadricObj *pt;
pt=gluNewQuadric();
gluQuadricDrawStyle(pt,GLU_LINE);
glColor3f (1.0, 0.0, 0.0);
gluPartialDisk(pt, 40, 90, 15, 6, 0, 90);
glFlush();
}
int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitWindowSize(680,480);
glutInitWindowPosition(10,10);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutCreateWindow("Disco hueco");
inicio();
glutDisplayFunc(pantalla);
glutMainLoop();
return EXIT_SUCCESS;
}