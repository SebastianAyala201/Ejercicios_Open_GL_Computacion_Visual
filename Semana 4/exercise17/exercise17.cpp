// Dibujando dos secuencias de lineas que se entrecruzan con GL_LINE_STRIP

#include <GL/glut.h>

void inicio()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-60, 180, -60, 110);
    glClearColor(1.0, 0.5, 0.0, 0.0);
}

void pantalla()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(5.0);

    double limInf = 0.0, limSup = 20.0;

    for(int i=1;i<=6;i++){
        glBegin(GL_LINE_STRIP);
            glVertex3f(limInf, 50.0 , 0.0); 
            glVertex3f(limSup, 0.0, 0.0);
        glEnd();
        glBegin(GL_LINE_STRIP);
            glVertex3f(limSup, 50.0 , 0.0); 
            glVertex3f(limInf, 0.0, 0.0);
        glEnd();
        limSup += 20;
        limInf += 20;
    }

    glFlush();

}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Lineas creadas con la funcion GL_LINE_STRIP");
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}