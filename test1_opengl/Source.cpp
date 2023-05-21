/*
#include <GL/freeglut.h>

#include <iostream>

int width = 500, height = 500;

void init()
{
	glViewport(0, 0, width, height);  //

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();  //reset projection matrix values -  makes it identity matrix

	GLdouble aratio = GLdouble(width) / GLdouble(height);

	gluPerspective(60.0, aratio, 0.01, 50.0);
	//gluOrtho2D(0.0, width, height, 0.0);
}


void displayFunction(void) //display function/render function
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  // red, green, blue, alpha
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);  //load world view matrix
	glLoadIdentity(); // reset world view matrix 

	gluLookAt(0.0f, 0.0f, 5.0f,  //eye vector
		0.0f, 0.0f, 0.0f, //center vector
		0.0f, 1.0f, 0.0f); //up vector

	glutSolidCube(1.0);

	glutPostRedisplay(); // for animation
	glutSwapBuffers(); // 
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);  //initialize all flags in freeglut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); //GLUT_SINGLE
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	int i = glutCreateWindow("Hello world :D");

	init();

	glutDisplayFunc(displayFunction);

	glutMainLoop();

	return 0;
}



#include<GL\glut.h>
void draw();
void reshape(int w, int h) {
	; // arg represent width , hight
	glViewport(0, 0, w, h);// الجزء المرئي فقط called custom
}
int main(int argc , char ** argv) {
	// glut init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	// end of glut init 
	// create window
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(10,10);
	glutCreateWindow("First Section");
	// end create window

	// start call back functions
	// 
	// علشان ارسم استخدم ال call back function
	glutDisplayFunc(draw);
	// الحدود بتاعه الرسم علي المحور x , y من -1 1  -1 1
	glutReshapeFunc(reshape); // used this fun if the user make resize
	// end start call back functions 
	// main loop

	glutMainLoop();


}

// -------------------------------------------
/*
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
float width, height;
float currentwidth;
float xpos = 0;// var to change position of shapy in x axis
bool direction = true;
void background();
void draw();
void reshape(int w, int h);
void timer(int);




 Program entry point

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//  glutInitWindowSize(640,480);
	  //glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	width = GetSystemMetrics(SM_CXSCREEN);// to get width of screen
	height = GetSystemMetrics(SM_CYSCREEN);
	glutInitWindowSize(width, height);//full screen with title ==> must before create window
	glutInitWindowPosition(10, 10);
	glutCreateWindow("first sec");


	glutDisplayFunc(draw);

	glutReshapeFunc(reshape);
	background();
	glutTimerFunc(0, timer, 0);


	glutMainLoop();

	return EXIT_SUCCESS;
}
void draw() {

	glClear(GL_COLOR_BUFFER_BIT);  // to clear the colors
	glLoadIdentity();
	glEnable(GL_POINT_SMOOTH);// to make point circle

	//glLineWidth(10); to change line width
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex2f(xpos, 0);
	glVertex2f(xpos, 2);

	glVertex2f(xpos - 2, 2);
	glVertex2f(xpos - 2, 0);





	glEnd();
	//glFlush();// to display on screen
	glutSwapBuffers();

}
void background() {
	//glClearColor(r,g,b,a);
	glClearColor(1, 0.5, .4, 0);// to change back ground color

}

void reshape(int w, int h) {
	float ratio;
	if (h == 0)h = 1;
	ratio = (float)width / height;
	glViewport(0, 0, w, h);
	// 0 and 0 are dimentions
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // uses when edit on matrix mode

	if (w >= h)
	{


		gluOrtho2D(-10 * ratio, 10 * ratio, -10, 10);
		currentwidth = 10 * ratio;
	}
	else
		gluOrtho2D(-10, 10, -10 / ratio, 10 / ratio);
	{


		glMatrixMode(GL_MODELVIEW);
		currentwidth = 10;

	}
}
void timer(int v) {

	glutPostRedisplay();// redraw
	glutTimerFunc(1000 / 6, timer, 0);

	if (direction)// right
	{
		if (xpos < currentwidth) {
			xpos += .3;

		}

		else {
			direction = false;


		}

	}
	else// left
	{
		if (xpos > -currentwidth) {
			xpos -= .3;

		}

		else {
			direction = true;


		}

	}
}
*/



