#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

inline GLint round(const GLfloat a) { return GLint(a + 0.5); }

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}

void plotPixel(GLint xCoordinate, GLint yCoordinate)
{
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2i(xCoordinate, yCoordinate);
	glEnd();
	glFlush();
}

void lineDDA(GLint x0, GLint y0, GLint xEnd, GLint yEnd)
{
	GLint dx = xEnd - x0;
	GLint dy = yEnd - y0;
	GLint steps, k;
	GLfloat xIncrement, yIncrement, x = x0, y = y0;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xIncrement = GLfloat(dx) / GLfloat(steps);
	yIncrement = GLfloat(dy) / GLfloat(steps);
	plotPixel(round(x), round(y));
	for (k = 0; k < steps; k++)
	{
		x += xIncrement;
		y += yIncrement;
		plotPixel(round(x), round(y));
	}
}

void drawMyLine(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); 
	//H
	GLint x0 = -100; // |
	GLint y0 = 100;
	GLint xEnd = -100;
	GLint yEnd = -100;
	lineDDA(x0, y0, xEnd, yEnd);

	GLint x01 = -100;  // --
	GLint y01 = 0;
	GLint xEnd1 = -20;
	GLint yEnd1 = 0;
	lineDDA(x01, y01, xEnd1, yEnd1);

	GLint x02 = -20;  // |
	GLint y02 = 100;
	GLint xEnd2 = -20;
	GLint yEnd2 = -100;
	lineDDA(x02, y02, xEnd2, yEnd2);

	//i
	GLint x03 = 20;  // |
	GLint y03 = 10;
	GLint xEnd3 = 20;
	GLint yEnd3 = -100;
	lineDDA(x03, y03, xEnd3, yEnd3);

	GLint x04 = 20;  // .
	GLint y04 = 100;
	GLint xEnd4 = 20;
	GLint yEnd4 = 100;
	lineDDA(x04, y04, xEnd4, yEnd4);

	//!
	glColor3f(1.0, 1.0, 0.0); 
	GLint x05 = 100;  // |
	GLint y05 = 100;
	GLint xEnd5 = 100;
	GLint yEnd5 = -20;
	lineDDA(x05, y05, xEnd5, yEnd5);

	GLint x06 = 100;  // .
	GLint y06 = -100;
	GLint xEnd6 = 100;
	GLint yEnd6 = -100;
	lineDDA(x06, y06, xEnd6, yEnd6);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(500, 0);
	glutCreateWindow("Draw \"HI\" by DDA" );
	init();
	glutDisplayFunc(drawMyLine);
	glutMainLoop();
}