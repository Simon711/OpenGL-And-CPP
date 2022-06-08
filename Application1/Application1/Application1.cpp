#include <GL/glut.h> // Include the GLUT header file

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //reset background to default
	glutSwapBuffers(); // Load the Identity Matrix to reset our drawing locations (coordinate)


	//start your drawing here
	glPointSize(10.0); //set the point size
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POINT); //your drawing will be starting here
	glVertex2f(5.0, 5.0);


	glEnd(); //end drawing session
	glFlush(); //display frame buffer on screen (whatever you have drawn), Flush the OpenGL buffers to the window 
}

//void color() {
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Clear the background of the window 
//}

void changeSize() {

	//if (h == 0) // Prevent a divide by zero, when window is too short
	//	h = 1; // (you cant make a window of zero width).

	//float ratio = w * 1.0 / h;

	//glViewport(0, 0, w, h); // Set the viewport to be the entire window
	glMatrixMode(GL_PROJECTION); // Use the Projection Matrix
	glLoadIdentity(); // Reset Matrix
	//gluPerspective(45, ratio, 1, 100); // Set the correct perspective.
	gluOrtho2D(-10, 10, -10, 10);
	//glMatrixMode(GL_MODELVIEW);	// Get Back to the Modelview
}

int main(int argc, char** argv) {

	glutInit(&argc, argv); // init GLUT and create window
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100); //initialize the window position (pixel) when run the code
	glutInitWindowSize(1280, 720); //initialize the window size (pixel) when run the code 
	glutCreateWindow("First Drawing"); //prompt out a window

	// register callbacks	
	glutDisplayFunc(display);
	changeSize();

//	color();

	glutMainLoop(); // enter GLUT event processing loop

	return 0;
}