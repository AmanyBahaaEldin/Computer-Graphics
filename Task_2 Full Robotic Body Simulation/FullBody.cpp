#include <GL/glut.h>
#include <stdlib.h>

static int RightShoulder = 0, RightElbow = 0, RightFingerBase = 0, RightFingerUp = 0 , RightHip =0,RightKnee=0,RightAnkle=0, LeftShoulder = 0, LeftElbow = 0, LeftFingerBase = 0, LeftFingerUp = 0 , LeftHip =0,LeftKnee=0,LeftAnkle=0,neck=0;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void display(void)
{
   
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();  //the matrix containing all objects
   glRotatef(angle2, 1.0, 0.0, 0.0);
   glRotatef(angle, 0.0, 1.0, 0.0);
   //glTranslatef (0.0, 1.3, 0.0);

   //Draw head
   glPushMatrix();
   glTranslatef (0.0, 2.5, 0.0);
   glRotatef ((GLfloat) neck, 0.0, 1.0, 0.0);
   glutWireSphere(0.4, 15, 10);
   glPopMatrix();
   

   //Draw body 
   glTranslatef (0.0, 1.0, 0.0);
   glPushMatrix();
   glScalef (1.5, 2.0, 0.6);
   glutWireCube (1.0);
   glPopMatrix();

   //Draw arm1
   glPushMatrix();  //to connect arm and fingers
   glTranslatef (0.75, 0.5, 0.0);
   glRotatef ((GLfloat) RightShoulder, 0.0, 0.0, 1.0);
   glTranslatef (0.5, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.0, 0.5, 0.45);
   glutWireCube (1.0);
   glPopMatrix();

   glTranslatef (0.5, 0.0, 0.0);
   glRotatef ((GLfloat) RightElbow, 0.0, 0.0, 1.0);
   glTranslatef (0.5, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.0, 0.5, 0.45);
   glutWireCube (1.0);
   glPopMatrix();


   //Draw finger flang1
   glPushMatrix();
   glTranslatef(0.5, -0.1, 0.0);
   glRotatef((GLfloat)RightFingerBase, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   //Draw finger flang1*
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)RightFingerUp, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();


   //Draw finger flang2
   glPushMatrix();
   glTranslatef(0.5, 0.2, 0.15);
   glRotatef((GLfloat)RightFingerBase, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   //Draw finger flang2*
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)RightFingerUp, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();

   //Draw finger flang3
   glPushMatrix();
   glTranslatef(0.5, 0.2, 0.05);
   glRotatef((GLfloat)RightFingerBase, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   //Draw finger flang3*
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)RightFingerUp, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();

   //Draw finger flang4
   glPushMatrix();
   glTranslatef(0.5, 0.2, -0.05);
   glRotatef((GLfloat)RightFingerBase, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   //Draw finger flang4*
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)RightFingerUp, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();

   //Draw finger flang5
   glPushMatrix();
   glTranslatef(0.5, 0.2, -0.15);
   glRotatef((GLfloat)RightFingerBase, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   //Draw finger flang4*
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)RightFingerUp, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();
   glPopMatrix(); // end of connection of arm1 and fingers

   //Draw arm2
   glPushMatrix(); //to connect arm2 and fingers
   glTranslatef (-0.75, 0.5, 0.0);
   glRotatef ((GLfloat) LeftShoulder, 0.0, 0.0, 1.0);
   glTranslatef (-0.5, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.0, 0.5, 0.45);
   glutWireCube (1.0);
   glPopMatrix();
   glTranslatef (-0.5, 0.0, 0.0);
   glRotatef ((GLfloat) LeftElbow, 0.0, 0.0, 1.0);
   glTranslatef (-0.5, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.0, 0.5, 0.45);
   glutWireCube (1.0);
   glPopMatrix();

   //Draw finger1
   glPushMatrix();
   glTranslatef(-0.5, -0.1, 0.0);
   glRotatef((GLfloat)LeftFingerBase, 0.0, 0.0, 1.0);
   glTranslatef(-0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   //Draw finger flang1*
   glTranslatef(-0.15, 0.0, 0.0);
   glRotatef((GLfloat)LeftFingerUp, 0.0, 0.0, 1.0);
   glTranslatef(-0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();


   //Draw finger flang2
   glPushMatrix();
   glTranslatef(-0.5, 0.2, 0.15);
   glRotatef((GLfloat)LeftFingerBase, 0.0, 0.0, 1.0);
   glTranslatef(-0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   //Draw finger flang2*
   glTranslatef(-0.15, 0.0, 0.0);
   glRotatef((GLfloat)LeftFingerUp, 0.0, 0.0, 1.0);
   glTranslatef(-0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();

   //Draw finger flang3
   glPushMatrix();
   glTranslatef(-0.5, 0.2, 0.05);
   glRotatef((GLfloat)LeftFingerBase, 0.0, 0.0, 1.0);
   glTranslatef(-0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   //Draw finger flang3*
   glTranslatef(-0.15, 0.0, 0.0);
   glRotatef((GLfloat)LeftFingerUp, 0.0, 0.0, 1.0);
   glTranslatef(-0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();

   //Draw finger flang4
   glPushMatrix();
   glTranslatef(-0.5, 0.2, -0.05);
   glRotatef((GLfloat)LeftFingerBase, 0.0, 0.0, 1.0);
   glTranslatef(-0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   //Draw finger flang4*
   glTranslatef(-0.15, 0.0, 0.0);
   glRotatef((GLfloat)LeftFingerUp, 0.0, 0.0, 1.0);
   glTranslatef(-0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();

   //Draw finger flang5
   glPushMatrix();
   glTranslatef(-0.5, 0.2, -0.15);
   glRotatef((GLfloat)LeftFingerBase, 0.0, 0.0, 1.0);
   glTranslatef(-0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   //Draw finger flang5*
   glTranslatef(-0.15, 0.0, 0.0);
   glRotatef((GLfloat)LeftFingerUp, 0.0, 0.0, 1.0);
   glTranslatef(-0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.06, 0.05);
   glutWireCube(1);
   glPopMatrix();
   glPopMatrix();

   glPopMatrix(); // end of connection of arm2 and fingers



   //Draw leg1
   glPushMatrix(); // connect leg with foot
   glTranslatef (-0.3, -1.0, 0.0);
   glRotatef ((GLfloat) LeftHip, 1.0, 0.0, 0.0);
   glTranslatef(0.0, -0.75, 0.0);
   glPushMatrix();
   glScalef (0.4, 1.5, 0.6);
   glutWireCube (1.0);
   glPopMatrix();
   glTranslatef (0.0, -0.75, 0.0);
   glRotatef ((GLfloat) LeftKnee, 1.0, 0.0, 0.0);
   glTranslatef(0.0, -0.75, 0.0);
   glPushMatrix();
   glScalef (0.4, 1.5, 0.6);
   glutWireCube (1.0);
   glPopMatrix();

   //Draw foot1
   glTranslatef (0.0, -0.75, 0.45);
   glRotatef ((GLfloat) LeftAnkle, 1.0, 0.0, 0.0);
   glTranslatef(0.0, -0.15, 0.0);
   glPushMatrix();
   glScalef (0.4, 0.3, 1.5);
   glutWireCube (1.0);
   glPopMatrix();

   glPopMatrix(); //end of connection of leg1 with foot

   //Draw leg2
   
   glPushMatrix(); //connection of leg2 with foot
   glTranslatef (0.3, -1.0, 0.0);
   glRotatef ((GLfloat) RightHip, 1.0, 0.0, 0.0);
   glTranslatef(0.0, -0.75, 0.0);
   glPushMatrix();
   glScalef (0.4, 1.5, 0.6);
   glutWireCube (1.0);
   glPopMatrix();

   glTranslatef (0.0, -0.75, 0.0);
   glRotatef ((GLfloat) RightKnee, 1.0, 0.0, 0.0);
   glTranslatef(0.0, -0.75, 0.0);
   glPushMatrix();
   glScalef (0.4, 1.5, 0.6);
   glutWireCube (1.0);
   glPopMatrix();

   //Draw foot2
   glTranslatef (0.0, -0.75, 0.45);
   glRotatef ((GLfloat) RightAnkle, 1.0, 0.0, 0.0);
   glTranslatef(0.0, -0.15, 0.0);
   glPushMatrix();
   glScalef (0.4, 0.3, 1.5);
   glutWireCube (1.0);
   glPopMatrix();




   glPopMatrix(); //end of connection of leg2 with foot

   



   glPopMatrix(); //of the matrix containing all objects
   glutSwapBuffers();
 


}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
   case 's':
      if (RightShoulder<90 )
         {
            RightShoulder = (RightShoulder + 5) % 360;
            LeftShoulder =(LeftShoulder-5) % 360;
            glutPostRedisplay();
            
         }
      break;
      
   case 'S':
      if (RightShoulder>-90 )
      {
         RightShoulder = (RightShoulder - 5) % 360;
         LeftShoulder = (LeftShoulder + 5)% 360;
         glutPostRedisplay();
      }
      break;
   case 'e':
      if (RightElbow < 90)
      {
         RightElbow = (RightElbow + 5) % 360;
         LeftElbow = (LeftElbow -5) % 360;
         glutPostRedisplay();
      }
      break;
   case 'E':
      if (RightElbow > -150)
      {
         RightElbow = (RightElbow - 5) % 360;
         LeftElbow = (LeftElbow + 5) % 360;
         glutPostRedisplay();
      }
      break;
   case 'n':
      if (neck < 90)
      {
         neck = (neck + 5) % 360;
         glutPostRedisplay();
      }
      break;
   case 'N':
      if (neck > -90)
      {
         neck = (neck - 5) % 360;
         glutPostRedisplay();
      }
      break;
   case 'f':
      if (RightFingerBase < 90)
      {
         RightFingerBase = (RightFingerBase + 5) % 360;
         LeftFingerBase = (LeftFingerBase - 5) % 360;
         glutPostRedisplay();
      }
      break;
   case 'F':
      if (RightFingerBase > -90)
      {
         RightFingerBase = (RightFingerBase - 5) % 360;
         LeftFingerBase = (LeftFingerBase + 5) % 360;
         glutPostRedisplay();
      }
      break;
   case 'g':
      if (RightFingerUp < 0)
      {
         RightFingerUp = (RightFingerUp + 5) % 360;
         LeftFingerUp = (LeftFingerUp -5) % 360;
         glutPostRedisplay();
      }
      break;
   case 'G':
      if (RightFingerUp>-90)
      {
         RightFingerUp = (RightFingerUp - 5) % 360;
         LeftFingerUp = (LeftFingerUp +5) % 360;
         glutPostRedisplay();
      }
      break;

   case 'h':
      if (RightHip > -90)
      {
         RightHip = (RightHip - 5)%360 ;
         glutPostRedisplay();
      }
      break;

   case 'H':
      if (RightHip < 0)
      {
         RightHip = (RightHip + 5)%360 ;
         glutPostRedisplay();
      }
      break;
   case 'l':
      if (LeftHip > -90)
      {
         LeftHip = (LeftHip - 5)%360 ;
         glutPostRedisplay();
      }
      break;
   case 'L':
      if (LeftHip < 0)
      {
         LeftHip = (LeftHip + 5)%360 ;
         glutPostRedisplay();
      }
      break;

   case 'k':
      if (RightKnee < 90)
      {
         RightKnee = (RightKnee +5) %360;
         glutPostRedisplay();
      }
      break;

   case 'K':
      if (RightKnee > 0)
      {
         RightKnee = (RightKnee -5) %360;
         glutPostRedisplay();
      }
      break;

   case 'j':
      if (LeftKnee < 90)
      {
         LeftKnee = (LeftKnee +5) %360;
         glutPostRedisplay();
      }
      break;

   case 'J':
      if (LeftKnee > 0)
      {
         LeftKnee = (LeftKnee -5) %360;
         glutPostRedisplay();
      }
      break;
      
      

   case 27:
      exit(0);
      break;
   default:
      break;
   }
}

static void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON) {
    if (state == GLUT_DOWN) {
      moving = 1;
      startx = x;
      starty = y;
    }
    if (state == GLUT_UP) {
      moving = 0;
    }
  }
}


static void motion(int x, int y)
{
  if (moving) {
    angle = angle + (x - startx);
    angle2 = angle2 + (y - starty);
    startx = x;
    starty = y;
    glutPostRedisplay();
  }
}



int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
