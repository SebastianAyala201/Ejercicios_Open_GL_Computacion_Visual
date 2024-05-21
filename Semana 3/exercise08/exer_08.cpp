// Dibujando un cuadrado con GL_LINE_LOOP

#include<GL/glut.h>

void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-50,150,-50,150); // Define una proyección ortográfica 2D
    glClearColor(0.0, 1.0, 1.0, 1.0); // Color de fondo
}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0); //Color de la figura o línea
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0,0);
    glVertex2f(0,100);
    glVertex2f(100,100);
    glVertex2f(100,0);
    glEnd();
    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(680,480); 
    glutInitWindowPosition(10,10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("Cuadrado con GL_LINE_LOOP"); // Crea una ventana con el título especificado
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    return EXIT_SUCCESS;
}