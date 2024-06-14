#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Establece el color de dibujo a negro
    
    float k = 0.5; // Ajusta este valor para cambiar el tamaño del anillo
    
    glBegin(GL_LINE_STRIP);
    for (float t = 0; t <= 2 * M_PI; t += 0.01) {
        float r = 1 + 2 * cos(t) + k;
        float x = -r * cos(t); // Orientar hacia la izquierda
        float y = r * sin(t);
        glVertex2f(x, y);
    }
    glEnd();
    
    glFlush();
}

void init() {
    // Establece el color de fondo en blanco
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    // Establece la región de visualización ortográfica con un rango adecuado
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-4.0, 4.0, -4.0, 4.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cardioide con anillo con OpenGL");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
