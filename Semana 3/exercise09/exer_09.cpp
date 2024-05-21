// //Dibujando un rectángulo inconcluso con la función GL_LINE_STRIP

#include<GL/glut.h>

void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-50,150,-50,150); // Define una proyección ortográfica 2D
    glClearColor(1.0, 0.8, 0.0, 1.0); // Color de fondo
}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0); //Color de la figura o línea
    glBegin(GL_LINE_STRIP);
    glVertex2f(0,0);
    glVertex2f(0,80);
    glVertex2f(80,80);
    glVertex2f(80,0);
    glVertex2f(40,0);
    glEnd();
    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(680,480); 
    glutInitWindowPosition(10,10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("Rectangulo inconcluso con la funcion GL_LINE_STRIP"); // Crea una ventana con el título especificado
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    return EXIT_SUCCESS;
}