/*
#include <GL/glut.h>

float carX = 250.0f;  // Initial car position (x-coordinate)
float carY = 250.0f;  // Initial car position (y-coordinate)
float carSize = 50.0f;  // Size of the car

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void drawCar()
{
	glColor3f(0.0, 0.0, 1.0);  // Blue color for the car body

	glBegin(GL_POLYGON);
	glVertex2f(carX, carY);
	glVertex2f(carX + carSize, carY);
	glVertex2f(carX + carSize, carY + carSize);
	glVertex2f(carX, carY + carSize);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);  // Red color for the car roof

	glBegin(GL_POLYGON);
	glVertex2f(carX, carY + carSize);
	glVertex2f(carX + carSize, carY + carSize);
	glVertex2f(carX + carSize / 2, carY + carSize * 1.5);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);  // Yellow color for the wheels

	glPushMatrix();
	glTranslatef(carX + carSize * 0.2, carY, 0.0);
	glutSolidTorus(2, 6, 10, 10);  // Front wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(carX + carSize * 0.8, carY, 0.0);
	glutSolidTorus(2, 6, 10, 10);  // Rear wheel
	glPopMatrix();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	drawCar();

	glFlush();
}
void keyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':  // Move car up
		carY += 10.0f;
		break;
	case 's':  // Move car down
		carY -= 10.0f;
		break;
	case 'a':  // Move car left
		carX -= 10.0f;
		break;
	case 'd':  // Move car right
		carX += 10.0f;
		break;
	case '+':  // Increase car size
		carSize += 10.0f;
		break;
	case '-':  // Decrease car size
		carSize -= 10.0f;
		if (carSize < 10.0f) carSize = 10.0f;  // Set a minimum size for the car
		break;
	default:
		break;
	}

	glutPostRedisplay();
}
/*void keyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':  // Move car up
		carY += 10.0f;
		break;
	case 's':  // Move car down
		carY -= 10.0f;
		break;
	case 'a':  // Move car left
		carX -= 10.0f;
		break;
	case 'd':  // Move car right
		carX += 10.0f;
		break;
	default:
		break;
	}

	glutPostRedisplay();
}

void mouseFunc(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		carX = x;  // Set car position to mouse x-coordinate
		carY = 500 - y;  // Set car position to mouse y-coordinate (inverted)
		glutPostRedisplay();
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3D Car");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardFunc);  // Register keyboard function

	glutMainLoop();
	return 0;
}


*/
/*
#include <GL/glut.h>

float carX = 0.0f;     // Initial car position (x-coordinate)
float carY = 0.0f;     // Initial car position (y-coordinate)
float carSize = 1.0f;  // Size of the car

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);  // Use perspective projection
	glMatrixMode(GL_MODELVIEW);
}

void drawCar()
{
	glPushMatrix();
	glTranslatef(carX, carY, -5.0f);  // Translate the car position along the z-axis

	glColor3f(0.0, 0.0, 1.0);  // Blue color for the car body

	glBegin(GL_POLYGON);
	glVertex3f(-carSize, -carSize, 0.0);
	glVertex3f(carSize, -carSize, 0.0);
	glVertex3f(carSize, carSize, 0.0);
	glVertex3f(-carSize, carSize, 0.0);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);  // Red color for the car roof

	glBegin(GL_POLYGON);
	glVertex3f(-carSize, carSize, 0.0);
	glVertex3f(carSize, carSize, 0.0);
	glVertex3f(0.0, carSize * 1.5, carSize * 0.5);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);  // Yellow color for the wheels

	glPushMatrix();
	glTranslatef(-carSize * 0.8, -carSize, 0.0);
	glutSolidTorus(0.05, 0.15, 10, 10);  // Front left wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(carSize * 0.8, -carSize, 0.0);
	glutSolidTorus(0.05, 0.15, 10, 10);  // Front right wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-carSize * 0.8, carSize, 0.0);
	glutSolidTorus(0.05, 0.15, 10, 10);  // Rear left wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(carSize * 0.8, carSize, 0.0);
	glutSolidTorus(0.05, 0.15, 10, 10);  // Rear right wheel
	glPopMatrix();

	glPopMatrix();
}

void drawCar()
{
	glPushMatrix();
	glTranslatef(carX, carY, -5.0f);  // Translate the car position along the z-axis

	// Adjust car position to wrap around the screen
	if (carX > 2.5f)
		carX = -2.5f;
	else if (carX < -2.5f)
		carX = 2.5f;
	if (carY > 2.5f)
		carY = -2.5f;
	else if (carY < -2.5f)
		carY = 2.5f;

	glColor3f(0.0, 0.0, 1.0);  // Blue color for the car body

	glBegin(GL_POLYGON);
	glVertex3f(-carSize, -carSize, 0.0);
	glVertex3f(carSize, -carSize, 0.0);
	glVertex3f(carSize, carSize, 0.0);
	glVertex3f(-carSize, carSize, 0.0);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);  // Red color for the car roof

	glBegin(GL_POLYGON);
	glVertex3f(-carSize, carSize, 0.0);
	glVertex3f(carSize, carSize, 0.0);
	glVertex3f(0.0, carSize * 1.5, carSize * 0.5);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);  // Yellow color for the wheels

	glPushMatrix();
	glTranslatef(-carSize * 0.8, -carSize, 0.0);
	glutSolidTorus(0.05, 0.15, 10, 10);  // Front left wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(carSize * 0.8, -carSize, 0.0);
	glutSolidTorus(0.05, 0.15, 10, 10);  // Front right wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-carSize * 0.8, carSize, 0.0);
	glutSolidTorus(0.05, 0.15, 10, 10);  // Rear left wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(carSize * 0.8, carSize, 0.0);
	glutSolidTorus(0.05, 0.15, 10, 10);  // Rear right wheel
	glPopMatrix();

	glPopMatrix();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -10.0f);  // Translate the scene along the z-axis

	drawCar();

	glFlush();
}

void keyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':  // Move car up
		carY += 0.1f;
		break;
	case 's':  // Move car down
		carY -= 0.1f;
		break;
		case 'a': // Move car left
			carX -= 0.1f;
			break;
		case 'd': // Move car right
			carX += 0.1f;
			break;
		case '+': // Increase car size
			carSize += 0.1f;
			break;
		case '-': // Decrease car size
			carSize -= 0.1f;
			if (carSize < 0.1f) carSize = 0.1f; // Set a minimum size for the car
			break;
		default:
			break;
	}
		glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3D Car");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardFunc); // Register keyboard function
		glEnable(GL_DEPTH_TEST);  // Enable depth testing

	glutMainLoop();
	return 0;
}

*/
/*
#include <GL/glut.h>
int windowHeight = 500;
int windowWidth = 500;
int lastMouseX = 0;
int lastMouseY = 0;
float pyramidRotationX = 0.0f;
float pyramidRotationY = 0.0f;
float pyramidSize = 1.0f;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawPyramid()
{
	glPushMatrix();
	glRotatef(pyramidRotationX, 1.0f, 0.0f, 0.0f);
	glRotatef(pyramidRotationY, 0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f); // Red color

	// Front face
	glVertex3f(0.0f, pyramidSize, 0.0f);
	glVertex3f(-pyramidSize, -pyramidSize, pyramidSize);
	glVertex3f(pyramidSize, -pyramidSize, pyramidSize);

	glColor3f(0.0f, 1.0f, 0.0f); // Green color

	// Right face
	glVertex3f(0.0f, pyramidSize, 0.0f);
	glVertex3f(pyramidSize, -pyramidSize, pyramidSize);
	glVertex3f(pyramidSize, -pyramidSize, -pyramidSize);

	glColor3f(0.0f, 0.0f, 1.0f); // Blue color

	// Back face
	glVertex3f(0.0f, pyramidSize, 0.0f);
	glVertex3f(pyramidSize, -pyramidSize, -pyramidSize);
	glVertex3f(-pyramidSize, -pyramidSize, -pyramidSize);

	glColor3f(1.0f, 1.0f, 0.0f); // Yellow color

	// Left face
	glVertex3f(0.0f, pyramidSize, 0.0f);
	glVertex3f(-pyramidSize, -pyramidSize, -pyramidSize);
	glVertex3f(-pyramidSize, -pyramidSize, pyramidSize);

	glEnd();

	glPopMatrix();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5.0f);

	drawPyramid();

	glFlush();
	glutSwapBuffers();
}

void reshape(int width, int height)
{
	if (height == 0)
		height = 1;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)width / height, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state ==
		GLUT_DOWN)
	{
		lastMouseX = x;
		lastMouseY = y;
	}
}

void motion(int x, int y)
{
	int deltaX = x - lastMouseX;
	int deltaY = y - lastMouseY;
		pyramidRotationY += deltaX;
	pyramidRotationX += deltaY;

	lastMouseX = x;
	lastMouseY = y;

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '+':
		pyramidSize += 0.1f;
		break;
	case '-':
		pyramidSize -= 0.1f;
		if (pyramidSize < 0.1f)
			pyramidSize = 0.1f;
		break;
	default:
		break;
	}
		glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("3D Pyramid");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
*/

