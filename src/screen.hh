#ifndef SCREEN_HH
# define SCREEN_HH

# include <cassert>
# include <vector>

class Screen
{
public:
  static constexpr unsigned short kframe_width = 64;
  static constexpr unsigned short kframe_height = 32;
  static constexpr unsigned short kframe_size = kframe_width * kframe_height;

  Screen();
  ~Screen();
  unsigned char& operator()(int x, int y);
private:
  std::vector<unsigned char> buffer_;
};

#endif //!SCREEN_HH
