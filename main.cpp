#include <GL/glew.h>
#include <GL/glut.h>

bool naik = false;   // arah
float lokasi_y = 0.0f; // lokasi pada paksi y
float sudut_y = 0.0f;  // sudut pada paksi y

void binaPrimitif(void){
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f); // bucu berwarna biru
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f); // bucu berwarna merah
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f); // bucu berwarna hijau
	glVertex3f(1.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f); // bucu berwarna kuning
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
	if (naik) // arah ke atas
		lokasi_y -= 0.1f; // gerak ke atas pada paksi y  
	else  // arah ke bawah  
		lokasi_y += 0.1f; // gerak ke bawah pada paksi y  
	  
	if (lokasi_y < -2.0f) // had atas  
		naik = false; // tukar arah 
	else if (lokasi_y > 2.0f) // had bawah 
		naik = true; // tukar arah 
	  
	sudut_y += 1.0f; // putaran 
	if (sudut_y > 360.0f) // jika lebih 360 darjah, tolak 360  
		sudut_y -= 360.0f; 

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Tukar background kepada warna merah
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Kosongkan buffer warna
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
	glLoadIdentity(); // 
	glTranslatef(0.0f, 0.0f, -5.0f);  // alihkan kamera menjauhi paksi z 
 	//binaPrimitif();   // Bina bentuk primitif
	//glScalef(1, 2.0, 1);
	//glTranslatef(0.0f, lokasi_y, 0.0f);   
	glRotatef(sudut_y, 0.0f, 1.0f, 0.0f);

	//glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	//glutWireSphere(1.0f, 8.0f, 8.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glutSolidSphere(2.0f, 8.0f, 8.0f);

	glutSwapBuffers();
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
 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
 
	glutInitWindowSize (500, 500); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Tetingkap pertama saya");

	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
 
	glutDisplayFunc(papar); 
	glutIdleFunc(papar);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(tekanKekunci);
    glutKeyboardUpFunc(lepasKekunci);
 
	glutMainLoop();
	return 0;   
}