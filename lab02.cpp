#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

const float SPEED = 0.3;
float rotation = 0;
float rotating = true;

void Render( void )  {
	glClear( GL_COLOR_BUFFER_BIT); 
	glPushMatrix();
    glRotatef(rotation, 0.0, 0.0, 1.0);      
    glBegin(GL_POLYGON);
    //Set color
	glColor3f(0.7f,0.7f,0.0f);
	//Specifies vertices		
    glVertex3f(-0.35, -0.5, 0.0);		
    glVertex3f(0.35, -0.5, 0.0);				
    glVertex3f(0.5, 0.35, 0.0);
	glVertex3f(0.0, 0.75, 0.0);				
    glVertex3f(-0.5, 0.35, 0.0);
    glEnd();
    glFlush();
    glPopMatrix();
    glutSwapBuffers();
    glutPostRedisplay();
   
}


void mouse(int button, int state, int x, int y) 
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
        rotating = !rotating;
    }
}

void increateRotation(void)
{
    if (rotating) {
        rotation += SPEED;
    }
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



int main( int argc, char *argv[] )  {
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
  glutInitWindowSize( 800, 600 );
  glutInitWindowPosition( 100, 100 );
  glutCreateWindow( "Polygon" );
  glutDisplayFunc(Render);
  glutIdleFunc(increateRotation);
  glutMouseFunc(mouse);
  glutMainLoop( );
  return 0;
}
