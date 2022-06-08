#include <GL/glut.h> // Include the GLUT header file

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)

	//original square
	glBegin(GL_QUADS);		//each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); //white color
	glVertex2f(-0.3f, -0.3f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(-0.3f, 0.3f);
	glEnd();

	glTranslatef(0.6f, 0.6, 0.0);	//translate left and down
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 1.0f); //cyan color
	glVertex2f(-0.3f, -0.3f);	
	glVertex2f(0.3f, -0.3f);	
	glVertex2f(0.3f, 0.3f);
	glVertex2f(-0.3f, 0.3f);
	glEnd();

	glRotatef(4.0, 0, 0, 1.0);	//rotate 4 degrees on z axis
	glBegin(GL_QUADS);		
	glColor3f(1.0f, 1.0f, 0.0f); //color
	glVertex2f(-0.3f, -0.3f);	//define vertices in counter-clockwise (CCW) order
	glVertex2f(0.3f, -0.3f);	//so that the normal(front-face) is facing you
	glVertex2f(0.3f, 0.3f);
	glVertex2f(-0.3f, 0.3);
	glEnd();

	glRotatef(4.0, 0, 0, 1.0);	//rotate 30 degrees on z axis
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.2f); //color
	glVertex2f(-0.3f, -0.3f);	//define vertices in counter-clockwise (CCW) order
	glVertex2f(0.3f, -0.3f);	//so that the normal(front-face) is facing you
	glVertex2f(0.3f, 0.3f);
	glVertex2f(-0.3f, 0.3);
	glEnd();

	glRotatef(4.0, 0, 0, 1.0);	//rotate 30 degrees on z axis
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.4f); //color
	glVertex2f(-0.3f, -0.3f);	//define vertices in counter-clockwise (CCW) order
	glVertex2f(0.3f, -0.3f);	//so that the normal(front-face) is facing you
	glVertex2f(0.3f, 0.3f);
	glVertex2f(-0.3f, 0.3);
	glEnd();

	glRotatef(4.0, 0, 0, 1.0);	//rotate 30 degrees on z axis
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.6f); //color
	glVertex2f(-0.3f, -0.3f);	//define vertices in counter-clockwise (CCW) order
	glVertex2f(0.3f, -0.3f);	//so that the normal(front-face) is facing you
	glVertex2f(0.3f, 0.3f);
	glVertex2f(-0.3f, 0.3);
	glEnd();

	glRotatef(4.0, 0, 0, 1.0);	//rotate 30 degrees on z axis
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.8f); //color
	glVertex2f(-0.3f, -0.3f);	//define vertices in counter-clockwise (CCW) order
	glVertex2f(0.3f, -0.3f);	//so that the normal(front-face) is facing you
	glVertex2f(0.3f, 0.3f);
	glVertex2f(-0.3f, 0.3);
	glEnd();

	glRotatef(4.0, 0, 0, 1.0);	//rotate 30 degrees on z axis
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f); //color
	glVertex2f(-0.3f, -0.3f);	//define vertices in counter-clockwise (CCW) order
	glVertex2f(0.3f, -0.3f);	//so that the normal(front-face) is facing you
	glVertex2f(0.3f, 0.3f);
	glVertex2f(-0.3f, 0.3);
	glEnd();

	glutSwapBuffers();
	glFlush(); // Flush the OpenGL buffers to the window
}


int main(int argc, char** argv) {

	glutInit(&argc, argv); // init GLUT and create window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100); //initialize the window position (pixel) when run the code
	glutInitWindowSize(800, 800); //initialize the window size (pixel) when run the code 
	glutCreateWindow("Translation and Rotation"); //prompt out a window

	glutDisplayFunc(display);
	glutMainLoop(); // enter GLUT event processing loop

	return 0;
}