/*
// to kow the size of window define:
#include<Windows.h> // to get screen size 
#include<math.h>
#include<GL\glut.h>
bool fullScreen = true ;
float width, height, sWidth, sHeight,
 r = 5 , cx , cy , delcx , delcy , PI = 22/7.0 ;
int c1 = 0 , qc = 1;
// r radius , cx center for x , cy center for y , delcx مقدار التغير في ال x
void draw();
void reshape(int, int);
void backGround();
void timer(int);

void keyboarddown(unsigned char , int , int); // acess for acc
void keyboardup(unsigned char, int, int);

void keySpecialdown(int, int, int); // botton, xPos,yPos
void keySpecialup(int, int, int); //  botton, xPos,yPos
void mouse(int, int, int, int); // 1-int for up , down 2- left , right 3- for x 4- for y 

int main(int argc, char** argv) {
	// glut init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	// end of glut init 
	// create window

	width = GetSystemMetrics(SM_CXSCREEN);
	height = GetSystemMetrics(SM_CYSCREEN);

	//glutInitWindowSize(width, height);
	//glutInitWindowPosition(10, 10);
	glutCreateWindow("Second Section");
	glutFullScreen();
	// end create window

	// start call back functions
	// علشان ارسم استخدم ال call back function
	glutDisplayFunc(draw);
	// الحدود بتاعه الرسم علي المحور x , y من -1 1  -1 1
	glutReshapeFunc(reshape); // used this fun if the user make resize
	glutTimerFunc(0, timer, 0);
	glutKeyboardFunc(keyboarddown);
	glutKeyboardUpFunc(keyboardup);

	glutSpecialFunc(keySpecialdown);
	glutSpecialUpFunc(keySpecialup);
	glutMouseFunc(mouse);
	// end start call back functions 
	// main loop

	glutMainLoop();


}
void draw() {

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	//
	//glEnable(GL_POINT_SMOOTH);// TO CONVERT THE SQUARE TO CYRCILE
	//glPointSize(30); // FUNCTION USED TO LARG THE SIZE

	glLineWidth(3);
	glColor3f(c1, 0, 1);
	glBegin(GL_LINE_STRIP);
	for (float i = 0; i <= 2*PI; i += PI/500) {
		glVertex2f(cx + cos(i)*r, cy + sin(i)*r);
	}
	
	glEnd();

	glColor3f(0, qc, 0 );
	glBegin(GL_QUADS);
	glVertex2f(-5, 2);
	glVertex2f(-7, 2);
	glVertex2f(-7, 0);
	glVertex2f(-5, 0);
	

	glutSwapBuffers();
}

void reshape(int w, int h) {

	// to make the borders dynamic we use define var
	float ratio;
	if (h == 0)
		h = 1;
	ratio = (float)w / h;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w >= h)
		gluOrtho2D(-10 * ratio, 10 * ratio, -10, 10); // is statis borders 
	else
		gluOrtho2D(-10, 10, -10 / ratio, 10 / ratio);
	glMatrixMode(GL_MODELVIEW);
	; // arg represent width , hight
	//glViewport(0, 0, w, h);// الجزء المرئي فقط called custom
}

void backGround() {
	glClearColor(.5, .4, 1, 0);  // r , b , g , A
}

void timer(int v) {
	// repaint 
	glutPostRedisplay();
	glutTimerFunc(1000 / 25, timer, 0);
	cx = delcx;
	cy = delcy;
	//xq += deltaxq;
	//if (xq > sWidth - 2 || xq < -sWidth);
	//deltaxq = -deltaxq;

	//yq += deltaxq;
	//if (yq > sHeight - 2 || yq < -sHeight);
	 //    deltayq = -deltayq;
		// xp += deltaxp;

}

void keyboarddown(unsigned char key, int x, int y) {
	 // unsigned char asc for letter a , A 
	 // x , y mean the position op mouse for screen
	if (key == 'a' || key == 'A')
		delcx -= .3;
	else if (key == 'd' || key == 'D')
		delcx  += .3;
	else if (key == 'w' || key == 'W')
		delcy += .3;
	else if (key == 's' || key == 'S')
		delcy -= .3;
	else if (key == 27)
		exit(0);  // to make esc direct 
}
void keyboardup(unsigned char key , int x, int y) {

}

void keySpecialdown(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT)
		delcx -= .3;
	else if (key == GLUT_KEY_RIGHT)
		delcx += .3;
	else if (key == GLUT_KEY_UP)
		delcy += .3;
	else if (key == GLUT_KEY_DOWN)
		delcy -= .3;

	if (key == GLUT_KEY_F1);
	     fullScreen = !fullScreen;
		 if (fullScreen)
			 glutFullScreen();
		 else
		 {
			 glutReshapeWindow(width/2 , height/2); // if you want to chang window
			 glutPositionWindow(0, 0);//window at 0.0
			 glutPositionWindow(width / 2 - width / 4, height / 2 - height / 4);
		 }


}
void keySpecialup(int key, int x, int y) {



}


void mouse(int, int, int, int) {
	
}


// we will toke about Animation coloring and transformation:

*/


