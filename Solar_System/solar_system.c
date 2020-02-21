#include <stdio.h>			
#include <stdarg.h>					
#include <stdlib.h>
#include<GL\freeglut.h>
#include<GL\glut.h>
#include<GL\GL.h>
#include<GL\GLU.h>

// Édi Aires , nº 33734
//José Pascoal, nº 34157



struct Image {
	unsigned long sizeX;
	unsigned long sizeY;
	char *data;
};

typedef struct Image Image;

GLuint texture_id[12];


typedef struct Planet
{
	float radius;
	float distance;
	float orbit;
	float orbitSpeed;
	float axisTilt;
	float axisAni;
};

float mercuryOrbit = 0;
float mercuryOrbitSpeed = 4.74;
float mercuryAxisAni = 0;

float venusOrbit = 0;
float venusOrbitSpeed = 3.50;
float venusAxisAni = 0;

float earthOrbit = 0;
float earthOrbitSpeed = 2.98;
float earthAxisAni = 0;

float marsOrbit = 0;
float marsOrbitSpeed = 2.41;
float marsAxisAni = 0;

float jupiterOrbit = 0;
float jupiterOrbitSpeed = 1.31;
float jupiterAxisAni = 0;

float saturnOrbit = 0;
float saturnOrbitSpeed = 0.97;
float saturnAxisAni = 0;

float uranusOrbit = 0;
float uranusOrbitSpeed = 0.68;
float uranusAxisAni = 0;

float neptuneOrbit = 0;
float neptuneOrbitSpeed = 0.54;
float neptuneAxisAni = 0;

float plutoOrbit = 0;
float plutoOrbitSpeed = 0.47;
float plutoAxisAni = 0;

int changeCamera = 0;
int zoom = 60;
int showOrbit = 0;
int labelActive = 0;

