#include <gl/glut.h>


void Render( void )  {
	glClear( GL_COLOR_BUFFER_BIT);      	     
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
  	    glutSwapBuffers();
   
}


int main( int argc, char *argv[] )  {
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
  glutInitWindowSize( 800, 600 );
  glutInitWindowPosition( 100, 100 );
  glutCreateWindow( "Polygon" );
  glutDisplayFunc(Render);
  glutMainLoop( );
  return 0;
}


