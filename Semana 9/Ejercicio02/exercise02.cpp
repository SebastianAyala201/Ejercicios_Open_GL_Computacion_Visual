//Dibujar un cono alambrico

#include <GL/glut.h>

// Función de inicialización
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Color de fondo negro
    glEnable(GL_DEPTH_TEST);           // Habilitar la prueba de profundidad
    glMatrixMode(GL_PROJECTION);       // Seleccionar la matriz de proyección
    gluPerspective(50.0, 1.0, 1.0, 10.0);  // Definir perspectiva
}

// Función de renderizado
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Limpiar el buffer de color y profundidad

    glMatrixMode(GL_MODELVIEW);  // Seleccionar la matriz de modelo/vista
    glLoadIdentity();            // Resetear la matriz
    gluLookAt(5.0, 0.0, 0.0,     // Posición de la cámara
              4.0, 0.0, 0.0,     // Punto al que mira la cámara
              0.0, 1.0, 0.0);    // Vector arriba

    glColor3f(0.0, 0.0, 1.0);    // Establecer el color del cono (blanco)
    glutWireCone(1.0, 2.0, 45, 3);  // Dibujar el cono con los parámetros especificados

    glutSwapBuffers();  // Intercambiar los buffers de la ventana
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                      // Inicializar GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // Modo de pantalla
    glutInitWindowSize(500, 500);               // Tamaño de la ventana
    glutInitWindowPosition(100, 100);           // Posición de la ventana
    glutCreateWindow("Cono Alambrico");         // Crear ventana con título

    init();  // Llamar a la función de inicialización
    glutDisplayFunc(display);  // Registrar la función de renderizado
    glutMainLoop();  // Iniciar el bucle principal de GLUT

    return 0;
}
