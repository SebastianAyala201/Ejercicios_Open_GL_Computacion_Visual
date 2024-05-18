//Dibuja un corazon con fondo rosado y relleno rojo

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
glColor3f(1.0,0.0,1.0);
glBegin(GL_POLYGON);
glVertex3f(30.0,0.0,0.0);
glVertex3f(10.0,20.0,0.0);
glVertex3f(0.0,30.0,0.0);
glVertex3f(0.0,50.0,0.0);
glVertex3f(10.0,60.0,0.0);
glVertex3f(20.0,60.0,0.0);
glVertex3f(30.0,50.0,0.0);

glVertex3f(40.0,60.0,0.0);
glVertex3f(50.0,60.0,0.0);
glVertex3f(60.0,50.0,0.0);
glVertex3f(60.0,30.0,0.0);
glVertex3f(50.0,20.0,0.0);
glEnd();

// Dibujar la cadena de texto "Feliz día mamá" debajo del corazón
    glRasterPos2f(0.0, -20.0); // Posición de la cadena de texto
    glColor3f(1.0, 0.0, 1.0); // Color del texto (negro)
    const char* texto = "          Feliz dia mama";
    for (int i = 0; texto[i] != '\0'; ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, texto[i]); // Renderizar cada carácter
    }



glFlush();
}
int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitWindowSize(680,480);
glutInitWindowPosition(10,10);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutCreateWindow("Feliz dia mama");
inicio();
glutDisplayFunc(pantalla);
glutMainLoop();
return EXIT_SUCCESS;
}