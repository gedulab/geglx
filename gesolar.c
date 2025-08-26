#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 10.0,  // 相机位置
              0.0, 0.0, 0.0,  // 观察点
              0.0, 1.0, 0.0); // 上方向

    // 绘制太阳
    glColor3f(1.0, 1.0, 0.0); // 设置颜色为黄色
    glutSolidSphere(1.0, 50, 50); // 绘制球体

    // 绘制地球
    glPushMatrix();
    glTranslatef(2.0, 0.0, 0.0); // 平移到太阳的轨道上
    glColor3f(0.0, 0.0, 1.0); // 设置颜色为蓝色
    glutSolidSphere(0.5, 50, 50); // 绘制球体
    glPopMatrix();

    // 绘制火星
    glPushMatrix();
    glTranslatef(3.0, 0.0, 0.0); // 平移到太阳的轨道上
    glColor3f(1.0, 0.5, 0.0); // 设置颜色为橙色
    glutSolidSphere(0.3, 50, 50); // 绘制球体
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Hello World");
    glEnable(GL_DEPTH_TEST); // 启用深度测试
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

