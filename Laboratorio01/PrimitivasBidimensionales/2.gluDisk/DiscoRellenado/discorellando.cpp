// Dibujando un disco rellenado

#include<GL/glut.h>

void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-100,100,-100,100); // Define una proyección ortográfica 2D
    glClearColor(1.0, 1.0, 1.0, 1.0); // Color de fondo
}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0); //Color de la figura o línea

    GLUquadricObj *pt;
    pt=gluNewQuadric();
    gluQuadricDrawStyle(pt,GLU_FILL);
    gluDisk(pt, 40, 90, 15, 6);

    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(680,480); 
    glutInitWindowPosition(10,10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("Disco Rellenado"); // Crea una ventana con el título especificado
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    return EXIT_SUCCESS;
}