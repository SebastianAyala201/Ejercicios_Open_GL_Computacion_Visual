//Cuadrilátero dibujado con la función GL_QUAD_STRIP, la cual permite unir varios cuadriláteros

#include <GL/glut.h>

void inicio()
{
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-40,150,-60,150);
glClearColor(1.0,1.0,1.0,0.0);
}
void pantalla()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,1.0,0.0); //Color amarillo

glBegin(GL_QUAD_STRIP);
    glVertex2f(0,0);
    glVertex2f(0,100);
    glVertex2f(50,0);
    glVertex2f(50,100);
    glVertex2f(100,0);
    glVertex2f(100,100);
glEnd();

glColor3f(0.0,0.0,0.0); //Colocando lineas para separar los cuadrilateros
glBegin(GL_LINE_LOOP);
    glVertex2f(0,0);
    glVertex2f(0,100);
    glVertex2f(50,100);
    glVertex2f(50,0);
glEnd();

glBegin(GL_LINE_STRIP);
    glVertex2f(50,100);
    glVertex2f(100,100);
    glVertex2f(100,0);
    glVertex2f(50,0);
glEnd();

glFlush();
}
int main(int argc, char *argv[])
{


glutInit(&argc, argv);
glutInitWindowSize(680,480);
glutInitWindowPosition(10,10);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutCreateWindow("2 Cuadrilateros graficados con funcion QUAD_STRIP y relleno amarillo");
inicio();
glutDisplayFunc(pantalla);
glutMainLoop();
return EXIT_SUCCESS;
}