#ifndef ROM_HH
# define ROM_HH

# include <iostream>
# include <fstream>
# include <string>

class Rom
{
public:
  Rom(std::string& filename);
  ~Rom();
  std::istream& operator>>(unsigned char& c);
private:
  std::string filename_;
  std::ifstream file_;
};

#endif
