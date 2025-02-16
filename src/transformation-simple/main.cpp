/**
 * Simple demonstration of transformations.
 */

#include <GL/glut.h>
#include <GL/gl.h>

//Globais
float x = 0.1;
float y = 0.1;
float z = 0.1;

int escala = 0;
float tamEscala = 0.0;

int rotaciona = 0;
float angRotaciona = 0.0;
float sentidoRot = 1.0;

int translada = 0;
float tamTranslada = 0.0;
float sentido = 1.0;
void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-1.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 1.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -1.0);
	glEnd();
}

void display()
{

	//if (translada == 0) x = x + 0.001;
	//if (translada == 1) x = x - 0.001;
	

	// Clear the screen painting it all with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform OpenGL we want to make changes to the modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	// Render a red square
	glColor3f(1, 0, 0);
	
	if (translada == 0) {
		if (tamTranslada > 1.0) sentido = -1.0;
		if (tamTranslada < -1.0) sentido = 1.0;
		tamTranslada = tamTranslada + (0.001 * sentido);
	}
	glTranslatef(tamTranslada, 0.0f, 0);	
	
	if (rotaciona == 0) {
		if (angRotaciona > 90.0) sentidoRot = -1.0;
		if (tamTranslada < 0.0) sentidoRot = 1.0;
		angRotaciona = angRotaciona + (0.1 * sentido);
	}
	glRotatef(angRotaciona, 0.0f, 0.0f, 1.0f);
	
	glRectf(-x, x, y, -y);

	glLoadIdentity();

	// Render a blue square
	glColor3f(0, 0, 1);
	//glTranslatef(0.2f, 0.2f, 0);
	//glRotatef(45.0f, 0, 0, 1.0f);
	//glRectf(-0.1f, 0.1f, 0.1f, -0.1f);

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == '1') {
		// 1 key
		if (rotaciona == 1){
			rotaciona = 0;
		} else{
			rotaciona = 1;
		}
	}

	if (key == '2') {
		// 2 key
		if (translada == 1){
			translada = 0;
		} else{
			translada = 1;
		}
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}
