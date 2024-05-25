// Dibujando 3 cuadrilateros unidos con GL_QUAD_STRIP

#include<GL/glut.h>

void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-20,120,-20,120); // Define una proyección ortográfica 2D
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0); //Color de la figura o línea
    glBegin(GL_QUAD_STRIP);
        glVertex2f(8,40);
        glVertex2f(8,85);
        glVertex2f(37,40);
        glVertex2f(40,70);
        glVertex2f(65,20);
        glVertex2f(70,75);
        glVertex2f(95,25);
        glVertex2f(100,70);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(8,40);
        glVertex2f(8,85);
        glVertex2f(40,70);
        glVertex2f(70,75);
        glVertex2f(100,70);
        glVertex2f(95,25);
        glVertex2f(65,20);
        glVertex2f(37,40);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(37,40);
        glVertex2f(40,70);
        glVertex2f(65,20);
        glVertex2f(70,75);
    glEnd();
    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(680,480); 
    glutInitWindowPosition(10,10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("3 cuadrilateros unidos con GL_QUAD_STRIP"); // Crea una ventana con el título especificado
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    return EXIT_SUCCESS;
}