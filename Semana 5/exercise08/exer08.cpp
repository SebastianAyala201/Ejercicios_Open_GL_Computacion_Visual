// Titulo

#include<GL/glut.h>

void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-50,150,-50,150); // Define una proyección ortográfica 2D
    glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo
}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0); //Color de la figura o línea
    // Lógica de la figura
    //Las funciones glBegin y glEnd delimitan los vértices que definen un primitivo.
    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(680,480); 
    glutInitWindowPosition(10,10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("XXXXXXXXXXX"); // Crea una ventana con el título especificado
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    return EXIT_SUCCESS;
}