#include "rom.hh"

Rom::Rom(std::string& filename)
  : filename_(filename)
{
  file_.open(filename, std::ios::binary);

  if (!file_.is_open())
  {
    std::cerr << "Error while opening " << filename << std::endl;
  }
}

Rom::~Rom()
{
}

std::istream& Rom::operator>>(unsigned char& c)
{
  return file_ >> c;
}
