#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * PI * (float)i / (float)num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawCar() {
    // **Badan Mobil**
    glColor3f(0.0f, 0.0f, 1.0f); // Biru
    glBegin(GL_POLYGON);
        glVertex2f(-0.3f, -0.1f);
        glVertex2f( 0.3f, -0.1f);
        glVertex2f( 0.35f,  0.1f);
        glVertex2f(-0.35f,  0.1f);
    glEnd();

    // **Atap Mobil**
    glColor3f(1.0f, 0.0f, 0.0f); // Merah
    glBegin(GL_POLYGON);
        glVertex2f(-0.2f, 0.1f);
        glVertex2f( 0.2f, 0.1f);
        glVertex2f( 0.15f, 0.2f);
        glVertex2f(-0.15f, 0.2f);
    glEnd();

    // **Roda Kiri**
    glPushMatrix();
        glTranslatef(-0.2f, -0.15f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.0f); // Hitam
        drawCircle(0, 0, 0.05f, 20);
    glPopMatrix();

    // **Roda Kanan**
    glPushMatrix();
        glTranslatef(0.2f, -0.15f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.0f); // Hitam
        drawCircle(0, 0, 0.05f, 20);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar Lingkaran
    glColor3f(1.0f, 1.0f, 0.0f); // Kuning
    drawCircle(0.0f, 0.5f, 0.1f, 50);

    // Gambar Mobil
    glPushMatrix();
        glTranslatef(0.0f, -0.2f, 0.0f); // Geser ke bawah
        drawCar();
    glPopMatrix();

    glFlush();
}

void init() {
    glClearColor(0.0f, 0.8f, 1.0f, 1.0f); // Background langit biru muda
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Mobil 2D dengan Lingkaran");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}