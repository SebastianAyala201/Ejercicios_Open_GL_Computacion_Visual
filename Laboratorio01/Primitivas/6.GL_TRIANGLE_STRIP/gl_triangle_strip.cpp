// Dibujando 4 triangulos unidos con GL_TRIANGLE_STRIP

#include<GL/glut.h>

void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-20,120,-20,120); // Define una proyección ortográfica 2D
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0); //Color de la figura o línea
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(5,65);
        glVertex2f(10,35);
        glVertex2f(35,70);
        glVertex2f(50,30);
        glVertex2f(70,65);
        glVertex2f(95,35);
    glEnd();

    glLineWidth(3);

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(5,65);
        glVertex2f(10,35);
        glVertex2f(35,70);
        glVertex2f(50,30);
        glVertex2f(70,65);
        glVertex2f(95,35);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex2f(95,35);
        glVertex2f(50,30);

        glVertex2f(70,65);
        glVertex2f(35,70);

        glVertex2f(10,35);
        glVertex2f(50,30);

        glVertex2f(5,65);
        glVertex2f(35,70);
    glEnd();

    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(680,480); 
    glutInitWindowPosition(10,10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("4 triangulos unidos con GL_TRIANGLE_STRIP"); // Crea una ventana con el título especificado
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    return EXIT_SUCCESS;
}