#ifndef MYINIT
#define MYINIT

#include "sysincludes.h"        
#include "globals.h"

GLUquadric *earth;

void loadTextures();

GLfloat material_diffuse[4];
GLfloat material_ambient[4];
GLfloat material_emission[4];
GLfloat material_specular[4];

GLfloat light_0_position[4];



void myInit(){

// This sets up most of the OpenGL options

    glClearColor(0.0,0.0,0.0,0.0);

// Set up a 3D Viewing perspective pulled back from the X-Y plane looking down
// at the first quadrant.

    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT);

    gluLookAt(  0.0,   0.0,   0.0,  // Eye
                5.0,   5.0, 5.0,  // Center
                0.0,   0.0, 1.0); // Up


#ifdef DEBUG
    printf( "OpenGL Version: %s\n", glGetString(GL_VERSION)); 
#endif

    loadTextures();

    earth = gluNewQuadric();
    gluQuadricTexture( earth, GL_TRUE);

// Now start working on lighting -- these are material properties

   material_diffuse = { 1.0, 1.0, 1.0, 1.0 };
   material_ambient = { 1.0, 1.0, 1.0, 1.0 };
   material_emission = { 1.0, 1.0, 1.0, 1.0 };
   material_specular = { 1.0, 1.0, 1.0, 1.0 };

   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
   glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_emission);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
//   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 25.0);

   light_0_position = { 10.0, 10.0, 10.0, 1.0 };

   glLightfv(GL_LIGHT0, GL_POSITION, light_0_position);


   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);

}


#endif 
