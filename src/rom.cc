#include "rom.hh"

Rom::Rom()
{
}

Rom::Rom(std::string& filename)
  : filename_(filename)
{
}

Rom::~Rom()
{
}

void Rom::open_file()
{
  file_.open(filename_, std::ios::binary);

  if (!file_.is_open())
  {
    std::cerr << "Error while opening the file \"" << filename_ << "\"" << std::endl;
  }
}

Rom& Rom::operator=(const Rom& r)
{
  if (this != &r)
  {
    this->filename_ = r.filename_;
  }

  return *this;
}

std::istream& Rom::operator>>(unsigned char& c)
{
  return file_ >> c;
}
