#ifndef _TEDITEXCEPTION_
#define _TEDITEXCEPTION_

#include<exception>
#include<string>

class TeditException : std::exception {
public:
  TeditException(std::string &message) : message(message) {}
  TeditException(std::string &&message) : message(message) {}

private:
  std::string message;
};

#endif
