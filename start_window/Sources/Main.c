#include <GLEW/glew.h>
#include <GLFW/glfw3.h>


/*
GLEW (OpenGL Extension Wrangler) предоставляет современный функционал OpenGL (шейдеры, вершинные объекты)
GLFW (OpenGL FrameWork) обеспечивает создание и управление мульти-платформенными окнами с контекстом OpenGL, предоставляет доступ к вводу
 */


int main(void)
{
    // инициализация GLFW
    if (!glfwInit())
    {
        return 1;
    }


    // создание окна с контекстом OpenGL
    GLFWwindow* window = glfwCreateWindow(400, 400, "GLEW Start Window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return 2;
    }
    glfwMakeContextCurrent(window); // делаем контекст окна текущим контекстом отрисовки


    // инициализация GLEW (только после подключения контекста отрисовки OpenGL)
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        return 3;
    }


    // основной цикл программы (до закрытия окна или нажатия Escape)
    while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE))
    {
        // отрисовка изображения
        glClearColor(0.5f, 0.5f, 0.5f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glPushMatrix(); // помещение матрицы в стек

        glBegin(GL_TRIANGLES);
	        glColor3f(1, 0, 0); glVertex2f(0.0f, 0.75f);
	        glColor3f(0, 1, 0); glVertex2f(0.87f, -0.75f);
	        glColor3f(0, 0, 1); glVertex2f(-0.87f, -0.75f);
        glEnd();

        glPopMatrix(); // загрузка матрицы из стека (возвращение ее прежнего состояния)

        // обмен переднего и заднего буферов
        glfwSwapBuffers(window);

        // запрос на обработку событий
        glfwPollEvents();
    }


    // освобождение памяти
    glfwTerminate();

    return 0;
}