// this is may project  ما قبل التعديل 
/*

#include <windows.h> // to get screen size
#include<cmath>
#include <GL/glut.h>
float angle;
float xx1 = 0, yy1 = 0, xx2 = 0, yy2 = 0, xx3 = 0, yy3 = 0;//----------------------------------------------
float width, height;
float currentwidth;
float currentheight;
float xpos = 0;// var to change position of shapy in x axis
float ypos = 0;// var to change position of shapy in y axis
float r = 4, cx = 0, cy = 0, delcx, delcy, pi = 3.14159, col = .1, dell = .3;// r= radius.. cx,cy= center of circle(x,y)..delcx,delcy delta of change مقدار التغير في ال(x,y)
int directionx = 0;
int directiony = 0;
int rotat1 = 2, rotat2 = 2, rotat3 = 2;
float angle1, angle2, angle3;
bool fullScreen = true;

static int slices = 16;
static int stacks = 16;

bool stop = false;
void background();
void draw();
void reshape(int w, int h);
void timer(int);
void keyboarddown(unsigned char, int, int);// x and y ==> position of mouse in the screen for button has ascii
void keyspecialdown(int, int, int);

int rotat = 2;

void mouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		rotat1 = 1;
		rotat2 = 1;
		rotat3 = 1;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		rotat1 = 0;
		rotat2 = 0;
		rotat3 = 0;
		//glutPostRedisplay();
	}
	if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
		rotat1 = 2;
		rotat2 = 2;
		rotat3 = 2;
		//glutPostRedisplay();
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	width = GetSystemMetrics(SM_CXSCREEN);// to get width of screen
	height = GetSystemMetrics(SM_CYSCREEN);// علشان لو عاوز اعملهم فل اسكرين سواء للاكس او الواي (x,y)
	//	glutInitWindowSize(width, height);//full screen with title ==> must before create window // علشان اعرف الويندوا حجمها كام
	glutInitWindowPosition(10, 10);
	glutCreateWindow("first sec");
	glutFullScreen();
	// call backfounction
	glutDisplayFunc(draw);// الفانكشن البحط فيها الرسم بتاعي
	glutReshapeFunc(reshape); // الفانكشن ال ههندل فيها ال السيز بتاع الويندوا
	background();
	glutKeyboardFunc(keyboarddown);
	glutSpecialFunc(keyspecialdown);
	glutMouseFunc(mouseClick);
	glutTimerFunc(0, timer, 0); // الفانكشن ال ههندل فيها ال انيميشن بتاعي

	glutMainLoop();// علشان البرنامج يدخل معايا في انفنت لووب ويستمر

	return EXIT_SUCCESS;
}
void draw() {
	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	const double a = t * 90.0;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // to clear the colors علشان ابدا ارسم لازم استخدم هذه الفانكشن
	glLoadIdentity();// هذه الفانكشن بتستخدم في ال برنامج ديماا علشان لو حبيت تعمل تغير في حاجه لازم يسمع التغير في الكود

	// اي رسم بيتم في ال  opengl لازم يبقي محصور بين ال البدايه والنهايه
	glTranslatef(.1, 0, -9.9);// بينقل المحاور بتاعتي من خلال ال (x,y,z)
	glBegin(GL_QUADS);
	//back  all z cordinates is negative
	glColor3f(0.6274509803921569, 0.3725490196078431, 0);
	glVertex3f(9, -.3, -1);
	glVertex3f(-9, -.3, -1);
	glVertex3f(-9, -9, -1);
	glVertex3f(9, -9, -1);
	glEnd();

	//glLineWidth(10); to change line width
	// any transformation before the begin
	glLoadIdentity();
	glTranslatef(xx2, yy2, -7);
	glRotatef(angle2, 0, 1, 0);// angel,x,y,z // rotate for y axis
	glBegin(GL_TRIANGLES);

	//front
	glColor3f(0.8823529411764706, 0.6745098039215686, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);

	//RIGHT
	glColor3f(0.7725490196078431, 0.607843137254902, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(1, -1, -1);
	glVertex3f(1, -1, 1);

	//LEFT
	glColor3f(1, 0.8274509803921569, 0.0705882352941176);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);

	//back
	glColor3f(0.7294117647058824, 0.5333333333333333, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, -1);
	glVertex3f(1, -1, -1);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(.6, .2, .1);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);
	glVertex3f(-1, -1, -1);
	glEnd();


	glLoadIdentity();
	glTranslatef(xx1 - 3, yy1, -6.5);
	glRotatef(angle1, 0, 1, 0);

	glBegin(GL_TRIANGLES);

	//front
	glColor3f(0.8823529411764706, 0.6745098039215686, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);

	//RIGHT
	glColor3f(0.7725490196078431, 0.607843137254902, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(1, -1, -1);
	glVertex3f(1, -1, 1);

	//LEFT
	glColor3f(1, 0.8274509803921569, 0.0705882352941176);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);

	//back
	glColor3f(0.7294117647058824, 0.5333333333333333, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, -1);
	glVertex3f(1, -1, -1);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(.6, .2, .1);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);
	glVertex3f(-1, -1, -1);

	glEnd();

	glLoadIdentity();
	glTranslatef(xx3 + 3, yy3, -9);
	glRotatef(angle3, 0, 1, 0);
	glBegin(GL_TRIANGLES);

	//front
	glColor3f(0.8823529411764706, 0.6745098039215686, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);

	//RIGHT
	glColor3f(0.7725490196078431, 0.607843137254902, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(1, -1, -1);
	glVertex3f(1, -1, 1);

	//LEFT
	glColor3f(1, 0.8274509803921569, 0.0705882352941176);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);

	//back
	glColor3f(0.7294117647058824, 0.5333333333333333, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, -1);
	glVertex3f(1, -1, -1);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(.6, .2, .1);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);
	glVertex3f(-1, -1, -1);

	glEnd();


	glLoadIdentity();
	glColor3d(1, 1, 0);

	glPushMatrix();//---------------------------------------------------------------------
	glTranslated(-2, 2, -6);
	glRotated(60, 1, 0, 0);
	glRotated(a, 0, 0, 1);
	glutSolidSphere(1, slices, stacks);
	glPopMatrix();
	//----------------------------------------

	glutSwapBuffers();// علشان اغير بين التوو بفرز (front , back):

}
void background() {
	//glClearColor(r,g,b,a);
	//glClearColor(0.1568627450980392, 1, 0.9019607843137255, 1);// to change back ground color
	glClearColor(0, 0.6627450980392157, 0.9019607843137255, 1);// to change back ground color
	glEnable(GL_DEPTH_TEST);// بنستخدم هذه الفانكشن في ال 3دي علشان تمكني المحاور بتاعتي  (x , y , z) , تمكني اعمل 3دي من خلال العمق
}

void reshape(int w, int h) { // فيدتهاا انها بتحدد ال الارتفاع والعرض بتاع الويندوا ملهاش علاقه سواء شغال 3دي او 2دي
	float ratio;// علشان اتجنب القسمه علي 0
	if (h == 0)h = 1;
	ratio = (float)width / height;
	glViewport(0, 0, w, h); // من خلالهاا بنحدد الحدود بتاع الرسم .. كده معناها اني هرسم فش الشاشه كلها
	// 0 and 0 are dimentions
	glMatrixMode(GL_PROJECTION);//-----------------------------------------------------------------------------
	glLoadIdentity(); // uses when edit on matrix mode بستخدمها في اي مكان افضي فيها المتركس واستخدم قيم جديده

	gluPerspective(45, ratio, 1, 100);// angel of vision -> ratio -> nearst object-> farest object // المسئوله عن تحديد البعد ال بيمثله محور زيد زي ال بيتم علي ارض الواقع
	//gluPerspective()--> بتحددلي filed of view زاويه الروئيه بتاعتي ال بشوف بيها الشكل
	glMatrixMode(GL_MODELVIEW);

}

void timer(int v) {

	glutPostRedisplay();// redraw بمعني انها كل فتره من الزمن بترسم نفسها مره اخري
	//glutTimerFunc(1000/60,timer,0);
	glutTimerFunc(30, timer, 0);
	if (rotat1 == 1)angle1 += 1.9;
	else if (rotat1 == 0)angle1 -= 1.9;

	if (rotat2 == 1)angle2 += 1.9;
	else if (rotat2 == 0)angle2 -= 1.9;

	if (rotat3 == 1)angle3 += 1.9;
	else if (rotat3 == 0)angle3 -= 1.9;


	if (rotat1 == 2)angle1 = angle1;
	if (rotat2 == 2)angle2 = angle2;
	if (rotat3 == 2)angle3 = angle3;

}

void keyboarddown(unsigned char key, int x, int y)
{



	if (key == 27) exit(0); // exit(0): بمعني اني بقول لل operating system ان البروجكت بتاعي من غير مشاكل في وقت الرن
	if (key == 49) rotat1 = !rotat1;
	if (key == 50) rotat2 = !rotat2;
	if (key == 51) rotat3 = !rotat3;

	if (key == 52) rotat1 = 2;
	if (key == 53) rotat2 = 2;
	if (key == 54) rotat3 = 2;
	if (key == 48)
	{
		rotat1 = 2;
		rotat2 = 2;
		rotat3 = 2;
	}

	if (key == 'w' || key == 'W') yy2 += .3;
	if (key == 'A' || key == 'a') xx2 -= .3;
	if (key == 'S' || key == 's') yy2 -= .3;
	if (key == 'D' || key == 'd') xx2 += .3;


	if (key == 'T' || key == 't') yy3 += .3;
	if (key == 'F' || key == 'f') xx3 -= .3;
	if (key == 'G' || key == 'g') yy3 -= .3;
	if (key == 'H' || key == 'h') xx3 += .3;




}

void keyspecialdown(int key, int x, int y)
{
	if (key == GLUT_KEY_RIGHT) xx1 += .3;
	else  if (key == GLUT_KEY_LEFT) xx1 -= .3;
	else if (key == GLUT_KEY_UP) yy1 += .3;
	else if (key == GLUT_KEY_DOWN) yy1 -= .3;

	if (key == GLUT_KEY_F1) // لما اتغط علي اف 1 بحوله لحاجه ليها سيز و بوزشن
	{
		fullScreen = !fullScreen;
		if (fullScreen)
		{
			glutFullScreen();
		}
		else
		{
			glutReshapeWindow(width / 2, height / 2);
			glutPositionWindow(width / 4, height / 4);
		}
	}
}

*/

