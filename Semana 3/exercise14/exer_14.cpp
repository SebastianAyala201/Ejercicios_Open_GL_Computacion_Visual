//Dibuja un polígono con la función GL_POLYGON y relleno amarillo

#include<GL/glut.h>

void inicio()
{
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-60,100,-80,100);
glClearColor(0.0,0.0,0.0,0.0);
}
void pantalla()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex3f(10.0,0.0,0.0);
glVertex3f(30.0,0.0,0.0);
glVertex3f(40.0,20.0,0.0);
glVertex3f(20.0,40.0,0.0);
glVertex3f(0.0,20.0,0.0);
glEnd();
glFlush();
}
int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitWindowSize(680,480);
glutInitWindowPosition(10,10);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutCreateWindow("Poligono de cinco lados con la primitiva GL_POLYGON y relleno amarillo");
inicio();
glutDisplayFunc(pantalla);
glutMainLoop();
return EXIT_SUCCESS;
}