void writeBitmapString(void *font, char *string)
{
	char *c;
	for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

void orbitalTrails(float distance) 
{
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutWireTorus(0.001, distance, 100.0, 100.0);
	glPopMatrix();
}
void drawScene()
{
	//Sun, Planets and Stars
	struct Planet sun, mercury,venus,earth,mars,jupiter,saturn,uranus,neptune,pluto;

	//sun
	sun.radius = 5.0;
	sun.distance = 0;
	sun.orbit = 0;
	sun.orbitSpeed = 0;
	sun.axisTilt = 0;
	sun.axisAni = 0;

	//mercury
	mercury.radius = 1.0;
	mercury.distance = 7;
	mercury.orbit = mercuryOrbit;
	mercury.orbitSpeed = mercuryOrbitSpeed;
	mercury.axisTilt = 02.11;
	mercury.axisAni = mercuryAxisAni;

	//venus
	venus.radius = 1.5;
	venus.distance = 11;
	venus.orbit = venusOrbit;
	venus.orbitSpeed = venusOrbitSpeed;
	venus.axisTilt = 177.0;
	venus.axisAni = venusAxisAni;

	//earth
	earth.radius = 2.0;
	earth.distance = 16;
	earth.orbit = earthOrbit;
	earth.orbitSpeed = earthOrbitSpeed;
	earth.axisTilt = 23.44;
	earth.axisAni = earthAxisAni;

	//mars
	mars.radius = 1.2;
	mars.distance = 21;
	mars.orbit = marsOrbit;
	mars.orbitSpeed = marsOrbitSpeed;
	mars.axisTilt = 25.00;
	mars.axisAni = marsAxisAni;

	//jupiter
	jupiter.radius = 3.5;
	jupiter.distance = 28;
	jupiter.orbit = jupiterOrbit;
	jupiter.orbitSpeed = jupiterOrbitSpeed;
	jupiter.axisTilt = 03.13;
	jupiter.axisAni = jupiterAxisAni;

	//saturn
	saturn.radius = 3.0;
	saturn.distance = 37;
	saturn.orbit = saturnOrbit;
	saturn.orbitSpeed = saturnOrbitSpeed;
	saturn.axisTilt = 26.70;
	saturn.axisAni = saturnAxisAni;

	//uranus
	uranus.radius = 2.5;
	uranus.distance = 45.5;
	uranus.orbit = uranusOrbit;
	uranus.orbitSpeed = uranusOrbitSpeed;
	uranus.axisTilt = 97.77;
	uranus.axisAni = uranusAxisAni;

	//neptune
	neptune.radius = 2.3;
	neptune.distance = 53.6;
	neptune.orbit = neptuneOrbit;
	neptune.orbitSpeed = neptuneOrbitSpeed;
	neptune.axisTilt = 28.32;
	neptune.axisAni = neptuneAxisAni;

	//pluto
	pluto.radius = 0.3;
	pluto.distance = 59;
	pluto.orbit = plutoOrbit;
	pluto.orbitSpeed = plutoOrbitSpeed;
	pluto.axisTilt = 119.6;
	pluto.axisAni = plutoAxisAni;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//gluLookAt(0.0, 20, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	if (changeCamera == 0)gluLookAt(0.0, zoom, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	if (changeCamera == 1)gluLookAt(0.0, 0.0, zoom, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	if (changeCamera == 2)gluLookAt(0.0, zoom, 0.00001, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);



	GLUquadric *quadric;
	quadric = gluNewQuadric();


	//sun
	glPushMatrix();
	glRotatef(sun.orbit, 0.0, 1.0, 0.0);
	glTranslatef(sun.distance, 0.0, 0.0);
	//glColor3ub(255, 0, 0);
	if (labelActive == 1) {
		glRasterPos3f(-1.2, 7.0, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_HELVETICA_12, "Sun");
	}
		glPushMatrix();
		glRotatef(sun.axisTilt, 1.0, 0.0, 0.0);
		glRotatef(sun.axisAni, 0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture_id[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		gluQuadricTexture(quadric, 1);
		gluSphere(quadric, sun.radius, 20.0, 20.0);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	glPopMatrix();

	//Mercury
	glPushMatrix();
	glRotatef(mercury.orbit, 0.0, 1.0, 0.0);
	glTranslatef(mercury.distance, 0.0, 0.0);
	//glColor3f(0, 1, 1);
	if (labelActive == 1) {
		glRasterPos3f(0.0, 3, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_HELVETICA_12, "Mercury");
	}
		glPushMatrix();
		glRotatef(mercury.axisTilt, 1.0, 0.0, 0.0);
		glRotatef(mercury.axisAni, 0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture_id[1]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		gluQuadricTexture(quadric, 1);
		gluSphere(quadric, mercury.radius, 20.0, 20.0);
		glDisable(GL_TEXTURE_2D);

		glPopMatrix();
	glPopMatrix();


	//Venus
	glPushMatrix();
	glRotatef(venus.orbit, 0.0, 1.0, 0.0);
	glTranslatef(venus.distance, 0.0, 0.0);
	//glColor3f(1, 1,0 );
	if (labelActive == 1) {
		glRasterPos3f(0.0, 3, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_HELVETICA_12, "Venus");
	}
		glPushMatrix();
		glRotatef(venus.axisTilt, 1.0, 0.0, 0.0);
		glRotatef(venus.axisAni, 0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture_id[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		gluQuadricTexture(quadric, 1);
		gluSphere(quadric, venus.radius, 20.0, 20.0);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	glPopMatrix();

	//Earth
	glPushMatrix();
	glRotatef(earth.orbit, 0.0, 1.0, 0.0);
	glTranslatef(earth.distance, 0.0, 0.0);
	//glColor3f(0, 1, 0);
	if (labelActive == 1) {
		glRasterPos3f(0.0, 3, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_HELVETICA_12, "Earth");
	}
		glPushMatrix();
		glRotatef(earth.axisTilt, 1.0, 0.0, 0.0);
		glRotatef(earth.axisAni, 0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture_id[3]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		gluQuadricTexture(quadric, 1);
		gluSphere(quadric, earth.radius, 20.0, 20.0);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	glPopMatrix();

	//Mars
	glPushMatrix();
	glRotatef(mars.orbit, 0.0, 1.0, 0.0);
	glTranslatef(mars.distance, 0.0, 0.0);
	//glColor3f(1, 0, 1);
	if (labelActive == 1) {
		glRasterPos3f(0.0, 3, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_HELVETICA_12, "Mars");
	}
		glPushMatrix();
		glRotatef(mars.axisTilt, 1.0, 0.0, 0.0);
		glRotatef(mars.axisAni, 0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture_id[4]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		gluQuadricTexture(quadric, 1);
		gluSphere(quadric, mars.radius, 20.0, 20.0);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

	glPopMatrix();

	//Jupiter
	glPushMatrix();
	glRotatef(jupiter.orbit, 0.0, 1.0, 0.0);
	glTranslatef(jupiter.distance, 0.0, 0.0);
	//glColor3f(1, 1, 1);
	if (labelActive == 1) {
		glRasterPos3f(0.0, 4.4, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_HELVETICA_12, "Jupiter");
	}
		glPushMatrix();
		glRotatef(jupiter.axisTilt, 1.0, 0.0, 0.0);
		glRotatef(jupiter.axisAni, 0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture_id[5]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		gluQuadricTexture(quadric, 1);
		gluSphere(quadric, jupiter.radius, 20.0, 20.0);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Saturn
	glPushMatrix();
	glRotatef(saturn.orbit, 0.0, 1.0, 0.0);
	glTranslatef(saturn.distance, 0.0, 0.0);
	//glColor3f(1, 1, 0);
	if (labelActive == 1) {
		glRasterPos3f(0.0, 4.4, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_HELVETICA_12, "Saturn");
	}
		glPushMatrix();
		glRotatef(saturn.axisTilt, 1.0, 0.0, 0.0);
		glRotatef(saturn.axisAni, 0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture_id[6]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		gluQuadricTexture(quadric, 1);
		gluSphere(quadric, saturn.radius, 20.0, 20.0);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

			glPushMatrix();
			glColor3ub(158, 145, 137);
			glRotatef(-63.0, 1.0, 0.0, 0.0);
			glutWireTorus(0.2, 6.0, 30.0, 30.0);
			glutWireTorus(0.4, 5.0, 30.0, 30.0);
			glPopMatrix();

	glPopMatrix();


	//Uranus
	glPushMatrix();
	glRotatef(uranus.orbit, 0.0, 1.0, 0.0);
	glTranslatef(uranus.distance, 0.0, 0.0);
	//glColor3f(0, 0, 1);
	if (labelActive == 1) {
		glRasterPos3f(0.0, 4.4, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_HELVETICA_12, "Uranus");
	}
		glPushMatrix();
		glRotatef(uranus.axisTilt, 1.0, 0.0, 0.0);
		glRotatef(uranus.axisAni, 0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture_id[7]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		gluQuadricTexture(quadric, 1);
		gluSphere(quadric, uranus.radius, 20.0, 20.0);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

	glPopMatrix();

	//Neptune
	glPushMatrix();
	glRotatef(neptune.orbit, 0.0, 1.0, 0.0);
	glTranslatef(neptune.distance, 0.0, 0.0);
	//glColor3f(1, 0, 1);
	if (labelActive == 1) {
		glRasterPos3f(0.0, 4.4, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_HELVETICA_12, "Neptune");
	}
		glPushMatrix();
		glRotatef(neptune.axisTilt, 1.0, 0.0, 0.0);
		glRotatef(neptune.axisAni, 0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture_id[8]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		gluQuadricTexture(quadric, 1);
		gluSphere(quadric, neptune.radius, 20.0, 20.0);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

	glPopMatrix();

	//Pluto
	glPushMatrix();
	glRotatef(pluto.orbit, 0.0, 1.0, 0.0);
	glTranslatef(pluto.distance, 0.0, 0.0);
	if (labelActive == 1) {
		glRasterPos3f(0.0, 3.0, 0.0);
		glColor3ub(255, 255, 255);
		writeBitmapString(GLUT_BITMAP_HELVETICA_12, "Pluto");
	}
		glPushMatrix();
		glRotatef(pluto.axisTilt, 1.0, 0.0, 0.0);
		glRotatef(pluto.axisAni, 0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture_id[9]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		gluQuadricTexture(quadric, 1);
		gluSphere(quadric, pluto.radius, 20.0, 20.0);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

	glPopMatrix();

	//stars
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_id[10]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBegin(GL_POLYGON);
	glTexCoord2f(-1.0, 0.0); glVertex3f(-200, -200, -100);
	glTexCoord2f(2.0, 0.0); glVertex3f(200, -200, -100);
	glTexCoord2f(2.0, 2.0); glVertex3f(200, 200, -100);
	glTexCoord2f(-1.0, 2.0); glVertex3f(-200, 200, -100);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture_id[10]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(-200, -83, 200);
	glTexCoord2f(8.0, 0.0); glVertex3f(200, -83, 200);
	glTexCoord2f(8.0, 8.0); glVertex3f(200, -83, -200);
	glTexCoord2f(0.0, 8.0); glVertex3f(-200, -83, -200);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	if (showOrbit == 0)
	{
		float d1 = mercury.distance;
		orbitalTrails(d1);

		float d2 = venus.distance;
		orbitalTrails(d2);

		float d3 = earth.distance;
		orbitalTrails(d3);

		float d4 = mars.distance;
		orbitalTrails(d4);

		float d5 = jupiter.distance;
		orbitalTrails(d5);

		float d6 = saturn.distance;
		orbitalTrails(d6);

		float d7 = uranus.distance;
		orbitalTrails(d7);

		float d8 = neptune.distance;
		orbitalTrails(d8);

		float d9 = pluto.distance;
		orbitalTrails(d9);
	}
	glutSwapBuffers();

}

void resize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
}

void animate(int n)
{
	
	mercuryOrbit += mercuryOrbitSpeed;
	venusOrbit += venusOrbitSpeed;
	earthOrbit += earthOrbitSpeed;
	marsOrbit += marsOrbitSpeed;
	jupiterOrbit += jupiterOrbitSpeed;
	saturnOrbit += saturnOrbitSpeed;
	uranusOrbit += uranusOrbitSpeed;
	neptuneOrbit += neptuneOrbitSpeed;
	plutoOrbit += plutoOrbitSpeed;
	
	
	if (mercuryOrbit > 360.0 &&  venusOrbit> 360.0 && earthOrbit > 360.0 && marsOrbit> 360.0 && jupiterOrbit> 360.0 && saturnOrbit> 360.0 && uranusOrbit> 360.0 && neptuneOrbit> 360.0 && plutoOrbit>360)
	{
		mercuryOrbit -= 360.0;
		venusOrbit -= 360.0;
		earthOrbit -= 360.0;
		marsOrbit -= 360.0;
		jupiterOrbit -= 360.0;
		saturnOrbit -= 360.0;
		uranusOrbit -= 360.0;
		neptuneOrbit -= 360.0;
		plutoOrbit -= 360;
	}
	

	mercuryAxisAni += 10.0;
	venusAxisAni += 10.0;
	earthAxisAni += 10.0;
	marsAxisAni += 10.0;
	jupiterAxisAni += 10.0;
	saturnAxisAni += 10.0;
	uranusAxisAni += 10.0;
	neptuneAxisAni += 10.0;
	plutoAxisAni += 10.0;
	
	
	if (mercuryAxisAni> 360.0 &&venusAxisAni > 360.0 && earthAxisAni> 360.0 && marsAxisAni> 360.0 && jupiterAxisAni> 360.0 && saturnAxisAni> 360.0 && uranusAxisAni> 360.0 && neptuneAxisAni> 360.0 && plutoAxisAni>360)
	{
		mercuryAxisAni -= 360.0;
		venusAxisAni -= 360.0;
		earthAxisAni -= 360.0;
		marsAxisAni -= 360.0;
		jupiterAxisAni -= 360.0;
		saturnAxisAni -= 360.0;
		uranusAxisAni -= 360.0;
		neptuneAxisAni -= 360.0;
		plutoAxisAni -= 360;

	}
	

	glutPostRedisplay();
	glutTimerFunc(30, animate, 1);
}


static unsigned int getint(FILE *fp)
{
	int c, c1, c2, c3;

	/*  get 4 bytes */
	c = getc(fp);
	c1 = getc(fp);
	c2 = getc(fp);
	c3 = getc(fp);

	return ((unsigned int)c) +
		(((unsigned int)c1) << 8) +
		(((unsigned int)c2) << 16) +
		(((unsigned int)c3) << 24);
}

static unsigned int getshort(FILE* fp)
{
	int c, c1;

	/* get 2 bytes*/
	c = getc(fp);
	c1 = getc(fp);

	return ((unsigned int)c) + (((unsigned int)c1) << 8);
}

//--------- loading image BMP

int LoadBMP(char *filename, Image *image) {
	FILE *file;
	unsigned long size;                 /*  size of the image in bytes. */
	unsigned long i;                    /*  standard counter. */
	unsigned short int planes;          /*  number of planes in image (must be 1)  */
	unsigned short int bpp;             /*  number of bits per pixel (must be 24) */
	char temp;                          /*  used to convert bgr to rgb color. */

										/*  make sure the file is there. */
	fopen_s(&file, filename, "rb") == NULL;
	if (file == NULL) {
		printf("File Not Found : %s\n", filename);
		return 0;
	}

	/*  seek through the bmp header, up to the width height: */
	fseek(file, 18, SEEK_CUR);

	/*  No 100% errorchecking anymore!!! */

	/*  read the width */    image->sizeX = getint(file);

	/*  read the height */
	image->sizeY = getint(file);

	/*  calculate the size (assuming 24 bits or 3 bytes per pixel). */
	size = image->sizeX * image->sizeY * 3;

	/*  read the planes */
	planes = getshort(file);
	if (planes != 1) {
		printf("Planes from %s is not 1: %u\n", filename, planes);
		return 0;
	}

	/*  read the bpp */
	bpp = getshort(file);
	if (bpp != 24) {
		printf("Bpp from %s is not 24: %u\n", filename, bpp);
		return 0;
	}

	/*  seek past the rest of the bitmap header. */
	fseek(file, 24, SEEK_CUR);

	/*  read the data.  */
	image->data = (char *)malloc(size);
	if (image->data == NULL) {
		printf("Error allocating memory for color-corrected image data");
		return 0;
	}

	if ((i = fread(image->data, size, 1, file)) != 1) {
		printf("Error reading image data from %s.\n", filename);
		return 0;
	}

	for (i = 0; i<size; i += 3) { /*  reverse all of the colors. (bgr -> rgb) */
		temp = image->data[i];
		image->data[i] = image->data[i + 2];
		image->data[i + 2] = temp;
	}

	fclose(file); /* Close the file and release the filedes */

				  /*  we're done. */
	return 1;
}

GLvoid LoadTexture(GLvoid)
{
	Image *TextureImage;

	TextureImage = (Image *)malloc(sizeof(Image));

	if (TextureImage == NULL)
	{
		printf("Error allocating space for image");
		exit(1);
	}


	LoadBMP("sun.bmp", TextureImage);

	glGenTextures(1, &texture_id[0]);

	glBindTexture(GL_TEXTURE_2D, texture_id[0]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		// Create The Texture

	LoadBMP("mercury.bmp", TextureImage);

	glGenTextures(1, &texture_id[1]);

	glBindTexture(GL_TEXTURE_2D, texture_id[1]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		// Create The Texture

	LoadBMP("venus.bmp", TextureImage);

	glGenTextures(1, &texture_id[2]);

	glBindTexture(GL_TEXTURE_2D, texture_id[2]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		// Create The Texture

	LoadBMP("earth.bmp", TextureImage);

	glGenTextures(1, &texture_id[3]);

	glBindTexture(GL_TEXTURE_2D, texture_id[3]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		// Create The Texture

	LoadBMP("mars.bmp", TextureImage);

	glGenTextures(1, &texture_id[4]);

	glBindTexture(GL_TEXTURE_2D, texture_id[4]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		// Create The Texture

	LoadBMP("jupiter.bmp", TextureImage);

	glGenTextures(1, &texture_id[5]);

	glBindTexture(GL_TEXTURE_2D, texture_id[5]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		// Create The Texture

	LoadBMP("saturn.bmp", TextureImage);

	glGenTextures(1, &texture_id[6]);

	glBindTexture(GL_TEXTURE_2D, texture_id[6]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		// Create The Texture

	LoadBMP("uranus.bmp", TextureImage);

	glGenTextures(1, &texture_id[7]);

	glBindTexture(GL_TEXTURE_2D, texture_id[7]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		// Create The Texture

	LoadBMP("neptune.bmp", TextureImage);

	glGenTextures(1, &texture_id[8]);

	glBindTexture(GL_TEXTURE_2D, texture_id[8]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		// Create The Texture

	LoadBMP("pluto.bmp", TextureImage);

	glGenTextures(1, &texture_id[9]);

	glBindTexture(GL_TEXTURE_2D, texture_id[9]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		// Create The Texture
	
	LoadBMP("stars.bmp", TextureImage);

	glGenTextures(1, &texture_id[10]);

	glBindTexture(GL_TEXTURE_2D, texture_id[10]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);		// Create The Texture

	free(TextureImage->data);
	free(TextureImage);
}

void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);

	LoadTexture();



}
void mouseWheel(int wheel, int direction, int x, int y)
{
	if (direction > 0 && zoom < 100) zoom=zoom+10;
	if (direction < 0 && zoom > -75) zoom=zoom-10  ;
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) 
	{
		case 27: exit(0); break;
		case '1': changeCamera = 0; glutPostRedisplay(); break;
		case '2': changeCamera = 1; glutPostRedisplay(); break;
		case '3': changeCamera = 2; glutPostRedisplay(); break;
		case 'o':
		{
				if (showOrbit == 0)
				{
					showOrbit = 1;
					break;
				}
				else
				{
					showOrbit = 0;
					break;
				}
	
		}

		case 'l':
		{
				if (labelActive == 0)
				{
					labelActive = 1;
					break;
				}
				else
				{
					labelActive = 0;
					break;
				}
		}
	}
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(500, 0);
	glutCreateWindow("Solar System");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseWheelFunc(mouseWheel);
	setup();
	animate(1);

	glutMainLoop();
}