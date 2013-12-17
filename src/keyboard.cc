#include "keyboard.hh"

std::vector<int> Keyboard::input_ = std::vector<int> (knb_input);

void Keyboard::key_callback(GLFWwindow* window,
                            int key,
                            int __attribute__((__unused__)) scancode,
                            int action,
                            int __attribute__((__unused__)) mods)
{
  if (action == GLFW_RELEASE || action == GLFW_PRESS)
  {
    if (key == GLFW_KEY_ESCAPE)
      glfwSetWindowShouldClose(window, GL_TRUE);

    if (key == GLFW_KEY_X)
      input_[0x0] = action;
    else if (key == GLFW_KEY_1)
      Keyboard::input_[0x1] = action;
    else if (key == GLFW_KEY_2)
      Keyboard::input_[0x2] = action;
    else if (key == GLFW_KEY_3)
      Keyboard::input_[0x3] = action;
    else if (key == GLFW_KEY_Q)
      Keyboard::input_[0x4] = action;
    else if (key == GLFW_KEY_W)
      Keyboard::input_[0x5] = action;
    else if (key == GLFW_KEY_E)
      Keyboard::input_[0x6] = action;
    else if (key == GLFW_KEY_A)
      Keyboard::input_[0x7] = action;
    else if (key == GLFW_KEY_S)
      Keyboard::input_[0x8] = action;
    else if (key == GLFW_KEY_D)
      Keyboard::input_[0x9] = action;
    else if (key == GLFW_KEY_Z)
      Keyboard::input_[0xA] = action;
    else if (key == GLFW_KEY_C)
      Keyboard::input_[0xB] = action;
    else if (key == GLFW_KEY_4)
      Keyboard::input_[0xC] = action;
    else if (key == GLFW_KEY_R)
      Keyboard::input_[0xD] = action;
    else if (key == GLFW_KEY_F)
      Keyboard::input_[0xE] = action;
    else if (key == GLFW_KEY_V)
      Keyboard::input_[0xF] = action;
  }
}
