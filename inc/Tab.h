#ifndef _WIN_
#define _WIN_

#include<memory>

#include<curses.h>

#include"Buf.h"

class Tab {
public:
  struct Cursor {
    int x, y;
  };
  Tab() : c{0, 0} { init(); }
  Tab(const std::string &filepath);
  Tab(const Tab &) = delete;
  Tab(Tab &&) = delete;
  Tab operator=(const Tab &) = delete;
  Tab operator=(Tab &&) = delete;
  ~Tab() { endwin(); } /* End curses mode*/

  void init();
  void loop();

private:
  std::shared_ptr<Buf> buf;
  Cursor c;
};

#endif
