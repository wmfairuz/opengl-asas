#include <GL/glew.h>
#include <GL/glut.h>

void papar(void){
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Tukar background kepada warna merah
	glClear(GL_COLOR_BUFFER_BIT); // Kosongkan buffer warna
	glLoadIdentity(); // 
 
	glFlush(); // Hantar buffer ke tetingkap
}
 
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
 
	glutInitDisplayMode (GLUT_SINGLE);
 
	glutInitWindowSize (500, 500); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Tetingkap pertama saya");
 
	glutDisplayFunc(papar); 
 
	glutMainLoop(); 
	return 0; 
}