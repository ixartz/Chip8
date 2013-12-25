#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLFW/glfw3.h>
#else
#endif

#include <iostream>
#include <string>
#include "rom.hh"
#include "chip8.hh"
#include "keyboard.hh"

void error_callback(int __attribute__((__unused__)) error, const char* description)
{
  fputs(description, stderr);
}

int main(int argc, char* argv[])
{
  GLFWwindow* window;
  Chip8 chip;
  std::string game_name;
  Rom rom;

  if (argc > 0)
  {
    game_name = std::string(argv[1]);
    rom = Rom(game_name);
  }
  else
  {
    exit(EXIT_FAILURE);
  }

  glfwSetErrorCallback(error_callback);

  if (!glfwInit())
    exit(EXIT_FAILURE);

  window = glfwCreateWindow(640, 480, "Chip 8", NULL, NULL);

  if (!window)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);

  chip.init();
  chip.load_from_rom(rom);
  glfwSetKeyCallback(window, Keyboard::key_callback);

  while (!glfwWindowShouldClose(window))
  {
    chip.emulate();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);

  glfwTerminate();
  exit(EXIT_SUCCESS);
}
