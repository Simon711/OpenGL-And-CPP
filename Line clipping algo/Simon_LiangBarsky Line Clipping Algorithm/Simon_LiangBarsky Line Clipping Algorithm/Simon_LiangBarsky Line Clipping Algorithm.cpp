/*CHONG HONG LEI (A19EC0035)*/
/*LIANG-BARSKY LINE CLIPPING ALGORITHM*/

#include<GL/glut.h>

class wcPt2D
{
private:
	GLfloat x, y;
public:
	/* Default Constructor: initialize position as (0.0, 0.0). */
	wcPt2D() {
		x = y = 0.0;
	}
	void setCoords(GLfloat xCoord, GLfloat yCoord) {
		x = xCoord;
		y = yCoord;
	}
	GLfloat getx() const {
		return x;
	}
	GLfloat gety() const {
		return y;
	}
};

inline GLint round(const GLfloat a) { return GLint(a + 0.5); }

GLint clipTest(GLfloat p, GLfloat q, GLfloat* u1, GLfloat* u2)
{
	GLfloat r;
	GLint returnValue = true;
	if (p < 0.0) {
		r = q / p;
		if (r > *u2)
			returnValue = false;
		else
			if (r > *u1)
				*u1 = r;
	}
	else
		if (p > 0.0) {
			r = q / p;
			if (r < *u1)
				returnValue = false;
			else if (r < *u2)
				*u2 = r;
		}
		else if (q < 0.0)
			/* Thus p = 0 and line is parallel to clipping boundary. */
			/* Line is outside clipping boundary. */
			returnValue = false;

	return (returnValue);
}

void lineClipLiangBarsk(wcPt2D winMin, wcPt2D winMax, wcPt2D p1, wcPt2D p2)
{
	GLfloat u1 = 0.0, u2 = 1.0, dx = p2.getx() - p1.getx(), dy;

	if (clipTest(-dx, p1.getx() - winMin.getx(), &u1, &u2))
		if (clipTest(dx, winMax.getx() - p1.getx(), &u1, &u2)) {
			dy = p2.gety() - p1.gety();
			if (clipTest(-dy, p1.gety() - winMin.gety(), &u1, &u2))
				if (clipTest(dy, winMax.gety() - p1.gety(), &u1, &u2)) {
					if (u2 < 1.0) {
						p2.setCoords(p1.getx() + u2 * dx, p1.gety() + u2 * dy);
					}
					if (u1 > 0.0) {
						p1.setCoords(p1.getx() + u1 * dx, p1.gety() + u1 * dy);
					}
					glColor3f(1, 1, 0);
					glLineWidth(5);
					glBegin(GL_LINES);
					glVertex2i(round(p1.getx()), round(p1.gety()));
					glVertex2i(round(p2.getx()), round(p2.gety()));
					glEnd();
					glFlush();
				}
		}
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1000, 0, 1000);
}

void worldCoordinate(wcPt2D X, wcPt2D Y) {

	glColor3f(0, 0, 1);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);
	glVertex2i(round(X.getx()), round(X.gety()));
	glVertex2i(round(X.getx()), round(Y.gety()));
	glVertex2i(round(Y.getx()), round(Y.gety()));
	glVertex2i(round(Y.getx()), round(X.gety()));
	glEnd();
	glFlush();
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	wcPt2D bottom_left_point, top_right_point, p1, p2, p3, p4;
	bottom_left_point.setCoords(100, 200);
	top_right_point.setCoords(700, 800);
	worldCoordinate(bottom_left_point, top_right_point);

	glLineWidth(5);
	// line 1
	p1.setCoords(300, 20);
	p2.setCoords(900, 900);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(round(p1.getx()), round(p1.gety()));
	glVertex2i(round(p2.getx()), round(p2.gety()));
	glEnd();

	// line 2
	p3.setCoords(10, 900);
	p4.setCoords(900, 10);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(round(p3.getx()), round(p3.gety()));
	glVertex2i(round(p4.getx()), round(p4.gety()));
	glEnd();

	lineClipLiangBarsk(bottom_left_point, top_right_point, p1, p2);
	lineClipLiangBarsk(bottom_left_point, top_right_point, p3, p4);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(500, 100);
	glutCreateWindow("Liang-Barsky Line Clipping Algorithm");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
}