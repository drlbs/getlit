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
GLfloat light_0_ambient[4];
GLfloat light_0_diffuse[4];
GLfloat light_0_specular[4];
GLfloat light_0_spot_direction[4];
GLfloat light_0_spot_cutoff;
GLfloat light_0_spot_exponent;
GLfloat light_0_gl_constant_attenuation;
GLfloat light_0_gl_linear_attenuation;
GLfloat light_0_gl_quadratic_attenuation;


void myInit(){

// This sets up most of the OpenGL options

    glClearColor(0.0,0.0,0.0,0.0);

// Set up a 3D Viewing perspective pulled back to the bottom corner of  
// the cube looking up to the middle of the cube.

    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT);

    gluLookAt(  0.0,   0.0,   0.0,  // Eye
                5.0,   5.0,   5.0,  // Center
                0.0,   0.0,   1.0); // Up


#ifdef DEBUG
    printf( "OpenGL Version: %s\n", glGetString(GL_VERSION)); 
#endif

    loadTextures();

    earth = gluNewQuadric();
    gluQuadricTexture( earth, GL_TRUE);

// Now start working on lighting -- these are material properties


   material_ambient  = { 0.5, 0.5, 0.5, 1.0 };
   material_diffuse  = { 0.2, 0.2, 0.2, 1.0 };
   material_specular = { 0.2, 0.2, 0.2, 1.0 };
   material_emission = { 0.2, 0.2, 0.2, 1.0 };

   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);
   glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_emission);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
//   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 25.0);


// These are light properties -- notice, specified for EACH light

   light_0_position =  {  5.0,  5.0,  0.0, 1.0 };
   light_0_ambient  =  {  1.0,  0.0,  0.0, 1.0 };
   light_0_diffuse  =  {  1.0,  0.0,  0.0, 1.0 };
   light_0_specular =  {  1.0,  0.0,  0.0, 1.0 };
   glLightfv(GL_LIGHT0, GL_POSITION, light_0_position);
   glLightfv(GL_LIGHT0, GL_AMBIENT, light_0_ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_0_diffuse);
   glLightfv(GL_LIGHT0, GL_SPECULAR, light_0_specular);


   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);

}


#endif 
