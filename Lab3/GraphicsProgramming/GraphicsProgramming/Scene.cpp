#include "Scene.h"

Scene::Scene(Input *in)
{
	// Store pointer for input class
	input = in;
		
	//OpenGL settings
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.39f, 0.58f, 93.0f, 1.0f);			// Cornflour Blue Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glEnable(GL_LIGHTING);								// Enable Lighting

	// Other OpenGL / render setting should be applied here.
	populateLightAmbient(0, 0, 1, 1, Light_Ambient);
	populateLightAmbient(0, 1, 1, 0, Light_Ambient1);
	populateLightDiffuse(0, 1, 1, 1, Light_Diffuse);
	populateLightPosition(0, -1, 0, 1, Light_Position);
	populateLightPosition(0, 0, 0, 1, Light_Position1);
	populateSpotDirection(0, -1, 0, 0, spot_Direction);

	// Initialise variables
	rotation = 1;
	rotation = 1;
	speed = 5;
}

void Scene::update(float dt)
{
	// Handle user input
	// Update object and variables (camera, rotation, etc).

	// Calculate FPS
	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);

	if (time - timebase > 1000) {
		sprintf_s(fps, "FPS: %4.2f", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}

	rotation += speed * dt;
	rotation2 += (speed * 2) * dt;
	Light_Position[2] += speed * dt;
}


