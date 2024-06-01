#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <cmath>
#include <iostream>

const int num_points = 1000;
const float theta_min = 0.0f;
const float theta_max = 2.0f * M_PI;
const float pi = 3.14159265359f;

void inicio()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void pantalla()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    GLUquadricObj *pt;
    pt = gluNewQuadric();
    gluQuadricDrawStyle(pt, GLU_LINE);
    glColor3f(1.0, 0.0, 0.0);
    gluPartialDisk(pt, 0, 90, 15, 6, 45, 90);
    glColor3f(1.0, 0.0, 0.0);
    gluPartialDisk(pt, 0, 45, 15, 6, -45, -90);
    glFlush();

    //Petalos
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_points; ++i) {
        float theta = theta_min + (theta_max - theta_min) * i / num_points;
        float r = 75 * sqrt(cos(2 * theta)); // Radio * Ecuación polar
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // Pétalo adicional arriba
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_points; ++i) {
        float theta = theta_min + (theta_max - theta_min) * i / num_points;
        if (theta >= (pi / 4) && theta <= (pi / 2)) { // Ángulo entre 45 y 90 grados
            float r = 75 * sqrt(cos(2 * theta)); // Radio * Ecuación polar
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f(x, y);
        }
    }
    glEnd();

    // Pétalo adicional abajo
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_points; ++i) {
        float theta = theta_min + (theta_max - theta_min) * i / num_points;
        if (theta >= (pi / 2) && theta <= (3 * pi / 2)) { // Ángulo entre 90 y 270 grados
            float r = 75 * sqrt(cos(2 * theta)); // Radio * Ecuación polar
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f(x, y);
        }
    }
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Disco hueco");
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}
