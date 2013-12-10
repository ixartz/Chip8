#ifndef CHIP_8_HH
# define CHIP_8_HH

# include "rom.hh"

class Chip8
{
public:
  Chip8();
  ~Chip8();

  void load_from_rom(Rom& r);
private:
  unsigned char memory_[4096];

  Rom* rom_;
};

#endif //!CHIP_8_HH