void Scene::render() {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(0.0f, 0.0f, 6.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(20, 1, 0, 0); // Rotate by x-axis

	glPushMatrix();
	//glRotatef(rotation, 0.0f, 1.0f, 0.0f);
	glLightfv(GL_LIGHT0, GL_AMBIENT, Light_Ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Light_Diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, Light_Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_Direction);
	glEnable(GL_LIGHT0);
	glPopMatrix();

	

	glPushMatrix();
	glBegin(GL_POINT);
		glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();
		glPushMatrix();
			glRotatef(rotation, 0.0f, 1.0f, 0.0f);
			glTranslatef(2, 0, 0);
			glLightfv(GL_LIGHT1, GL_AMBIENT, Light_Ambient1);
			glLightfv(GL_LIGHT0, GL_POSITION, Light_Position1);
			gluSphere(gluNewQuadric(), 0.20, 20, 20);
			glEnable(GL_LIGHT1);
		glPopMatrix();
	glPopMatrix();
	// Render geometry here -------------------------------------
	glBegin(GL_QUADS);
	//Front 
	glColor3f(0.0f, 0.0f, 1.0f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);

	//Right 
	glColor3f(0.0f, 1.0f, 0.0f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	//back
	glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	//left
	glColor3f(0.0f, 1.0f, 1.0f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);

	//top
	glColor3f(1.0f, 0.0f, 1.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);

	//bottom
	glColor3f(1.0f, 1.0f, 1.0f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	glEnd();
	glPopMatrix();
	
	//glBegin(GL_TRIANGLES);
	//// front face
	//glColor3f(1.0f, 0.0f, 0.0f);	
	//glNormal3f(0.0f, 0.0f, 1.0f);
	//glVertex3f(0.0f, 0.0f, 0.0f);/////////////
	//glNormal3f(0.0f, 0.0f, 1.0f);
	//glVertex3f(0.0f, 1.0f, 0.0f);/////////////
	//glNormal3f(0.0f, 0.0f, 1.0f);
	//glVertex3f(1.0f, 1.0f, 0.0f);/////////////
	//glNormal3f(0.0f, 0.0f, 1.0f);
	//glVertex3f(1.0f, 1.0f, 0.0f);/////////////
	//glNormal3f(0.0f, 0.0f, 1.0f);
	//glVertex3f(1.0f, 0.0f, 0.0f);/////////////
	//glNormal3f(0.0f, 0.0f, 1.0f);
	//glVertex3f(0.0f, 0.0f, 0.0f);/////////////
	//// left face
	//glColor3f(1.0f, 0.0f, 0.0f);
	//glNormal3f(0.0f, 0.0f, 1.0f);
	//glVertex3f(0.0f, 0.0f, 0.0f);/////////////
	//glNormal3f(0.0f, 0.0f, 1.0f);
	//glVertex3f(0.0f, 0.0f, -1.0f);/////////////
	//glNormal3f(0.0f, 0.0f, 1.0f);
	//glVertex3f(0.0f, 1.0f, 0.0f);/////////////
	//glNormal3f(0.0f, 0.0f, 1.0f);
	//glVertex3f(0.0f, 0.0f, -1.0f);/////////////
	//glNormal3f(0.0f, 0.0f, 1.0f);
	//glVertex3f(0.0f, 1.0f, -1.0f);/////////////
	//glNormal3f(0.0f, 0.0f, 1.0f);
	//glVertex3f(0.0f, 1.0f, 0.0f);/////////////
	//// bottom face
	//glColor3f(1.0f, 0.0f, 0.0f);
	//glNormal3f(0.0f, 1.0f, 0.0f);
	//glVertex3f(0.0f, 0.0f, 0.0f);/////////////
	//glNormal3f(0.0f, -1.0f, 0.0f);
	//glVertex3f(1.0f, 0.0f, 0.0f);/////////////
	//glNormal3f(0.0f, -1.0f, 0.0f);
	//glVertex3f(1.0f, 0.0f, -1.0f);/////////////
	//glNormal3f(0.0f, -1.0f, 0.0f);
	//glVertex3f(1.0f, 0.0f, -1.0f);/////////////
	//glNormal3f(0.0f, -1.0f, 0.0f);
	//glVertex3f(0.0f, 0.0f, -1.0f);/////////////
	//glNormal3f(0.0f, -1.0f, 0.0f);
	//glVertex3f(0.0f, 0.0f, 0.0f);/////////////

	//glEnd();

	// Geometry rendering ends here -----------------------------
	// Render text, should be last object rendered.
	renderTextOutput();
	
	// Swap buffers, after all objects are rendered.
	glutSwapBuffers();
}

void Scene::resize(int w, int h) 
{
	width = w;
	height = h;
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = (float)w / (float)h;
	fov = 45.0f;
	nearPlane = 0.1f;
	farPlane = 100.0f;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(fov, ratio, nearPlane, farPlane);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void Scene::renderTextOutput()
{
	// Render current mouse position and frames per second.
	sprintf_s(mouseText, "Mouse: %i, %i", input->getMouseX(), input->getMouseY());
	displayText(-1.f, 0.96f, 1.f, 0.f, 0.f, mouseText);
	displayText(-1.f, 0.90f, 1.f, 0.f, 0.f, fps);
}

void Scene::displayText(float x, float y, float r, float g, float b, char* string) {
	// Get Lenth of string
	int j = strlen(string);

	// Swap to 2D rendering
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 5, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Orthographic lookAt (along the z-axis).
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Set text colour and position.
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	// Render text.
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
	}
	// Reset colour to white.
	glColor3f(1.f, 1.f, 1.f);

	// Swap back to 3D rendering.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, ((float)width/(float)height), nearPlane, farPlane);
	glMatrixMode(GL_MODELVIEW);
}

GLfloat* Scene::populateLightAmbient(float x, float y, float z, float w, GLfloat* lightAmbient) {
	lightAmbient[0] = x;
	lightAmbient[1] = y;
	lightAmbient[2] = z;
	lightAmbient[3] = w;

	return lightAmbient;
}

GLfloat* Scene::populateLightDiffuse(float x, float y, float z, float w, GLfloat* lightDiffuse) {
	lightDiffuse[0] = x;
	lightDiffuse[1] = y;
	lightDiffuse[2] = z;
	lightDiffuse[3] = w;

	return lightDiffuse;
}

GLfloat* Scene::populateLightPosition(float x, float y, float z, float w, GLfloat* lightPosition) {
	lightPosition[0] = x;
	lightPosition[1] = y;
	lightPosition[2] = z;
	lightPosition[3] = w;

	return lightPosition;
}

GLfloat* Scene::populateSpotDirection(float x, float y, float z, float w, GLfloat* spotDirection) {
	spotDirection[0] = x;
	spotDirection[1] = y;
	spotDirection[2] = z;
	spotDirection[3] = w;

	return spotDirection;
}