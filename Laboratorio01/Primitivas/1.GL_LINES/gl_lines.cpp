// Dibujando 3 lineas con GL_LINES

#include<GL/glut.h>

void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-20,120,-20,120); // Define una proyección ortográfica 2D
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0); //Color de la figura o línea
    glLineWidth(4);
    glBegin(GL_LINES);
        glVertex2f(30,50);
        glVertex2f(40,100);

        glVertex2f(45,30);
        glVertex2f(90,90);

        glVertex2f(60,90);
        glVertex2f(60,0);
    glEnd();
    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(680,480); 
    glutInitWindowPosition(10,10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("3 Lineas con GL_LINES"); // Crea una ventana con el título especificado
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    return EXIT_SUCCESS;
}