#include <windows.h>
#include<cmath>
#include <GL/glut.h>
float angle;
float xx1 = 0, yy1 = 0, xx2 = 0, yy2 = 0, xx3 = 0, yy3 = 0;
float width, height;// خاصين بالشاشه بتاعه الجهاز (el screen) 

float currentheight;

int rotat1 = 2, rotat2 = 2, rotat3 = 2;
float angle1, angle2, angle3;
bool fullScreen = true;

//bool stop = false;
void background();
void draw();
void reshape(int w, int h);
void timer(int);
void keyboarddown(unsigned char, int, int);// x and y ==> position of mouse in the screen for button has ascii
void keyspecialdown(int, int, int);

//int rotat = 2;

void mouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		rotat1 = 1;
		rotat2 = 1;
		rotat3 = 1;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		rotat1 = 0;
		rotat2 = 0;
		rotat3 = 0;
		//glutPostRedisplay();
	}
	if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
		rotat1 = 2;
		rotat2 = 2;
		rotat3 = 2;
		//glutPostRedisplay();
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	width = GetSystemMetrics(SM_CXSCREEN);// to get width of screen  علشان اجيب محور x 
	height = GetSystemMetrics(SM_CYSCREEN); // علشان اجيب الارتفاع بتاع محور  y 
	//	glutInitWindowSize(width, height);//full screen with title ==> must before create window
	glutInitWindowPosition(10, 10);
	glutCreateWindow("first sec"); // شاشه اللعبه 
	glutFullScreen();
	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
	background();
	glutKeyboardFunc(keyboarddown);
	glutSpecialFunc(keyspecialdown);
	glutMouseFunc(mouseClick);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();

	return EXIT_SUCCESS;
}
void draw() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // to clear the colors
	glLoadIdentity();

	glTranslatef(.1, 0, -9.9);
	glBegin(GL_QUADS);

	//back  all z cordinates is negative
	glColor3f(0.6274509803921569, 0.3725490196078431, 0);

	glVertex3f(9, -.3, -1);
	glVertex3f(-9, -.3, -1);
	glVertex3f(-9, -9, -1);
	glVertex3f(9, -9, -1);

	glEnd();

	// any transformation before the begin
	glLoadIdentity();
	glTranslatef(xx2, yy2, -7);
	glRotatef(angle2, 0, 1, 0);// angel,x,y,z
	glBegin(GL_TRIANGLES);
	//front

	glColor3f(0.8823529411764706, 0.6745098039215686, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	//RIGHT

	glColor3f(0.7725490196078431, 0.607843137254902, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(1, -1, -1);
	glVertex3f(1, -1, 1);

	//LEFT

	glColor3f(1, 0.8274509803921569, 0.0705882352941176);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);
	//back

	glColor3f(0.7294117647058824, 0.5333333333333333, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, -1);
	glVertex3f(1, -1, -1);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(.6, .2, .1);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);
	glVertex3f(-1, -1, -1);

	glEnd();

	glLoadIdentity();
	glTranslatef(xx1 - 3, yy1, -6.5);
	glRotatef(angle1, 0, 1, 0);

	glBegin(GL_TRIANGLES);
	//front

	glColor3f(0.8823529411764706, 0.6745098039215686, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	//RIGHT

	glColor3f(0.7725490196078431, 0.607843137254902, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(1, -1, -1);
	glVertex3f(1, -1, 1);

	//LEFT

	glColor3f(1, 0.8274509803921569, 0.0705882352941176);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);
	//back

	glColor3f(0.7294117647058824, 0.5333333333333333, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, -1);
	glVertex3f(1, -1, -1);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(.6, .2, .1);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);
	glVertex3f(-1, -1, -1);

	glEnd();

	glLoadIdentity();
	glTranslatef(xx3 + 3, yy3, -9);
	glRotatef(angle3, 0, 1, 0);
	glBegin(GL_TRIANGLES);
	//front

	glColor3f(0.8823529411764706, 0.6745098039215686, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	//RIGHT

	glColor3f(0.7725490196078431, 0.607843137254902, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(1, -1, -1);
	glVertex3f(1, -1, 1);

	//LEFT

	glColor3f(1, 0.8274509803921569, 0.0705882352941176);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);
	//back

	glColor3f(0.7294117647058824, 0.5333333333333333, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, -1);
	glVertex3f(1, -1, -1);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(.6, .2, .1);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);
	glVertex3f(-1, -1, -1);

	glEnd();
	glLoadIdentity();

	glColor3d(1, 1, 0);

	//  glPushMatrix();
	glTranslated(-2, 2, -6);

	glutSolidSphere(.4, 17, 17);
	//  glPopMatrix();
	glutSwapBuffers();

}
void background() {
	//glClearColor(r,g,b,a);

	glClearColor(0, 0.6627450980392157, 0.9019607843137255, 1);// to change back ground color
	glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h) {
	float ratio;
	if (h == 0)h = 1;
	ratio = (float)width / height;
	glViewport(0, 0, w, h);
	// 0 and 0 are dimentions
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // uses when edit on matrix mode

	gluPerspective(45, ratio, 1, 100);// angel of vision -> ratio -> nearst object-> farest object

	glMatrixMode(GL_MODELVIEW);

}

