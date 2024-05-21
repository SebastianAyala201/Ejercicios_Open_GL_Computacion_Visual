// Dibujando un cuadrado vacio

#include<GL/glut.h>

void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-20,120,-20,120); // Define una proyección ortográfica 2D
    glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo
}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0); //Color de la figura o línea
    glLineWidth(3.0);         // Establece el ancho de la línea
    glBegin(GL_LINES);
    glVertex2i(0,0);
    glVertex2i(0,100);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(0,100);
    glVertex2i(100,100);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(100,100);
    glVertex2i(100,0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(100,0);
    glVertex2i(0,0);
    glEnd();

    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(680,480); 
    glutInitWindowPosition(10,10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("Cuadrado vacio"); // Crea una ventana con el título especificado
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    return EXIT_SUCCESS;
}