#ifndef __BUFFER__
#define __BUFFER__

#include<sstream>
#include<string>

class Buf {
private:
  std::string filepath;
  std::ostringstream content;

public:
  Buf() = default;
  Buf(const std::string &filepath);
  Buf(const Buf &) = delete;
  Buf(Buf &&) = delete;
  Buf operator=(const Buf &) = delete;
  Buf operator=(Buf &&) = delete;
  std::string get_content() const;
};

#endif
