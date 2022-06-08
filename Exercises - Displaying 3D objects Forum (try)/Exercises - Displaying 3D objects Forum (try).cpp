//Simon Chong Kai Yuen A19EC3028

#include<windows.h>
#include<GL/glut.h>

static int window;
static int menu_id;
static int submenu_id;
static int value = 2;

void menu(int num) {
	if (num == 0) {
		glutDestroyWindow(window);
		exit(0);
	}
	else
		value = num;
	glutPostRedisplay();
}

void createMenu(void)
{
	submenu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Pyramid", 2);
	glutAddMenuEntry("Cube", 3);
	glutAddMenuEntry("Octahedron", 4);
	glutAddMenuEntry("Triangular Prism", 5);

	menu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Clear", 1);
	glutAddSubMenu("Draw", submenu_id);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	if (value == 1)
		glutPostRedisplay();

	else if (value == 2) {	//pyramid
		glPushMatrix();
		glRotatef(30, 5.0, 5.0, 0.0);

		//front surface
		glBegin(GL_TRIANGLES);
		glColor3d(1.0, 0.0, 0.0);
		glVertex3f(0.0, 0.4, 0.0);
		glVertex3f(-0.3, -0.3, 0.3);
		glVertex3f(0.3, -0.3, 0.3);
		glEnd();

		//back surfacec
		glBegin(GL_TRIANGLES);
		glColor3d(0.8, 0.0, 0.0);
		glVertex3f(0.0, 0.4, 0.0);
		glVertex3f(-0.3, -0.3, -0.3);
		glVertex3f(0.3, -0.3, -0.3);
		glEnd();

		//left surface
		glBegin(GL_TRIANGLES);
		glColor3d(0.2, 0.0, 0.0);
		glVertex3f(0.0, 0.4, 0.0);
		glVertex3f(-0.3, -0.3, -0.3);
		glVertex3f(-0.3, -0.3, 0.3);
		glEnd();

		//right surface
		glBegin(GL_TRIANGLES);
		glColor3d(0.8, 0.0, 0.0);
		glVertex3f(0.0, 0.4, 0.0);
		glVertex3f(0.3, -0.3, -0.3);
		glVertex3f(0.3, -0.3, 0.3);
		glEnd();

		//bottom surface
		glBegin(GL_POLYGON);
		glColor3d(0.4, 0.0, 0.0);
		glVertex3f(-0.3, -0.3, 0.3);
		glVertex3f(0.3, -0.3, 0.3);
		glVertex3f(-0.3, -0.3, 0.3);
		glVertex3f(0.3, -0.3, 0.3);
		glEnd();
		glPopMatrix();
	}

	else if (value == 3) {	//cube
		glPushMatrix();
		glRotatef(45, 0.5, 0.8, 0.0);

		//bottom surface
		glBegin(GL_POLYGON);
		glColor3d(0.0, 0.2, 0.0);
		glVertex3f(-0.3, -0.3, 0.3);
		glVertex3f(0.3, -0.3, 0.3);
		glVertex3f(0.3, -0.3, -0.3);
		glVertex3f(-0.3, -0.3, -0.3);
		glEnd();

		//back surface
		glBegin(GL_POLYGON);
		glColor3d(0.0, 0.2, 0.0);
		glVertex3f(-0.3, -0.3, -0.3);
		glVertex3f(-0.3, 0.3, -0.3);
		glVertex3f(0.3, 0.3, -0.3);
		glVertex3f(0.3, -0.3, -0.3);
		glEnd();

		//right surface
		glBegin(GL_POLYGON);
		glColor3d(0.0, 0.2, 0.0);
		glVertex3f(0.3, 0.3, 0.3);
		glVertex3f(0.3, -0.3, 0.3);
		glVertex3f(0.3, -0.3, -0.3);
		glVertex3f(0.3, 0.3, -0.3);
		glEnd();

		//left surface
		glBegin(GL_POLYGON);
		glColor3d(0.0, 0.4, 0.0);
		glVertex3f(-0.3, 0.3, 0.3);
		glVertex3f(-0.3, -0.3, 0.3);
		glVertex3f(-0.3, -0.3, -0.3);
		glVertex3f(-0.3, 0.3, -0.3);
		glEnd();

		//top surface
		glBegin(GL_POLYGON);
		glColor3d(0.0, 1.0, 0.0);
		glVertex3f(-0.3, 0.3, 0.3);
		glVertex3f(0.3, 0.3, 0.3);
		glVertex3f(0.3, 0.3, -0.3);
		glVertex3f(-0.3, 0.3, -0.3);
		glEnd();

		//front surface
		glBegin(GL_POLYGON);
		glColor3d(0.0, 0.6, 0.0);
		glVertex3f(-0.3, -0.3, 0.3);
		glVertex3f(-0.3, 0.3, 0.3);
		glVertex3f(0.3, 0.3, 0.3);
		glVertex3f(0.3, -0.3, 0.3);
		glEnd();

		glPopMatrix();
	}

	else if (value == 4) {
		glPushMatrix();
		glRotated(40, 0.3, 0.2, 0.0);

		//back surface (top)
		glBegin(GL_TRIANGLES);
		glColor3d(0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.6, 0.0);
		glVertex3f(-0.3, 0.0, -0.3);
		glVertex3f(0.3, 0.0, -0.3);
		glEnd();

		//right surface (top)
		glBegin(GL_TRIANGLES);
		glColor3d(0.0, 0.0, 0.6);
		glVertex3f(0.0, 0.6, 0.0);
		glVertex3f(0.3, 0.0, -0.3);
		glVertex3f(0.3, 0.0, 0.3);
		glEnd();

		//back surface (bottom)
		glBegin(GL_TRIANGLES);
		glColor3d(0.0, 0.0, 0.6);
		glVertex3f(0.0, -0.6, 0.0);
		glVertex3f(-0.3, 0.0, -0.3);
		glVertex3f(0.3, 0.0, -0.3);
		glEnd();

		//right surface (bottom)
		glBegin(GL_TRIANGLES);
		glColor3d(0.0, 0.0, 1.0);
		glVertex3f(0.0, -0.6, 0.0);
		glVertex3f(0.3, 0.0, -0.3);
		glVertex3f(0.3, 0.0, 0.3);
		glEnd();

		//left surface (top)
		glBegin(GL_TRIANGLES);
		glColor3d(0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.6, 0.0);
		glVertex3f(-0.3, 0.0, -0.3);
		glVertex3f(-0.3, 0.0, 0.3);
		glEnd();

		//front surface (top)
		glBegin(GL_TRIANGLES);
		glColor3d(0.0, 0.0, 0.6);
		glVertex3f(0.0, 0.6, 0.0);
		glVertex3f(-0.3, 0.0, 0.3);
		glVertex3f(0.3, 0.0, 0.3);
		glEnd();

		//left surface (bottom)
		glBegin(GL_TRIANGLES);
		glColor3d(0.0, 0.0, 0.6);
		glVertex3f(0.0, -0.6, 0.0);
		glVertex3f(-0.3, 0.0, -0.3);
		glVertex3f(-0.3, 0.0, 0.3);
		glEnd();

		//front surface (bottom)
		glBegin(GL_TRIANGLES);
		glColor3d(0.0, 0.0, 1.0);
		glVertex3f(0.0, -0.6, 0.0);
		glVertex3f(-0.3, 0.0, 0.3);
		glVertex3f(0.3, 0.0, 0.3);
		glEnd();
		
		glPopMatrix();
	}

	else if (value == 5) {
		glPushMatrix();
		glRotated(60, 0.2, 0.7, 0.2);
		glColor3d(1.0, 0.0, 1.0);
		

		glBegin(GL_TRIANGLES);
		glColor3d(1.0, 1.0, 1.0);
		glVertex3f(0.0, 0.3, -0.4);
		glVertex3f(-0.3, -0.3, -0.4);
		glVertex3f(0.3, -0.3, -0.4);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3d(0.7, 0.7, 0.7);
		glVertex3f(0.0, 0.3, -0.4);
		glVertex3f(0.0, 0.3, 0.4);
		glVertex3f(-0.3, -0.3, 0.4);
		glVertex3f(-0.3, -0.3, -0.4);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3d(0.7, 0.7, 0.7);
		glVertex3f(0.0, 0.3, -0.4);
		glVertex3f(0.0, 0.3, 0.4);
		glVertex3f(0.3, -0.3, 0.4);
		glVertex3f(0.3, -0.3, -0.4);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3d(1.0, 1.0, 1.0);
		glVertex3f(0.0, 0.3, 0.4);
		glVertex3f(-0.3, -0.3, 0.4);
		glVertex3f(0.3, -0.3, 0.4);
		glEnd();

		glPopMatrix();
	}

	glFlush();
}

//void keyPressed(unsigned char key, int x, int y) {
//	switch (toupper(key)) {
//	case 'S':
//		static bool f = false;
//		if (!f) {
//			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//		}
//		else {
//			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//		}
//
//		f = !f;
//		break;
//	}
//}


void keyPressed(unsigned char key, int x, int y)
{
	key = toupper(key);
	if (key == 'F')
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	else if (key == 'L')
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (key == 'P')
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(1000, 100);
	window = glutCreateWindow("3D Objects from GLUT Library");

	createMenu();

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed);
	glutMainLoop();
	return 0;
}