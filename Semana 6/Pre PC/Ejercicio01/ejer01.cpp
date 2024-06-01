#include <GL/glut.h>
#include <iostream>

// Variables globales para la longitud del lado y el número de cuadrados
float L = 0;
float N = 0;

// Inicialización
void inicio() {
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-100, 100, -100, 100); // Define una proyección ortográfica 2D
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

// Función para dibujar un cuadrado con el centro en el origen y lado L
void drawSquare1(int size) {
    float halfSize = size / 2;
    glBegin(GL_LINE_LOOP); 
    glVertex2f(-halfSize, -halfSize);
    glVertex2f(halfSize, -halfSize);
    glVertex2f(halfSize, halfSize);
    glVertex2f(-halfSize, halfSize);
    glEnd();
}

void drawSquare2(int size) {
    float halfSize = size / 2;
    glBegin(GL_LINE_LOOP); 
    glVertex2f(0,-halfSize);
    glVertex2f(halfSize, 0);
    glVertex2f(0, halfSize);
    glVertex2f(-halfSize, 0);
    glEnd();
}

// Función de pantalla
void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Color del cuadrado
    glLineWidth(3);

    float size = L;
    for (int i = 1; i <= N; ++i) {
        if(i%2!=0){
            drawSquare1(size);
            
        }else{
            drawSquare2(size);
            size = size / 2;
        } 
        
    }

    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}


// Función para leer las entradas del teclado
void readInput() {
    std::cout << "Ingrese la longitud del lado del cuadrado mayor (L): ";
    std::cin >> L;
    std::cout << "Ingrese el número de cuadrados a dibujar (N): ";
    std::cin >> N;
}

int main(int argc, char *argv[]) {
    readInput();

    glutInit(&argc, argv);
    glutInitWindowSize(680, 480); 
    glutInitWindowPosition(10, 10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("Dibujar Cuadrados con OpenGL"); // Crea una ventana con el título especificado
    inicio(); 
    glutDisplayFunc(pantalla); // Establece la función de pantalla
    glutMainLoop(); // Inicia el bucle principal de GLUT
    return EXIT_SUCCESS;
}
