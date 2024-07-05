//Dibujar un cono solido

#include <GL/glut.h>

// Función de inicialización
void init() {
    // Establecer el color de fondo de la ventana a negro
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // Habilitar la prueba de profundidad para renderizado 3D adecuado
    glEnable(GL_DEPTH_TEST);
    // Seleccionar la matriz de proyección para establecer la perspectiva
    glMatrixMode(GL_PROJECTION);
    // Establecer una perspectiva con un campo de visión de 45 grados, una relación de aspecto de 1:1 y planos de recorte cercanos y lejanos
    gluPerspective(45.0, 1.0, 1.0, 10.0);
}

// Función para dibujar un cono alámbrico
void drawWireCone() {
    glColor3f(1.0, 1.0, 1.0);  // Color blanco para el cono alámbrico
    glutWireCone(1.0, 2.0, 45, 3);  // Dibujar el cono alámbrico con radio 1, altura 2, 45 meridianos y 3 paralelas
}

// Función para dibujar un cono sólido
void drawSolidCone() {
    glColor3f(0.0, 0.0, 1.0);  // Color azul para el cono sólido
    glutSolidCone(1.0, 2.0, 45, 3);  // Dibujar el cono sólido con radio 1, altura 2, 45 meridianos y 3 paralelas
}

// Función de renderizado
void display() {
    // Limpiar el buffer de color y el buffer de profundidad
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Seleccionar la matriz de modelo/vista para posicionar objetos
    glMatrixMode(GL_MODELVIEW);
    // Resetear la matriz modelo/vista
    glLoadIdentity();
    // Definir la posición y orientación de la cámara
    gluLookAt(0.0, 3.0, 6.0,   // Posición de la cámara (eye)
              0.0, 0.0, 0.0,   // Punto de interés (center)
              0.0, 1.0, 0.0);  // Vector "arriba" de la cámara (up)

    // Dibujar primero el cono alámbrico
    drawWireCone();
    // Luego, dibujar el cono sólido encima para que se superponga
    drawSolidCone();

    // Intercambiar los buffers de la ventana para mostrar el renderizado actual
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    // Inicializar GLUT
    glutInit(&argc, argv);
    // Configurar el modo de pantalla con doble buffer, color RGB y prueba de profundidad
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // Establecer el tamaño de la ventana a 500x500 píxeles
    glutInitWindowSize(500, 500);
    // Establecer la posición inicial de la ventana
    glutInitWindowPosition(100, 100);
    // Crear una ventana con el título "Cono Alámbrico y Sólido"
    glutCreateWindow("Cono Alambrico solido");

    // Llamar a la función de inicialización
    init();
    // Registrar la función de renderizado
    glutDisplayFunc(display);
    // Iniciar el bucle principal de GLUT
    glutMainLoop();

    return 0;
}
