// Dibujando vertices de un poligono con GL_POINTS

#include<GL/glut.h>
#include<math.h>

void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-100,100,-100,100); // Define una proyección ortográfica 2D
    glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo
}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0); //Color de la figura o línea
    
    GLfloat ang, radio = 40.0f,x,y;
    glPointSize(5.0); 
    glPushMatrix();
    glBegin(GL_POINTS);
        for (ang = 0.0; ang < 2*M_PI; ang +=2*M_PI/6){
            x = radio * sin(ang);
            y = radio * cos(ang);
            glVertex2f(x,y);
        }

    glEnd();
    glPopMatrix();
    glFlush(); // Asegura que las órdenes de dibujo se ejecuten
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(680,480); 
    glutInitWindowPosition(10,10); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("Vertices de un hexagono"); // Crea una ventana con el título especificado
    inicio(); 
    glutDisplayFunc(pantalla); 
    glutMainLoop();
    return EXIT_SUCCESS;
}