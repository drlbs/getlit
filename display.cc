#ifndef DISPLAY_FUNC
#define DISPLAY_FUNC

#include "sysincludes.h"       

#include "globals.h"

void display(){

    // Enable Texturing and the Depth Buffer
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Bind textures and draw six sides of a cube

    glBindTexture(GL_TEXTURE_2D, textureID[0]);
    glBegin(GL_POLYGON);
      glNormal3d(0,0,-1);
      glTexCoord3d( 0.0, 0.0, 0.0);   glVertex3d(  0.0,  0.0, 0.0 );
      glTexCoord3d( 0.0, 1.0, 0.0);   glVertex3d(  0.0, 10.0, 0.0 );
      glTexCoord3d( 1.0, 1.0, 0.0);   glVertex3d( 10.0, 10.0, 0.0 );
      glTexCoord3d( 1.0, 0.0, 0.0);   glVertex3d( 10.0,  0.0, 0.0 );
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureID[1]);
    glBegin(GL_POLYGON);
      glNormal3d(0,0,1);
      glTexCoord3d( 0.0, 0.0, 0.0);   glVertex3d(  0.0,  0.0, 10.0 );
      glTexCoord3d( 0.0, 1.0, 0.0);   glVertex3d(  0.0, 10.0, 10.0 );
      glTexCoord3d( 1.0, 1.0, 0.0);   glVertex3d( 10.0, 10.0, 10.0 );
      glTexCoord3d( 1.0, 0.0, 0.0);   glVertex3d( 10.0,  0.0, 10.0 );
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureID[1]);
    glBegin(GL_POLYGON);
      glNormal3d(-1,0,0);
      glTexCoord3d( 0.0, 0.0, 0.0);   glVertex3d(  0.0,  0.0,  0.0 );
      glTexCoord3d( 0.0, 1.0, 0.0);   glVertex3d(  0.0, 10.0,  0.0 );
      glTexCoord3d( 1.0, 1.0, 0.0);   glVertex3d(  0.0, 10.0, 10.0 );
      glTexCoord3d( 1.0, 0.0, 0.0);   glVertex3d(  0.0,  0.0, 10.0 );
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureID[1]);
    glBegin(GL_POLYGON);
      glNormal3d(1,0,0);
      glTexCoord3d( 0.0, 0.0, 0.0);   glVertex3d( 10.0,  0.0,  0.0 );
      glTexCoord3d( 0.0, 1.0, 0.0);   glVertex3d( 10.0, 10.0,  0.0 );
      glTexCoord3d( 1.0, 1.0, 0.0);   glVertex3d( 10.0, 10.0, 10.0 );
      glTexCoord3d( 1.0, 0.0, 0.0);   glVertex3d( 10.0,  0.0, 10.0 );
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureID[1]);
    glBegin(GL_POLYGON);
      glNormal3d(0,-1,0);
      glTexCoord3d( 0.0, 0.0, 0.0);   glVertex3d(  0.0,  0.0,  0.0 );
      glTexCoord3d( 0.0, 1.0, 0.0);   glVertex3d(  0.0,  0.0, 10.0 );
      glTexCoord3d( 1.0, 1.0, 0.0);   glVertex3d( 10.0,  0.0, 10.0 );
      glTexCoord3d( 1.0, 0.0, 0.0);   glVertex3d( 10.0,  0.0,  0.0 );
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textureID[1]);
    glBegin(GL_POLYGON);
      glNormal3d(0,1,0);
      glTexCoord3d( 0.0, 0.0, 0.0);   glVertex3d(  0.0, 10.0,  0.0 );
      glTexCoord3d( 0.0, 1.0, 0.0);   glVertex3d(  0.0, 10.0, 10.0 );
      glTexCoord3d( 1.0, 1.0, 0.0);   glVertex3d( 10.0, 10.0, 10.0 );
      glTexCoord3d( 1.0, 0.0, 0.0);   glVertex3d( 10.0, 10.0,  0.0 );
    glEnd();

    glPushMatrix();
    glTranslatef(light_0_position[0],light_0_position[1],light_0_position[2]); 
    glutSolidSphere(0.5,20,20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(light_1_position[0],light_1_position[1],light_1_position[2]); 
    glutSolidSphere(0.5,20,20);
    glPopMatrix();
/*
    // Bind the texture and draw the sphere

    glBindTexture ( GL_TEXTURE_2D, textureID[2]);
    glTranslatef(-5.0,5.0,-5.0);
    glScalef(5.0,5.0,5.0);
    glPushMatrix();
    glRotatef(90.0,0.0,1.0,0.0);
    glRotatef(-45.0,0.0,0.0,1.0);
// The next line fixes the mirrored texture map
    glScalef(1.0,-1.0,1.0);
    gluSphere( earth, 0.9, 36, 72);
    glPopMatrix();

*/

    /// Trying add heads up display

    // Try some blending
/*
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, 800, 800, 0.0, -1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_CULL_FACE);
    glClear(GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.0f, 0.0, 0.5);
    glVertex2f(300.0, 300.0);
    glVertex2f(300.0, 700.0);
    glVertex2f(700.0, 700.0);
    glVertex2f(700.0, 300.0);
    glEnd();    

    // Go back to 3D rending 
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    

    glDisable(GL_BLEND); 
*/

    // Flush the buffer
    glFlush();

    // For completeness turn off these options
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);

}

#endif
