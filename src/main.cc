#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLFW/glfw3.h>
#else
#endif

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

  if (argc > 1)
  {
    game_name = argv[1];
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
  glOrtho(0, 640, 480, 0, 0, 1);

  while (!glfwWindowShouldClose(window))
  {
    //chip.emulate();

    glClear(GL_COLOR_BUFFER_BIT);

    for (int j = 0; j < Screen::kframe_height; ++j)
      for (int i = 0; i < Screen::kframe_width; ++i)
      {
        if (chip.get_pixel(i, j) == 0)
          glColor3f(0.0f, 0.0f, 0.0f);
        else
          glColor3f(1.0f, 1.0f, 1.0f);
      }

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);

  glfwTerminate();
  exit(EXIT_SUCCESS);
}
