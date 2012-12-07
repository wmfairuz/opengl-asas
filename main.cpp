#include <GL/glew.h>
#include <GL/glut.h>

void papar(void){
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Tukar background kepada warna merah
	glClear(GL_COLOR_BUFFER_BIT); // Kosongkan buffer warna
	glLoadIdentity(); // 
 
	glFlush(); // Hantar buffer ke tetingkap
}
 
void reshape (int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); 
	glMatrixMode(GL_MODELVIEW); 
}
 
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
 
	glutInitDisplayMode (GLUT_SINGLE);
 
	glutInitWindowSize (500, 500); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Tetingkap pertama saya");
 
	glutDisplayFunc(papar); 
        glutReshapeFunc(reshape);
 
	glutMainLoop(); 
	return 0; 
}