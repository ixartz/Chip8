#include "chip8.hh"

Chip8::Chip8()
{
}

Chip8::~Chip8()
{
}

void Chip8::load_from_rom(Rom& r)
{
  int i = 0x200;
  rom_ = &r;

  while (r >> memory_[i])
    ++i;
}
