#ifndef CHIP_8_HH
# define CHIP_8_HH

# include <vector>
# include <stack>
# include "keyboard.hh"
# include "screen.hh"
# include "rom.hh"

class Chip8
{
public:
  static constexpr unsigned short kmemory_start = 0x200;
  static constexpr unsigned short kmemory_size = 4096;
  static constexpr unsigned short knb_register = 16;

  Chip8();
  ~Chip8();
  void init();
  void emulate();
  void load_from_rom(Rom& r);
  unsigned char get_pixel(int x, int y);
private:
  void make_beep_();

  unsigned short opcode_;
  unsigned short I_;
  unsigned short pc_; // program counter

  // Deduce from opcode_
  unsigned short NNN_;
  unsigned char NN_;
  unsigned char N_;
  unsigned char X_;
  unsigned char Y_;

  // Timer
  unsigned char delay_timer_;
  unsigned char sound_timer_;

  std::vector<unsigned char> memory_;
  std::vector<unsigned char> V_;
  std::stack<unsigned short> stack_;

  Screen screen_;
  Rom* rom_;
};

#endif //!CHIP_8_HH
