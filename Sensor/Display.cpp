#include "Display.h"
#include "freeGLUT\freeglut.h"

Display::Display() :
	windowName("Display"),
	width(800),
	height(600)
{
}


Display::~Display()
{
}


void display();

int Display::init()
{
	int argc = 1;
	char* argv[]{ "Display" };
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);	
	return 0;
}
void Display::drawPoints(Vector2 * vertices, int count, float size)
{
	glPointSize(size);
	glBegin(GL_POINTS);
	for (int i = 0; i < count; i++) {
		glVertex2fv(&vertices[i].x);
	}
	glEnd();
}
void Display::drawLines(Vector2 * vertices, int count)
{
	glBegin(GL_LINES);
	for (int i = 0; i < count; i++) {
		glVertex2fv(&vertices[i].x);
	}
	glEnd();
}
void Display::drawText(Vector2 * position, const char * text, int length)
{
}
void Display::setBackgroundColor(Color color)
{
	glClearColor(color.r, color.g, color.b, color.a);
}
void Display::setForegroundColor(Color color)
{
	glColor3fv((float*)&color);
}

void Display::onRender()
{
}


Display* instance = nullptr;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (instance != nullptr)
		instance->onRender();
	glutSwapBuffers();
}

void reshape(int width, int height) {

	float r = (float)width / (float)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluOrtho2D(-r, r, -1, 1);
	gluOrtho2D(-r / 2, r / 2, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void Display::run()
{
	instance = this;

	glutInitWindowSize(width, height);
	glutCreateWindow(windowName);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);

	//glClearColor(0.4f, 0.4f, 0.4f, 1);
	glColor4f(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_DEPTH);

	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	glutMainLoop();
}