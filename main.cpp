#include <GL/glew.h>
#include <GL/glut.h>

void binaPrimitif(void){
	glBegin(GL_QUADS);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
}
 
void tekanKekunci(unsigned char key, int x, int y) {
	switch (key) {
		case 27:  // Keluar dari program
			exit(0) ;
			break ;
		default:
			break ;
	}
}
 
void lepasKekunci(unsigned char key, int x, int y) {
 
}
 
void papar(void){
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Tukar background kepada warna merah
	glClear(GL_COLOR_BUFFER_BIT); // Kosongkan buffer warna
	glLoadIdentity(); // 
	glTranslatef(0.0f, 0.0f, -5.0f);  // alihkan kamera menjauhi paksi z 
 	binaPrimitif();   // Bina bentuk primitif
	glFlush(); // Hantar buffer ke tetingkap
}
 
void reshape(int width, int height){
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // 
	glMatrixMode(GL_PROJECTION); // Tukar kepada projection matrix
	glLoadIdentity(); //   
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // fov, aspect ratio, near and far plane 
	glMatrixMode(GL_MODELVIEW); // Tukar semula ke modelview matrix  	
}
 
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
 
	glutInitDisplayMode (GLUT_SINGLE);
 
	glutInitWindowSize (500, 500); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Tetingkap pertama saya");
 
	// Now, we define callbacks and functions for various tasks.
	glutDisplayFunc(papar); 
	glutReshapeFunc(reshape);
        glutKeyboardFunc(tekanKekunci);
        glutKeyboardUpFunc(lepasKekunci);
 
	glutMainLoop(); // Start the main code
	return 0;   /* ANSI C requires main to return int. */
}