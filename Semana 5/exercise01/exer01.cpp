#include <GL/glut.h>
#include <math.h>
#include <iostream>

const int num_points = 1000;
const float theta_min = 0.0f;
const float theta_max = 2.0f * M_PI;
float rotation_angle = -M_PI / 64 + 1;

void inicio() {
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-90, 100, -90, 100);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < num_points; ++i) {
		float theta = theta_min + (theta_max - theta_min) * i / num_points;
		float r = 50 * sin(5 * theta);
		float x = r * cos(theta);
		float y = r * sin(theta);
		
		float x_rot = x * cos(rotation_angle) - y * sin(rotation_angle);
		float y_rot = x * sin(rotation_angle) + y * cos(rotation_angle);
		
		glVertex2f(x_rot, y_rot);
	}
	glEnd();
	
	glFlush();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(0, 100);
	glVertex2f(0, -100);
	glVertex2f(100, 0);
	glVertex2f(-100, 0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Curva de cinco petalos");
	inicio();
	glutDisplayFunc(display);
	glutMainLoop();
}