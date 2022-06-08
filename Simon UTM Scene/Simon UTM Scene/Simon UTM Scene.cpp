#include<GL/glut.h>
#include<math.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //reset background to default
	glutSwapBuffers(); // Load the Identity Matrix to reset our drawing locations (coordinate)
	// mid point of scree is x=810, y=390 to ease ploting coordinate

	// start your drawing here

	glBegin(GL_QUADS);    //gradient blue sky          
	glColor3f(0.0, 0.3, 0.4); 
	glVertex2f(0.0,0.0);
	glColor3f(0.0, 0.3, 0.4);
	glVertex2f(810, 0);
	glColor3f(0.0, 0.5, 0.9);
	glVertex2f(810, 390);
	glColor3f(0.0, 0.5, 0.9);
	glVertex2f(0, 390);
	glEnd();

	glLineWidth(5); //pole of moon and star
	glBegin(GL_LINES); // |
	glColor3f(0.2, 0.2, 0.2);
	glVertex2f(405, 340);
	glVertex2f(405, 260);
	glEnd();

	//stars
	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(50, 90);
	glVertex2f(120, 150);
	glVertex2f(65, 290);
	glVertex2f(90, 350);
	glVertex2f(700, 90);
	glVertex2f(760, 250);
	glVertex2f(660, 200);
	glVertex2f(580, 350);
	glVertex2f(620, 220);
	glVertex2f(700, 370);
	glVertex2f(750, 300);
	glVertex2f(100, 370);
	glVertex2f(130, 380);
	glVertex2f(800, 360);
	glEnd();

	//stars
	glPointSize(1);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(72, 300);
	glVertex2f(150, 250);
	glVertex2f(300, 290);
	glVertex2f(500, 350);
	glVertex2f(600, 100);
	glVertex2f(700, 250);
	glVertex2f(800, 200);
	glEnd();

	//moon
	glBegin(GL_POLYGON); //using shape argument to determine the shape
	glColor3f(1, 1, 0); //color
	for (int i = 0; i < 360; i++) { //draw a grass field, (circle) y=100
		float theta = i * 3.142 / 180;
		glVertex2f(405 + 12 * cos(theta), (345) + 10 * sin(theta));
	}
	glEnd();

	glBegin(GL_POLYGON); //using shape argument to determine the shape
	glColor3f(0.0, 0.475, 0.875); //color
	for (int i = 0; i < 360; i++) { //draw a grass field, (circle) y=100
		float theta = i * 3.142 / 180;
		glVertex2f(410 + 12 * cos(theta), (345) + 10 * sin(theta));
	}
	glEnd();

	//star on mosque
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 0);
	glVertex2f(413, 352);
	glVertex2f(412, 348); //
	glVertex2f(406, 347);
	glVertex2f(411, 344); //
	glVertex2f(411, 339);
	glVertex2f(415, 343); //
	glVertex2f(422, 340);
	glVertex2f(418, 345); //
	glVertex2f(422, 349);
	glVertex2f(416.5, 348.5); //
	glEnd();

	//star
	//glBegin(GL_POLYGON);
	//glColor3f(1, 1, 0);
	//glVertex2f(420, 320);
	//glEnd();

	glBegin(GL_QUADS);   //left 2nd pole     
	glColor3f(0.4, 0.6, 0.8);
	glVertex2f(195, 190);
	glColor3f(0.5, 0.70, 0.9);
	glVertex2f(200, 290);
	glColor3f(0.5, 0.70, 0.9);
	glVertex2f(225, 290);
	glColor3f(0.4, 0.6, 0.8);
	glVertex2f(230, 190);
	glEnd();

	glBegin(GL_TRIANGLES); //left triangle
	glColor3f(0.4, 0.6, 0.8);
	glVertex2f(205, 290);
	glColor3f(0.5, 0.70, 0.9);
	glVertex2f(215, 380);
	glColor3f(0.4, 0.6, 0.8);
	glVertex2f(220, 290);
	glEnd();

	glBegin(GL_QUADS);   //right 2nd pole  
	glColor3f(0.4, 0.6, 0.8);
	glVertex2f(580, 190);
	glColor3f(0.5, 0.70, 0.9);
	glVertex2f(585, 290);
	glColor3f(0.5, 0.70, 0.9);
	glVertex2f(610, 290);
	glColor3f(0.4, 0.6, 0.8);
	glVertex2f(615, 190);
	glEnd();

	glBegin(GL_TRIANGLES); //right triangle
	glColor3f(0.4, 0.6, 0.8);
	glVertex2f(590, 290);
	glColor3f(0.5, 0.70, 0.9);
	glVertex2f(595, 380);
	glColor3f(0.4, 0.6, 0.8);
	glVertex2f(605, 290);
	glEnd();

	//round shape on mosque
	glBegin(GL_POLYGON); //using shape argument to determine the shape
	glColor3f(0.5, 0.70, 0.9); //color
	for (int i = 0; i < 360; i++) { //draw a grass field, (circle) y=100
		float theta = i * 3.142 / 180;
		glVertex2f(405 + 120 * cos(theta), (200) + 120 * sin(theta));
	}
	glEnd();

	glBegin(GL_QUADS);   //BOTTOM big stand for poles   
	glColor3f(0.4, 0.6, 0.8);
	glVertex2f(205, 70);
	glColor3f(0.5, 0.70, 0.9);
	glVertex2f(185, 195);
	glColor3f(0.5, 0.70, 0.9);
	glVertex2f(625, 195);
	glColor3f(0.4, 0.6, 0.8);
	glVertex2f(590, 70);
	glEnd();


	glBegin(GL_QUADS);  //square under round shape      
	glColor3f(0.4, 0.6, 0.8);
	glVertex2f(288, 220);
	glColor3f(0.5, 0.7, 0.9);
	glVertex2f(522, 220);
	glColor3f(0.5, 0.7, 0.9);
	glVertex2f(522, 250);
	glColor3f(0.4, 0.6, 0.8);
	glVertex2f(288, 250);
	glEnd();

	glBegin(GL_QUADS);   //main mosque (behind)       
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2f(260, 90);   
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(240, 210);
	glColor3f(0.6f, 0.6f, 0.6f); 
	glVertex2f(570, 210);
	glColor3f(0.4f, 0.46f, 0.4f);
	glVertex2f(550, 90);
	glEnd();

	glBegin(GL_QUADS);   //main mosque        
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(280, 90);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex2f(260, 230);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex2f(550, 230);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(530, 90);
	glEnd();

	//door
	glBegin(GL_QUADS);   //main mosque (behind)       
	glColor3f(0.3f, 0.3f, 0.3f); //
	glVertex2f(340, 90);
	glColor3f(0.6f, 0.6f, 0.6f); //
	glVertex2f(320, 205);
	glColor3f(0.6f, 0.6f, 0.6f); //
	glVertex2f(490, 205);
	glColor3f(0.3f, 0.3f, 0.3f); //
	glVertex2f(470, 90);
	glEnd();

	//draw grass
	glBegin(GL_POLYGON); //using shape argument to determine the shape
	glColor3f(0.3, 0.5, 0.01); //color
	for (int i = 0; i < 360; i++) { //draw a grass field, (circle) y=100
		float theta = i * 3.142 / 180;
		glVertex2f(405+1500*cos(theta), (-1400)+1500*sin(theta));
	}
	glEnd();

	glLineWidth(20);
	glBegin(GL_LINES); // # symbol
	glColor3f(1.0, 1.0, 0.5);
	glVertex2f(180, 120);// |
	glVertex2f(170, 50);
	glVertex2f(215, 120);// |
	glVertex2f(205, 50);
	glVertex2f(150, 100);// --
	glVertex2f(230, 100);
	glVertex2f(150, 70);// --
	glVertex2f(230, 70);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.5);
	glVertex2f(250, 120);// I
	glVertex2f(250, 50);
	glEnd();

	glBegin(GL_LINES); // a
	glColor3f(1.0, 1.0, 0.5);
	glVertex2f(310, 88); //
	glVertex2f(270, 97.5); 
	glVertex2f(270, 100); // |
	glVertex2f(270, 50);
	glVertex2f(270, 53); //
	glVertex2f(310, 65);
	glVertex2f(310, 91); // |
	glVertex2f(310, 63);
	glVertex2f(310, 63); // 
	glVertex2f(320, 50);
	glEnd();

	glBegin(GL_LINES); // m
	glColor3f(1.0, 1.0, 0.5);
	glVertex2f(340, 99.5); // |
	glVertex2f(340, 50); 
	glVertex2f(340, 97.5); // 
	glVertex2f(360, 50); 
	glVertex2f(359, 50); // 
	glVertex2f(379, 97.5); 
	glVertex2f(379, 99.5); // |
	glVertex2f(379, 50); 
	glEnd();

	glBegin(GL_LINES); // U
	glColor3f(1.0, 1.0, 0.5);
	glVertex2f(400, 123); // |
	glVertex2f(400, 50);
	glVertex2f(397, 50); // --
	glVertex2f(463, 50);
	glVertex2f(460, 50); // |
	glVertex2f(460, 123);
	glEnd();

	glBegin(GL_LINES); // T
	glColor3f(1.0, 1.0, 0.5);
	glVertex2f(480, 120); // --
	glVertex2f(550, 120);
	glVertex2f(515, 120); // |
	glVertex2f(515, 50);
	glEnd();

	glBegin(GL_LINES); // M
	glColor3f(1.0, 1.0, 0.5);
	glVertex2f(570, 122); // |
	glVertex2f(570, 50);
	glVertex2f(570, 120); // 
	glVertex2f(600, 50);
	glVertex2f(600, 50); // 
	glVertex2f(630, 120);
	glVertex2f(630, 122); // |
	glVertex2f(630, 50);
	glEnd();

	glFlush(); //display the frame buffer to window
}

void myinit() {
	glClearColor(0.0, 0.4, 0.8, 1.0); //background color
	glMatrixMode(GL_PROJECTION); // Use the Projection Matrix
	glLoadIdentity(); // Reset Matrix
	gluOrtho2D(0.0, 810.0, 0.0, 390.0); //set the coordinate system in window
}

void main(int argc, char** argv) {
	glutInit(&argc, argv); // init GLUT and create window
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set the display mode
	glutInitWindowSize(1280, 720); //initialize the window size (pixel) when run the code 
	glutInitWindowPosition(300, 190); //initialize the window position (pixel) when run the code
	glutCreateWindow("IamUTM & Mosque"); //prompt out a window

	glutDisplayFunc(display); // register callbacks

	myinit();
	glutMainLoop();
}