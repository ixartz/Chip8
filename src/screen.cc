#include "screen.hh"

Screen::Screen()
  : buffer_(kframe_size)
{
}

Screen::~Screen()
{
}

unsigned char& Screen::operator()(int x, int y)
{
  assert(x >= 0 && x < kframe_width);
  assert(y >= 0 && y < kframe_height);

  return buffer_[x + y * kframe_width];
}
