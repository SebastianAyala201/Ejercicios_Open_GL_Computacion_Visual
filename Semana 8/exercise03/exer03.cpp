#include <GL/glut.h>
<<<<<<< HEAD

float x, y;
bool check = false; // Inicialmente falso para no dibujar ningún punto al inicio

void inicio() {
    glClearColor(1, 0, 0, 0); // Fondo rojo
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

void mouse(int click, int estado, int CoordX, int CoordY) {
    if (click == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
        check = true;
        x = CoordX;
        y = 480 - CoordY; // Convertir coordenadas de ventana a coordenadas OpenGL
=======
#include <vector>

// Estructura para almacenar la posición y color de un píxel
struct Pixel {
    int x, y;
    float r, g, b;
};

// Vector para almacenar los píxeles pintados
std::vector<Pixel> pixels;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Dibujar cada píxel almacenado en el vector
    glBegin(GL_POINTS);
    for (const auto& pixel : pixels) {
        glColor3f(pixel.r, pixel.g, pixel.b);
        glVertex2i(pixel.x, pixel.y);
    }
    glEnd();

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Convertir coordenadas de ventana a coordenadas de OpenGL
        int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
        int posX = x;
        int posY = windowHeight - y;  // Invertir y

        // Crear un nuevo píxel con color rojo
        Pixel pixel = { posX, posY, 1.0f, 0.0f, 0.0f };
        pixels.push_back(pixel);

>>>>>>> 49e8087 (Subiendo ejercicios de semana 8)
        glutPostRedisplay();
    }
}

<<<<<<< HEAD
void PintarPixel(float x, float y) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void pantalla(void) {
    if (check) {
        glColor3f(1, 1, 1); // Color blanco para el punto
        glPointSize(10);
        PintarPixel(x, y);
    } else {
        glColor3f(1, 0, 0); // Mantener el fondo rojo si no se ha hecho clic
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(640, 0);
        glVertex2f(640, 480);
        glVertex2f(0, 480);
        glEnd();
    }
    glFlush();
=======
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Fondo blanco
    glColor3f(0.0, 0.0, 0.0);  // Color de dibujo negro
    glPointSize(5.0);  // Tamaño de los puntos

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);  // Coordenadas del mundo
>>>>>>> 49e8087 (Subiendo ejercicios de semana 8)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
<<<<<<< HEAD
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Resaltar pixeles");

    inicio();
     glClear(GL_COLOR_BUFFER_BIT); // Limpiar el buffer de color
    glutDisplayFunc(pantalla);
    glutMouseFunc(mouse);
    glutMainLoop();
    return EXIT_SUCCESS;
}
=======
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Resaltar Píxeles");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}
>>>>>>> 49e8087 (Subiendo ejercicios de semana 8)
