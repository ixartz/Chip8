#include "chip8.hh"

Chip8::Chip8()
  : memory_(kmemory_size)
  , V_(knb_register)
{
}

Chip8::~Chip8()
{
}

void Chip8::init()
{
  opcode_ = 0;
  I_ = 0;
  pc_ = kmemory_start;

  delay_timer_ = 0;
  sound_timer_ = 0;

  for (int i = 0; i < kmemory_size; ++i)
    memory_[i] = 0;

  for (int i = 0; i < knb_register; ++i)
    V_[i] = 0;

  memory_[0] = 0xF0; memory_[1] = 0x90; memory_[2] = 0x90; memory_[3] = 0x90; memory_[4] = 0xF0;
  memory_[5] = 0x20; memory_[6] = 0x60; memory_[7] = 0x20; memory_[8] = 0x20; memory_[9] = 0x70;
  memory_[10] = 0xF0; memory_[11] = 0x10; memory_[12] = 0xF0; memory_[13] = 0x80; memory_[14] = 0xF0;
  memory_[15] = 0xF0; memory_[16] = 0x10; memory_[17] = 0xF0; memory_[18] = 0x10; memory_[19] = 0xF0;
  memory_[20] = 0x90; memory_[21] = 0x90; memory_[22] = 0xF0; memory_[23] = 0x10; memory_[24] = 0x10;
  memory_[25] = 0xF0; memory_[26] = 0x80; memory_[27] = 0xF0; memory_[28] = 0x10; memory_[29] = 0xF0;
  memory_[30] = 0xF0; memory_[31] = 0x80; memory_[32] = 0xF0; memory_[33] = 0x90; memory_[34] = 0xF0;
  memory_[35] = 0xF0; memory_[36] = 0x10; memory_[37] = 0x20; memory_[38] = 0x40; memory_[39] = 0x40;
  memory_[40] = 0xF0; memory_[41] = 0x90; memory_[42] = 0xF0; memory_[43] = 0x90; memory_[44] = 0xF0;
  memory_[45] = 0xF0; memory_[46] = 0x90; memory_[47] = 0xF0; memory_[48] = 0x10; memory_[49] = 0xF0;
  memory_[50] = 0xF0; memory_[51] = 0x90; memory_[52] = 0xF0; memory_[53] = 0x90; memory_[54] = 0x90;
  memory_[55] = 0xE0; memory_[56] = 0x90; memory_[57] = 0xE0; memory_[58] = 0x90; memory_[59] = 0xE0;
  memory_[60] = 0xF0; memory_[61] = 0x80; memory_[62] = 0x80; memory_[63] = 0x80; memory_[64] = 0xF0;
  memory_[65] = 0xE0; memory_[66] = 0x90; memory_[67] = 0x90; memory_[68] = 0x90; memory_[69] = 0xE0;
  memory_[70] = 0xF0; memory_[71] = 0x80; memory_[72] = 0xF0; memory_[73] = 0x80; memory_[74] = 0xF0;
  memory_[75] = 0xF0; memory_[76] = 0x80; memory_[77] = 0xF0; memory_[78] = 0x80; memory_[79] = 0x80;
}

void Chip8::emulate()
{
  opcode_ = memory_[pc_] << 8 | memory_[pc_ + 1];
  pc_ += 2;

  // Timer
  if(delay_timer_ > 0)
    --delay_timer_;

  if(sound_timer_ > 0)
  {
    if(sound_timer_ == 1)
      make_beep_();

    --sound_timer_;
  }
}

void Chip8::load_from_rom(Rom& r)
{
  int i = kmemory_start;
  rom_ = &r;

  while (r >> memory_[i])
    ++i;
}

void Chip8::make_beep_()
{
  std::cout << "\a" << std::endl;
}
