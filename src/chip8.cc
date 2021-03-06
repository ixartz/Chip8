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

  screen_.clean();

  while (!stack_.empty())
    stack_.pop();

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

  NNN_ = opcode_ & 0x0FFF;
  NN_ = opcode_ & 0x00FF;
  N_ = opcode_ & 0x000F;
  X_ = (opcode_ & 0x0F00) >> 8;
  Y_ = (opcode_ & 0x00F0) >> 4;

  switch (opcode_ & 0xF000)
  {
    case 0x0000:
      switch (NN_)
      {
        case 0x00E0:
          screen_.clean();
          break;
        case 0x00EE:
          pc_ = stack_.top();
          stack_.pop();
          break;
      }
      /*
       * The 0NNN instruction is deprecated.
       * So, it is not implemented.
       */
      break;
    case 0x1000:
      pc_ = NNN_;
      break;
    case 0x2000:
      stack_.push(pc_);
      pc_ = NNN_;
      break;
    case 0x3000:
      if (V_[X_] == NN_)
        pc_ += 2;
      break;
    case 0x4000:
      if (V_[X_] != NN_)
        pc_ += 2;
      break;
    case 0x5000:
      if (V_[X_] == V_[Y_])
        pc_ += 2;
      break;
    case 0x6000:
      V_[X_] = NN_;
      break;
    case 0x7000:
      V_[X_] += NN_;
      break;
    case 0x8000:
      switch (N_)
      {
        case 0x0000:
          V_[X_] = V_[Y_];
          break;
        case 0x0001:
          V_[X_] |= V_[Y_];
          break;
        case 0x0002:
          V_[X_] &= V_[Y_];
          break;
        case 0x0003:
          V_[X_] ^= V_[Y_];
          break;
        case 0x0004:
        {
          // Carry flag
          unsigned short sum = V_[X_] + V_[Y_];
          V_[0xF] = sum > 255;

          V_[X_] = sum & 0xFF;
          break;
        }
        case 0x0005:
          V_[0xF] = V_[X_] > V_[Y_];

          V_[X_] -= V_[Y_];
          break;
        case 0x0006:
          V_[0xF] = V_[X_] & 0x01;
          V_[X_] >>= 1;
          break;
        case 0x0007:
          V_[0xF] = V_[Y_] > V_[X_];
          V_[X_] = V_[Y_] - V_[X_];
          break;
        case 0x000E:
          V_[0xF] = (V_[X_] & 0x80) >> 7;
          V_[X_] <<= 1;
          break;
      }
      break;
    case 0x9000:
      if (V_[X_] != V_[Y_])
        pc_ += 2;
      break;
    case 0xA000:
      I_ = NNN_;
      break;
    case 0xB000:
      pc_ = NNN_ + V_[0];
      break;
    case 0xC000:
      /*
       * It is useless to choose a random value between 0 and 255
       * because we do a AND operation with the byte mask (NN_, a 16-bit)
       * in the target register. So, the result will automatically between 0 and 255.
       */
      V_[X_] = rand() & NN_;
      break;
    case 0xD000:
      unsigned char line;

      V_[0xF] = 0;

      for (int j = 0; j < N_; ++j)
      {
        line = memory_[I_ + j];

        for (int i = 0; i < 8; ++i)
        {
          if ((line & 0x80) > 0)
          {
            if (screen_(V_[X_] + i, V_[Y_] + j) > 0)
              V_[0xF] = 1;

            screen_(V_[X_] + i, V_[Y_] + j) ^= 1;
          }

          line <<= 1;
        }
      }
      break;
    case 0xE000:
      switch (NN_)
      {
        case 0x009E:
          if (Keyboard::is_pressed(V_[X_]))
            pc_ += 2;
          break;
        case 0x00A1:
          if (!Keyboard::is_pressed(V_[X_]))
            pc_ += 2;
          break;
      }
      break;
    case 0xF000:
      switch (NN_)
      {
        case 0x0007:
          V_[X_] = delay_timer_;
          break;
        case 0x000A:
          break;
        case 0x0015:
          delay_timer_ = V_[X_];
          break;
        case 0x0018:
          sound_timer_ = V_[X_];
          break;
        case 0x001E:
          I_ += V_[X_];
          break;
        case 0x0029:
          I_ = V_[X_] * 5;
          break;
        case 0x0033:
          memory_[I_] = V_[X_] / 100;
          memory_[I_ + 1] = V_[X_] / 10 % 10;
          memory_[I_ + 2] = V_[X_] % 10;
          break;
        case 0x0055:
          for (int i = 0; i <= X_; ++i)
          {
            memory_[I_ + i] = V_[i];
          }
          break;
        case 0x0065:
          for (int i = 0; i <= X_; ++i)
          {
            V_[i] = memory_[I_ + i];
          }
          break;
      }
      break;
  }

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

  rom_->open_file();

  while (r >> memory_[i])
    ++i;
}

void Chip8::make_beep_()
{
  std::cout << "\a" << std::endl;
}

unsigned char Chip8::get_pixel(int x, int y)
{
  return screen_(x, y);
}
