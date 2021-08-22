#include <GL/glut.h>
#include <math.h>

static int RightShoulder = 0, RightElbow = 0, RightFingerBase = 0, RightFingerUp = 0 , RightHip =0,RightKnee=0,RightAnkle=0, LeftShoulder = 0, LeftElbow = 0, LeftFingerBase = 0, LeftFingerUp = 0 , LeftHip =0,LeftKnee=0,LeftAnkle=0,neck=0;
double eye[] = { 0, 0, -15 };
double center[] = { 0, 0, 1 };
double up[] = { 0, 1, 0 };
double look_vector[] = {0,0,0};
double New_Vector[] = { 0,0,0};
double normalized[] = {0,0,0};
double RAngle1 = 0;
double RAngle2 = 0;
double UpAngle = 0;
double DownAngle = 0;
double speed = 0.1;
int moving, startx, starty;

GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
    glMatrixMode(GL_PROJECTION);
	gluPerspective(65.0, (GLfloat)1024 / (GLfloat)869, 1.0, 60.0);
}

void crossProduct(double a[], double b[], double c[])
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(double a[])
{
	double norm;
	norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	norm = sqrt(norm);
	a[0] /= norm;
	a[1] /= norm;
	a[2] /= norm;
}

void rotatePoint(double a[], double theta, double p[])
{

	double temp[3];
	temp[0] = p[0];
	temp[1] = p[1];
	temp[2] = p[2];

	temp[0] = -a[2] * p[1] + a[1] * p[2];
	temp[1] = a[2] * p[0] - a[0] * p[2];
	temp[2] = -a[1] * p[0] + a[0] * p[1];

	temp[0] *= sin(theta);
	temp[1] *= sin(theta);
	temp[2] *= sin(theta);

	temp[0] += (1 - cos(theta))*(a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
	temp[1] += (1 - cos(theta))*(a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
	temp[2] += (1 - cos(theta))*(a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

	temp[0] += cos(theta)*p[0];
	temp[1] += cos(theta)*p[1];
	temp[2] += cos(theta)*p[2];

	p[0] = temp[0];
	p[1] = temp[1];
	p[2] = temp[2];

}

void Left()
{
	// implement camera rotation arround vertical window screen axis to the left
	// used by mouse and left arrow
	rotatePoint(up , RAngle1 , eye);
	RAngle1 = RAngle1 - 0.001 ;
}

void Right()
{
	// implement camera rotation arround vertical window screen axis to the right
	// used by mouse and right arrow
	rotatePoint(up , RAngle2 , eye);
	RAngle2 = RAngle2 + 0.001 ;
}

void Up()
{
	
	look_vector[0] = center[0] - eye[0];
	look_vector[1] = center[1] - eye[1];
	look_vector[2] = center[2] - eye[2];
	crossProduct(look_vector , up , New_Vector);
	normalize(New_Vector);
	rotatePoint(New_Vector , UpAngle , eye);
	rotatePoint(New_Vector , UpAngle , up);
	UpAngle = UpAngle - 0.001;


	// implement camera rotation arround horizontal window screen axis +ve
	// used by up arrow
}

void Down()
{	
	// implement camera rotation arround horizontal window screen axis 
	// used by down arrow
	look_vector[0] = center[0] - eye[0];
	look_vector[1] = center[1] - eye[1];
	look_vector[2] = center[2] - eye[2];
	crossProduct(look_vector , up , New_Vector);
	normalize(New_Vector);
	rotatePoint(New_Vector , DownAngle , eye);
	rotatePoint(New_Vector , DownAngle , up);
	DownAngle = DownAngle + 0.001;
}

void moveForward()
{
	look_vector[0] = center[0] - eye[0];
	look_vector[1] = center[1] - eye[1];
	look_vector[2] = center[2] - eye[2];

	eye[0]    += look_vector[0] * speed;
	eye[1]    += look_vector[1] * speed;
	eye[2]    += look_vector[2] * speed;

	center[0] += look_vector[0] * speed;
	center[1] += look_vector[1] * speed;
	center[2] += look_vector[2] * speed;
}

void moveBack()
{
	look_vector[0] = center[0] - eye[0];
	look_vector[1] = center[1] - eye[1];
	look_vector[2] = center[2] - eye[2];

	eye[0]    -= look_vector[0] * speed;
	eye[1]    -= look_vector[1] * speed;
	eye[2]    -= look_vector[2] * speed;

	center[0] -= look_vector[0] * speed;
	center[1] -= look_vector[1] * speed;
	center[2] -= look_vector[2] * speed;
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT );
   	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

	glPushMatrix();  //the matrix containing all objects
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	

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

void specialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: Left(); break;
	case GLUT_KEY_RIGHT: Right(); break;
	case GLUT_KEY_UP:    Up(); break;
	case GLUT_KEY_DOWN:  Down(); break;
	}

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	// List all youe keyboard keys from assignment two her for body movement
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
	case 'i':
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
      


	case 'f':
		moveForward();
		glutPostRedisplay();
		break;
	case 'b':
		moveBack();
		glutPostRedisplay();
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
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("body");
	init();
	glutMouseFunc(mouse);
    glutMotionFunc(motion);
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}
