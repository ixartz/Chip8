#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLFW/glfw3.h>
#else
#endif

#include <iostream>
#include "chip8.hh"

void error_callback(int __attribute__((__unused__)) error, const char* description)
{
  fputs(description, stderr);
}

int main()
{
  GLFWwindow* window;

  glfwSetErrorCallback(error_callback);

  if (!glfwInit())
    exit(EXIT_FAILURE);

   window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);

  if (!window)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);

  //glfwSetKeyCallback(window, key_callback);

  while (!glfwWindowShouldClose(window))
  {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);

  glfwTerminate();
  exit(EXIT_SUCCESS);
}
