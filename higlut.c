#include <GL/glut.h>
#include <math.h>
float angle;
GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat light_diffuse[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat light_specular[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat light_position[] = { 0.2, 0.2, 0.2, 1.0 };

void drawSolar() {
    //for light
    glEnable(GL_LIGHT0);

    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // Draw Sun : color yellow
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(0.0f ,0.75f, 0.0f);
    glutSolidSphere(3.0f,100,100);

    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glColor3f(0.9f,0.9f,0.9f);
    glTranslatef(-14 ,0.60, 0.0f);
    glutSolidSphere(0.75f,60,60);

    //Venus : drak yellow
    glColor3f(0.9f, 0.7f, 0.0f);
    glTranslatef(7,0.0f, 4.0f);
    glutSolidSphere(0.60f,40,40);


    //Earth : bluelight_ambient
    glColor3f(0.0f, 0.5f, 1.0f);
    glTranslatef(17,0.0f, 8.0f);
    glutSolidSphere(1.5f,40,40);

	//Mars : dark white
    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(12,0.0f, -15.0f);
    glutSolidSphere(0.75f,40,40);


    //drak yellow :  Jupiter
    glColor3f(0.9f, 0.5f, 0.0f);
    glTranslatef(14,0.0f, 10.0f);
    glutSolidSphere(1.9f,40,40);

    glEnd();

    angle+=0.1f;
    glFlush();

    glutSwapBuffers();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0,  // 相机位置
              0.0, 0.0, 0.0,  // 观察点
              0.0, 1.0, 0.0); // 上方向

    glColor3f(1.0, 0.0, 0.0); // 设置颜色为红色
    glutSolidSphere(1.0, 50, 50); // 绘制球体
//    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Hello World");
    glEnable(GL_DEPTH_TEST); // 启用深度测试
    glutDisplayFunc(drawSolar);
    glutMainLoop();
    return 0;
}

