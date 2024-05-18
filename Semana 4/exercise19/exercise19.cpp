//Dibujando 3 lineas con GL_LINES

#include<GL/glut.h>

void inicio()
{
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-50, 120, -50, 120); 
glClearColor(0.0,0.0,0.0,0.0);
}
void pantalla()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,1.0,1.0);
glLineWidth(3.0);

glBegin(GL_LINES);
    glVertex3f(0.0, 20.0, 0.0);
    glVertex3f(50.0, 50.0, 0.0);
glEnd();

glBegin(GL_LINES);
    glVertex3f(60.0, 40.0, 0.0);
    glVertex3f(60.0, 0.0, 0.0);
glEnd();

glBegin(GL_LINES);
    glVertex3f(30.0, 10.0, 0.0);
    glVertex3f(80.0, 35.0, 0.0);
glEnd();

glFlush();
}
int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitWindowSize(680,480);
glutInitWindowPosition(10,10);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutCreateWindow("Dibujo obtenido con la funcion GL_LINES");
inicio();
glutDisplayFunc(pantalla);
glutMainLoop();
return EXIT_SUCCESS;
}