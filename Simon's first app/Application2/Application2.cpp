#include<GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //reset background to default
	glutSwapBuffers(); // Load the Identity Matrix to reset our drawing locations (coordinate)

	// mid point of scree is x=640, y=360 to ease ploting coordinate

	glPointSize(90.0); //point size
	// start your drawing here
	glBegin(GL_POINTS); //using shape argument to determine the shape
	glColor3f(1.0, 1.0, 1.0); //point color
	glVertex2f(0.0 + 20, 0.0 + 20);	
	glVertex2f(1280.0 - 20, 20.0);
	glVertex2f(0.0 + 20, 720.0 - 20);
	glVertex2f(1280.0 - 20, 720.0 -20);
	glEnd(); //end your drawing session here

	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.6);
	glVertex2f(512, 600);
	glVertex2f(256, 480);
	glVertex2f(256, 240);
	glVertex2f(512, 120);
	glVertex2f(768, 120);
	glVertex2f(1024, 240);
	glVertex2f(1024, 480);
	glVertex2f(768, 600);
	glEnd(); //end your drawing session here
	
	glBegin(GL_TRIANGLES); //normal triangle
	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(420, 233 + 45); ///////first triangle
	glVertex2f(840, 233 + 45);
	glVertex2f(640, 480 + 45);
	glEnd(); //end your drawing session here

	//glPointSize(20.0); //point size
	glBegin(GL_TRIANGLES); //inverse triangle
	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(420, 480 - 45); //second triangle
	glVertex2f(840, 480 - 45);
	glVertex2f(640, 233 - 45);
	glEnd(); //end your drawing session here

	glLineWidth(20.0);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(640 - 500, 360 - 300);
	glVertex2f(640 + 500, 360 - 300);
	glVertex2f(640 - 500, 360 + 300);
	glVertex2f(640 + 500, 360 + 300);
	glEnd();

	glFlush(); //display the frame buffer to window
}

void myinit() {
	glClearColor(1.5, 0.5, 0.5, 1.0); //background color
	glMatrixMode(GL_PROJECTION); // Use the Projection Matrix
	glLoadIdentity(); // Reset Matrix
	gluOrtho2D(0.0, 1280.0, 0.0, 720.0); //set the coordinate system in window
}

void main(int argc, char** argv) {
	glutInit(&argc, argv); // init GLUT and create window
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set the display mode
	glutInitWindowSize(1280, 720); //initialize the window size (pixel) when run the code 
	glutInitWindowPosition(0, 0); //initialize the window position (pixel) when run the code
	glutCreateWindow("Points"); //prompt out a window

	glutDisplayFunc(display); // register callbacks
	
	myinit();
	glutMainLoop();
}