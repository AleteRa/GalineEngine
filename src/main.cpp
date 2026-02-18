#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

extern "C" {
    _declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
 // _declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1; // AMD
}

int glWindowSizeX = 500;
int glWindowSizeY = 500;

void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height) {
    glWindowSizeX = width;
    glWindowSizeY = height;
    glViewport(0, 0, glWindowSizeX, glWindowSizeY);
    std::cout << "Width: " << width << " - Height: " << height << std::endl;
}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(pWindow, true);
}

int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    int major, minor, rev;
    glfwGetVersion(&major, &minor, &rev);
    std::cout << "GLFW version: " << major << "." << minor << "." << rev << std::endl;
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 6);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* pWindow = glfwCreateWindow(glWindowSizeX, glWindowSizeY, "Galina Engine", nullptr, nullptr);
    if (!pWindow)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGL()) {
        std::cout << "glad error" << std::endl;
        return -1;
    }

    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGl version: " << glGetString(GL_VERSION) << std::endl;

    glClearColor(0, 1, 1, 1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

