//Dibujando la figura del examen parcial

#include <GL/glut.h>
#include <cmath>

void inicio() {
	// Establece el color de fondo en blanco
	glClearColor(1.0, 1.0, 1.0, 1.0);
	
	// Establece la región de visualización ortográfica con un rango adecuado
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

void dibujarDiscoParcialDerecha(){
    // Crear un objeto quadrico para dibujar el disco
    GLUquadricObj *pt;
    pt=gluNewQuadric();
    // Especificar el estilo de dibujo (líneas en este caso)
    gluQuadricDrawStyle(pt,GLU_LINE);
    // Establecer el color
    glColor3f (1.0, 0.0, 0.0);
    // Dibujar el disco parcial
    gluPartialDisk(pt, 0, 6, 15, 6, 40, 100);
}

void dibujarDiscoParcialIzquierda(){
    // Crear un objeto quadrico para dibujar el disco
    GLUquadricObj *pt;
    pt=gluNewQuadric();
    // Especificar el estilo de dibujo (líneas en este caso)
    gluQuadricDrawStyle(pt,GLU_LINE);
    // Establecer el color
    glColor3f (1.0, 0.0, 0.0);
    // Dibujar el disco parcial
    gluPartialDisk(pt, 0, 3, 15, 6, -40,-100);
}

void dibujar2Petalos(){
    // Establecer el color
    glColor3f(1.0, 0.0, 0.0);
    // Rotar los pétalos
    glRotatef(90, 0, 0, 1);
	// Dibujar los pétalos
	glBegin(GL_LINE_STRIP);
	for (float t = 0; t <= 2*M_PI; t += 0.01) {
		float r = 2 * sqrt(cos(2*t));
		float x = r * cos(t);
		float y = r * sin(t);
		glVertex2f(x, y);
	}
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	// Dibujar los discos parciales y los pétalos
	dibujarDiscoParcialDerecha();
    dibujarDiscoParcialIzquierda();
    dibujar2Petalos();
	glFlush();
}



int main(int argc, char** argv) {
	// Inicializar GLUT
	glutInit(&argc, argv);
	// Establecer el modo de visualización y buffer
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Establecer el tamaño de la ventana
	glutInitWindowSize(800, 600);
	// Crear la ventana
	glutCreateWindow("Examen Parcial");
	// Especificar la función de renderizado
	glutDisplayFunc(display);
	// Inicializar OpenGL
	inicio();
	// Entrar en el bucle de eventos de GLUT
	glutMainLoop();
	return 0;
}
