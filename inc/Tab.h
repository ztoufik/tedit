#ifndef _WIN_
#define _WIN_

#include<curses.h>

#include"Buf.h"

class Tab {
public:
  struct Cursor {
    int x, y;
  };
  Tab() : c{0, 0} { init(); }
  Tab(const std::string &filepath) : buf(filepath) { Tab(); }
  ~Tab() { endwin(); } /* End curses mode*/
  void init();
  void loop();

private:
  Buf buf;
  Cursor c;
};

#endif