void timer(int v) {

	glutPostRedisplay();// redraw
	//glutTimerFunc(1000/60,timer,0);
	glutTimerFunc(30, timer, 0);
	if (rotat1 == 1)angle1 += 1.9;
	else if (rotat1 == 0)angle1 -= 1.9;

	if (rotat2 == 1)angle2 += 1.9;
	else if (rotat2 == 0)angle2 -= 1.9;

	if (rotat3 == 1)angle3 += 1.9;
	else if (rotat3 == 0)angle3 -= 1.9;

	if (rotat1 == 2)angle1 = angle1;
	if (rotat2 == 2)angle2 = angle2;
	if (rotat3 == 2)angle3 = angle3;

}

void keyboarddown(unsigned char key, int x, int y)
{

	if (key == 27) exit(0);
	if (key == 49) rotat1 = !rotat1;
	if (key == 50) rotat2 = !rotat2;
	if (key == 51) rotat3 = !rotat3;

	if (key == 52) rotat1 = 2;
	if (key == 53) rotat2 = 2;
	if (key == 54) rotat3 = 2;
	if (key == 48)
	{
		rotat1 = 2;
		rotat2 = 2;
		rotat3 = 2;
	}

	if (key == 'w' || key == 'W') yy2 += .3;
	if (key == 'A' || key == 'a') xx2 -= .3;
	if (key == 'S' || key == 's') yy2 -= .3;
	if (key == 'D' || key == 'd') xx2 += .3;

	if (key == 'T' || key == 't') yy3 += .3;
	if (key == 'F' || key == 'f') xx3 -= .3;
	if (key == 'G' || key == 'g') yy3 -= .3;
	if (key == 'H' || key == 'h') xx3 += .3;

}

void keyspecialdown(int key, int x, int y)
{
	if (key == GLUT_KEY_RIGHT) xx1 += .3;
	else  if (key == GLUT_KEY_LEFT) xx1 -= .3;
	else if (key == GLUT_KEY_UP) yy1 += .3;
	else if (key == GLUT_KEY_DOWN) yy1 -= .3;
	if (key == GLUT_KEY_F1)
	{
		fullScreen = !fullScreen;
		if (fullScreen)
		{
			glutFullScreen();
		}
		else
		{
			glutReshapeWindow(width / 2, height / 2);
			glutPositionWindow(width / 4, height / 4);
		}
	}
}
