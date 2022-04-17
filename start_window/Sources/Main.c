#include <GLEW/glew.h>
#include <GLFW/glfw3.h>


/*
GLEW (OpenGL Extension Wrangler) ������������� ����������� ���������� OpenGL (�������, ��������� �������)
GLFW (OpenGL FrameWork) ������������ �������� � ���������� ������-�������������� ������ � ���������� OpenGL, ������������� ������ � �����
 */


int main(void)
{
    // ������������� GLFW
    if (!glfwInit())
    {
        return 1;
    }


    // �������� ���� � ���������� OpenGL
    GLFWwindow* window = glfwCreateWindow(400, 400, "GLEW Start Window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return 2;
    }
    glfwMakeContextCurrent(window); // ������ �������� ���� ������� ���������� ���������


    // ������������� GLEW (������ ����� ����������� ��������� ��������� OpenGL)
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        return 3;
    }


    // �������� ���� ��������� (�� �������� ���� ��� ������� Escape)
    while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE))
    {
        // ��������� �����������
        glClearColor(0.5f, 0.5f, 0.5f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glPushMatrix(); // ��������� ������� � ����

        glBegin(GL_TRIANGLES);
	        glColor3f(1, 0, 0); glVertex2f(0.0f, 0.75f);
	        glColor3f(0, 1, 0); glVertex2f(0.87f, -0.75f);
	        glColor3f(0, 0, 1); glVertex2f(-0.87f, -0.75f);
        glEnd();

        glPopMatrix(); // �������� ������� �� ����� (����������� �� �������� ���������)

        // ����� ��������� � ������� �������
        glfwSwapBuffers(window);

        // ������ �� ��������� �������
        glfwPollEvents();
    }


    // ������������ ������
    glfwTerminate();

    return 0;
}