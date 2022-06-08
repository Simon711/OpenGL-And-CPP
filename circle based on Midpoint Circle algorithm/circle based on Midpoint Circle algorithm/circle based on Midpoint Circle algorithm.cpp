#include <GL/glut.h>


inline GLint round(const GLfloat a) { return GLint(a + 0.5); }

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

class screenPt
{	private:GLint x, y;
	public:
	/*  Default Constructor: initializes coordinate position to (0, 0).  */
	screenPt ()  {
		x=y=0;
	}
	
	void setCoords (GLint xCoordValue, GLint yCoordValue)  {
		x = xCoordValue;y = yCoordValue;
	}
	
	GLint getx () const  {
		return x;
	}
	
	GLint gety () const  {
		return y;
	}
	
	void incrementx ()  {
		x++;
	}
	
	void decrementy ()  {
		y--;
	}
};

void plotPixel (GLint xCoord, GLint yCoord)
{
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2i (xCoord, yCoord);
	glEnd();
	glFlush();
}

void circlePlotPoints(GLint xc, GLint yc, screenPt circPt) { 
	plotPixel(xc + circPt.getx(), yc + circPt.gety());
	plotPixel(xc - circPt.getx(), yc + circPt.gety());
	plotPixel(xc + circPt.getx(), yc - circPt.gety());
	plotPixel(xc - circPt.getx(), yc - circPt.gety());
	plotPixel(xc + circPt.gety(), yc + circPt.getx());
	plotPixel(xc - circPt.gety(), yc + circPt.getx());
	plotPixel(xc + circPt.gety(), yc - circPt.getx());
	plotPixel(xc - circPt.gety(), yc - circPt.getx());
}

void circleMidpoint(GLint xc, GLint yc, GLint radius)
{
	screenPt circPt; GLint p = 1 - radius;         //  Initial value for midpoint parameter.
	circPt.setCoords(0, radius); //  Set coordinates for top point of circle.
	void circlePlotPoints(GLint, GLint, screenPt);
	/*  Plot the initial point in each circle quadrant.  */
	circlePlotPoints(xc, yc, circPt);
	/*  Calculate next point and plot in each octant.  */

	while (circPt.getx() < circPt.gety())
	{
		circPt.incrementx();
		if (p < 0)
			p += 2 * circPt.getx() + 1;
		else {
			circPt.decrementy();
			p += 2 * (circPt.getx() - circPt.gety()) + 1;
		}
		circlePlotPoints(xc, yc, circPt);
	}
}

void drawCircle(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	GLint x = 250;
	GLint y = 250;
	GLint r = 200;
	circleMidpoint(x, y, r);

	glColor3f(0.0, 1.0, 0.0);
	GLint x1 = 100;
	GLint y1 = 400;
	GLint r1 = 300;
	circleMidpoint(x1, y1, r1);

	glColor3f(0.0, 0.0, 1.0);
	GLint x2 = 400;
	GLint y2 = 180;
	GLint r2 = 150;
	circleMidpoint(x2, y2, r2);

	glColor3f(0.0, 1.0, 1.0);
	GLint x3 = 350;
	GLint y3 = 200;
	GLint r3 = 50;
	circleMidpoint(x3, y3, r3);

	glColor3f(1.0, 1.0, 0.0);
	GLint x4 = 100;
	GLint y4 = 380;
	GLint r4 = 70;
	circleMidpoint(x4, y4, r4);

	glColor3f(0.0, 0.0, 0.0);
	GLint x5 = 200;
	GLint y5 = 230;
	GLint r5 = 150;
	circleMidpoint(x5, y5, r5);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(500, 0);
	glutCreateWindow("Draw many circles by circle mid-point algorithm");
	init();
	glutDisplayFunc(drawCircle);
	glutMainLoop();
}