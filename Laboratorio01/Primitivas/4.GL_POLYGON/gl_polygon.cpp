// Dibujando un polígono con GL_POLYGON

#include<GL/glut.h>

void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-20,120,-20,120); // Define una proyección ortográfica 2D
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0); //Color de la figura o línea
    glBegin(GL_POLYGON);
        glVertex2f(10,20);
        glVertex2f(30,70);
        glVertex2f(70,90);
        glVertex2f(90,40);
        glVertex2f(60,10);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(10,20);
        glVertex2f(30,70);
        glVertex2f(70,90);
        glVertex2f(90,40);
        glVertex2f(60,10);
    glEnd();
    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(680,480); 
    glutInitWindowPosition(10,10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("Poligono con GL_POLYGON"); // Crea una ventana con el título especificado
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    return EXIT_SUCCESS;
}