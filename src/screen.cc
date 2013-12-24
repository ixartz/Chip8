#include "screen.hh"

Screen::Screen()
  : buffer_(kframe_size)
{
}

Screen::~Screen()
{
}

void Screen::clean()
{
  for (int j = 0; j < kframe_height; ++j)
  {
    for (int i = 0; i < kframe_width; ++i)
    {
      buffer_[i + j * kframe_width] = 0;
    }
  }
}

unsigned char& Screen::operator()(int x, int y)
{
  assert(x >= 0 && x < kframe_width);
  assert(y >= 0 && y < kframe_height);

  return buffer_[x + y * kframe_width];
}
