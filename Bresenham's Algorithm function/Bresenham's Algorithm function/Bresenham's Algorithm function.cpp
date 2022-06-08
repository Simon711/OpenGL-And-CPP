#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
const float half = 0.5;

inline GLint round(const GLfloat a)
{
	return GLint(a + half);
}

void init(void);
void setPixel(GLint, GLint);
void lineBresenham(GLint, GLint, GLint, GLint);
void drawLine(void);

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(960, 510);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Algorithm");
	init();
	glutDisplayFunc(drawLine);
	glutMainLoop();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0); //set the background as black
	glMatrixMode(GL_PROJECTION); //set to this mode to adjust.modify matrix/coordinate
	gluOrtho2D(0.0, 960.0, 0.0, 510.0); //set the coordinate system to x= 0-960 and y= 0-510
}

void setPixel(GLint xCoordinate, GLint yCoordinate)
{
	glPointSize(20.0); //set point size to 20 pixel
	glBegin(GL_POINTS); //start to draw
	glVertex2i(xCoordinate, yCoordinate); //take x and y as argument to determine 2 points
	glEnd();
	glFlush();
}

void lineBresenham(GLint x0, GLint y0, GLint x1, GLint y1)
{
	GLint dx = x1 - x0;	//calculate difference of x
	GLint dy = y1 - y0; //calculate difference of y
	GLint p = (2 * dy) - dx; //calculate first pk
	GLfloat x = x0, y = y0;

	while (x < x1)
	{
		if (p >= 0) //if pk greater than 0
		{
			setPixel(round(x), round(y)); //revoke the setpixel function to draw points between 2 initial points
			p += (2 * dy) - (2 * dx);
			y++; //y will be incremented
		}

		else //if pf smaller than 0
		{
			setPixel(round(x), round(y)); //revoke the setpixel function to draw points between 2 initial points
			p += (2 * dy); //y will not be incremented in this case
		}
		x++; //x will be incremented in both condition 
	}
}

void drawLine(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); //set points color to white
	GLint x0 = 20; //x of 1st point 
	GLint y0 = 20; //y of 1st point
	GLint x1 = 900; //x of 2nd point
	GLint y1 = 480; //y of 2nd point
	lineBresenham(x0, y0, x1, y1); //call the function to calculate the points betweeen two initial points and draw then display
}