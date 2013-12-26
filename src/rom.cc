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
  if (buffer_)
    delete[] buffer_;
}

void Rom::open_file()
{
  file_.open(filename_, std::ios::binary | std::ios::ate);

  if (file_.is_open())
  {
    pos_ = 0;
    size_ = file_.tellg();
    buffer_ = new char[size_];
    file_.seekg(0, std::ios::beg);
    file_.read(buffer_, size_);
  }
  else
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

bool Rom::operator>>(unsigned char& c)
{
  c = buffer_[pos_];
  ++pos_;
  return pos_ < size_;
}
