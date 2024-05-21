//Dibuja un pentagono con la función GL_POLYGON y relleno amarillo

#include<GL/glut.h>

void inicio()
{
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-50,150,-50,150);
glClearColor(0.0,0.0,0.0,0.0);
}
void pantalla()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
    glVertex2f(30,0);
    glVertex2f(0,50);
    glVertex2f(45,100);
    glVertex2f(90,50);
    glVertex2f(60,0);
glEnd();
glFlush();
}
int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitWindowSize(680,480);
glutInitWindowPosition(10,10);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutCreateWindow("Pentagono con la primitiva GL_POLYGON y relleno amarillo");
inicio();
glutDisplayFunc(pantalla);
glutMainLoop();
return EXIT_SUCCESS;
}