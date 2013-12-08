#ifndef CHIP_8_HH
# define CHIP_8_HH

# include "rom.hh"

class Chip8
{
public:
  Chip8();
  ~Chip8();

  void load_rom(Rom& r);
};

#endif //!CHIP_8_HH
