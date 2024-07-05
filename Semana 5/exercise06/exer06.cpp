// Titulo

#include<GL/glut.h>
#include<cmath>
#include<math.h>

void inicio(){
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-250,250,-250,250); // Define una proyección ortográfica 2D
    glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo
}

void pantalla(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0); //Color de la figura o línea
    //Discos con GLUT
    GLUquadricObj *pt;
    pt=gluNewQuadric();
    gluQuadricDrawStyle(pt, GLU_LINE);
    glColor3f (0.0, 0.0, 0.0); //Color negro
    gluDisk(pt, 0, 200, 20, 6); //Objeto, radio interno, radio externo, segmentos, anillos

    //Curva polar
    int npuntos = 1000;
    float theta, r, x, y, k = 2.0f;
    glColor3f(1.0, 0.0, 0.0); //Color rojo
    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
        for(int i=0; i < npuntos; i++){
            theta = 2.0f * M_PI * i / npuntos;
            r = 40 * (2-3*sin(theta)); //Radio * Ecuación polar
            x = r * cos(theta);
            y = r * sin(theta);
            glVertex2f(x, y);
        }
    glEnd();

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