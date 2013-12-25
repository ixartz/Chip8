#ifndef KEYBOARD_HH
# define KEYBOARD_HH

# include <GLFW/glfw3.h>
# include <vector>

class Keyboard
{
public:
  static constexpr unsigned short knb_input = 16;

  static void key_callback(GLFWwindow* window,
                           int key,
                           int scancode,
                           int action,
                           int mods);

  static bool is_pressed(int key);
private:
  static std::vector<bool> input_;
};

#endif //!KEYBOARD_HH
