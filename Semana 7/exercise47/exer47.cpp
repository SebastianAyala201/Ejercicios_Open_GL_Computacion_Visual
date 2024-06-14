#include <GL/glut.h>
#include <cmath>

// Constantes
const int N = 1000; // Número de puntos para dibujar la curva
const float PI = 3.14159265358979323846;
const float theta_min = 0;
const float theta_max = 4 * PI;

// Función para inicializar el entorno de OpenGL
void inicio() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(theta_min, theta_max, -3, 3); // Define una proyección ortográfica 2D
    glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo
}

// Función para dibujar la curva
void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0); // Color de la curva

    glBegin(GL_LINE_STRIP); // Inicia el trazado de la curva
    for (int i = 0; i <= N; ++i) {
        float theta = theta_min + i * (theta_max - theta_min) / N;
        float y = sin(theta) + pow(sin(2.5 * theta), 3);
        glVertex2f(theta, y);
    }
    glEnd();

    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Curva f(θ) = sin(θ) + sin^3(2.5θ)"); // Crea una ventana con el título especificado
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}
