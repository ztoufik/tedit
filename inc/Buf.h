#ifndef __BUFFER__
#define __BUFFER__

#include<string>
#include<vector>

class Buf {
private:
  std::string filepath;
  std::vector<std::string> content;

public:
  Buf() = default;
  Buf(const std::string &filepath);
  Buf(const Buf &) = delete;
  Buf(Buf &&) = delete;
  Buf operator=(const Buf &) = delete;
  Buf operator=(Buf &&) = delete;
  std::vector<std::string>& get_content();
};

#endif
