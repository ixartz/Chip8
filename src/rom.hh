#ifndef ROM_HH
# define ROM_HH

# include <iostream>
# include <fstream>
# include <string>

class Rom
{
public:
  Rom();
  Rom(std::string& filename);
  ~Rom();
  void open_file();
  Rom& operator=(const Rom& r);
  bool operator>>(unsigned char& c);
private:
  std::string filename_;
  std::ifstream file_;
  int pos_;
  int size_;
  char* buffer_ = NULL;
};

#endif
