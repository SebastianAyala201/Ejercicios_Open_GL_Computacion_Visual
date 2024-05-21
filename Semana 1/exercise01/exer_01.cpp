// TITULO

#include<GL/glut.h>

void inicio(){
    glMatrixMode(GL_PROJECTION); //Indica el tipo de proyección
    gluOrtho2D(-60,100,-60,100); // Define una proyección ortográfica 2D
    glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo
}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);// Limpia el buffer de color usando el color especificado en glClearColor
    glColor3f(1.0,0.0,1.0); //Color de la figura o línea
    // Lógica de la figura
    //Las funciones glBegin y glEnd delimitan los vértices que definen un primitivo.
    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv); // Inicializa GLUT y procesa los argumentos de línea de comandos
    glutInitWindowSize(680,480); // Establece el tamaño de la ventana a 680x480 píxeles
    glutInitWindowPosition(10,10); // Establece la posición de la ventana en la pantalla
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Establece el modo de visualización
    glutCreateWindow("XXXXXXXXXXX"); // Crea una ventana con el título especificado
    inicio(); // Llama a la función de inicialización definida por el usuario
    glutDisplayFunc(pantalla); // Establece la función de visualización
    glutMainLoop(); // Inicia el bucle principal de eventos de GLUT
    return EXIT_SUCCESS; // Indica que el programa ha terminado correctamente
}