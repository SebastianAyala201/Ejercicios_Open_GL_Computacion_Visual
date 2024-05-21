// Dibujando 4 lineas con GL_LINE_STRIP

#include<GL/glut.h>

void inicio()
{
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0, 80, 0, 80); 
glClearColor(0.0, 0.0, 0.0, 0.0);
}
void pantalla()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,1.0);
glLineWidth(3.0);

glBegin(GL_LINE_STRIP);
    glVertex3f(30.0, 60.0, 0.0);
    glVertex3f(20.0, 30.0, 0.0);
    glVertex3f(60.0, 50.0, 0.0);
    glVertex3f(60.0, 20.0, 0.0);
    glVertex3f(40.0, 45.0, 0.0);
glEnd();
glFlush();
}
int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitWindowSize(680,480);
glutInitWindowPosition(10,10);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutCreateWindow("Lineas dibujadas con la funcion GL_LINE_STRIP");
inicio();
glutDisplayFunc(pantalla);
glutMainLoop();
return EXIT_SUCCESS;
}