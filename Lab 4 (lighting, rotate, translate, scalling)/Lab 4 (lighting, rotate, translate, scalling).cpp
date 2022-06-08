//Simon Chong Kai Yuen
//A19EC3028

#include <windows.h>
#include <GL/glut.h>
using namespace std;

static int window;
static int menu_id;
static int submenu_id;
static int value = 2;

float def_translate = -0.5f;
float change_translate = 0.03f;
float def_scale = 1.0f;
float change_scale = 0.03f;
int trans = 0;
int scale = 0;

//initializa 3D rendering
void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
}

void handleKeypress(unsigned char key, int x, int u)
{
    switch (key)
    {
    case 27:
        exit(0);
    case '1':
        glEnable(GL_LIGHTING);
        break;
    case '0':
        glDisable(GL_LIGHTING);
        break;
    case 'a':
        change_translate = 0.03f;
        change_scale = 0.3f;
        break;
    case 'd':
        change_translate = 0.0f;
        change_scale = 0.0f;
        break;
    }
}

void menu(int num)
{
    if (num == 0)
    {
        glutDestroyWindow(window);
        exit(0);
    }
    else
    {
        value = num;
    }
    glutPostRedisplay();
}


void createMenu(void)
{
    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Triangular Prism", 2);
    glutAddMenuEntry("Pyramid", 3);

    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("Draw", submenu_id);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void handleResize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLfloat ambientColor[] = { 0.3f,0.3f,0.3f,1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    GLfloat lightColor0[] = { 0.5f,0.5f,0.5f,1.0f };
    GLfloat lightPos0[] = { 2.0f,0.0f,0.0f,1.0f };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    GLfloat lightColor1[] = { 0.5f,0.2f,0.2f,1.0f };

    GLfloat lightPos1[] = { -1.0f,0.5f,0.5f,0.0f };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

    if (value == 1)
    {
        glutPostRedisplay();
    }
    else if (value == 2) {
        //Triangular Prism
        glTranslatef(0.0f, 1.0f, -6.0f);

        glTranslatef(def_translate, 0.0f, -0.0f);
        glColor3f(1.0f, 0.0f, 0.0f);

        glBegin(GL_TRIANGLES);
        glNormal3f(1.0f, 0.0f, 0.0f); //front surface
        glVertex3f(-1.0, -1.0, 0.5);
        glVertex3f(1.0, -1.0, 0.5);
        glVertex3f(0.0, 0.5, 0.5);

        glNormal3f(0.0f, 0.0f, -0.5); //back surface
        glVertex3f(-1.0, -1.0, -0.5);
        glVertex3f(1.0, -1.0, -0.5);
        glVertex3f(0.0, 0.5, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        glNormal3f(0.0f, 0.0f, 0.5); //left surface
        glVertex3f(-1.0, -1.0, 0.5);
        glVertex3f(0.0, 0.5, 0.5);
        glVertex3f(0.0, 0.5, -0.5);
        glVertex3f(-1.0, -1.0, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        glNormal3f(-1.0f, 0.0f, 0.0f); //right surface
        glVertex3f(1.0, -1.0, 0.5);
        glVertex3f(0.0, 0.5, 0.5);
        glVertex3f(0.0, 0.5, -0.5);
        glVertex3f(1.0, -1.0, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        glNormal3f(1.0f, -1.0f, 0.5); //bottom surface
        glVertex3f(-1.0, -1.0, 0.5);
        glVertex3f(1.0, -1.0, 0.5);
        glVertex3f(1.0, -1.0, -0.5);
        glVertex3f(-1.0, -1.0, -0.5);
        glEnd();

        glEnd();
        glutSwapBuffers();
    }

    else if (value == 3) {
        //pyramid
        glTranslatef(0.0f, 0.0f, -10.0f);
        glScalef(def_scale, def_scale, 1.0);
        glRotatef(105, 0.0f, 1.0f, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glBegin(GL_TRIANGLES);

        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(0.0, 0.5, 0.0);

        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(0.0, 0.5, 0.0);

        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(0.0, 0.5, 0.0);

        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(0.0, 0.5, 0.0);
        glEnd();

        glBegin(GL_POLYGON);
        glNormal3f(1.0f, -1.0f, 0.0f);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(0.0, -0.5, 0.5);
        glVertex3f(0.0, -0.5, -0.5);
        glVertex3f(-0.5, -0.5, -0.5);
        glEnd();

        glutSwapBuffers();
    }
}


void Translation(int value)
{
    if (trans == 0) {
        def_translate += change_translate;
        if (def_translate > 2)
        {
            trans = 1;
        }
    }
    if (trans == 1) {
        def_translate -= change_translate;
        if (def_translate < -2)
        {
            trans = 0;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(25, Translation, 0);
}


void Scaling(int value)
{
    if (scale == 0) {
        def_scale += change_scale;
        if (def_scale > 4)
        {
            scale = 1;
        }
    }
    if (scale == 1) {
        def_scale -= change_scale;
        if (def_scale < 0)
        {
            scale = 0;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(25, Scaling, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1500, 1000);
    glutInitWindowPosition(200, 100);

    window = glutCreateWindow("Lighting Your 3D Scene");
    createMenu();
    initRendering();
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);

    glutTimerFunc(25, Translation, 0);
    glutTimerFunc(25, Scaling, 0);
    glutMainLoop();

    return 0;

}
