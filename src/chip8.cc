#include "chip8.hh"

Chip8::Chip8()
{
}

Chip8::~Chip8()
{
}

void Chip8::init()
{
  pc_ = kmemory_start;
}

void Chip8::emulate()
{
  opcode_ = memory_[pc_] << 8 | memory_[pc_ + 1];
  pc_ += 2;
}

void Chip8::load_from_rom(Rom& r)
{
  int i = kmemory_start;
  rom_ = &r;

  while (r >> memory_[i])
    ++i;
}
