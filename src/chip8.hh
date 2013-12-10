#ifndef CHIP_8_HH
# define CHIP_8_HH

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
private:
  unsigned short opcode_;
  unsigned char memory_[kmemory_size];
  unsigned char V_[knb_register];
  unsigned short I_;
  unsigned short pc_;

  Rom* rom_;
};

#endif //!CHIP_8_HH
