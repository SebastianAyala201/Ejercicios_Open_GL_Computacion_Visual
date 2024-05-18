#include <GL/glut.h>

void inicio()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 140, -50, 140);
    glClearColor(1.0, 1.0, 1.0, 0.0); 
}

void pantalla()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0); 
    glBegin(GL_TRIANGLE_STRIP);
        glVertex3f(0, 0, 0);
        glVertex3f(40, 50, 0);
        glVertex3f(80, 0, 0);
        glVertex3f(110, 80, 0);
    glEnd();

    //Bordes
    glColor3f(0.0, 0.0, 0.0); //Color negro de los bordes
    glLineWidth(2.0);

    glBegin(GL_LINE_STRIP);
        glVertex3f(0, 0, 0);
        glVertex3f(40, 50, 0);
        glVertex3f(80, 0, 0);
        glVertex3f(110, 80, 0);
        glVertex3f(40, 50, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(80, 0, 0);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Dos Triangulos con GL_TRIANGLE_STRIP");
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}