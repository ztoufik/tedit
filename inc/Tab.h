#ifndef _WIN_
#define _WIN_

#include<memory>
#include<map>

#include<curses.h>

#include"Buf.h"

class Tab {
public:
    struct Cursor {
        private:
            std::pair<int,int> xy;
        public:
            Cursor(int,int);
            Cursor(const Cursor &) = delete;
            Cursor(Cursor &&) = delete;
            Cursor operator=(const Cursor &) = delete;
            Cursor operator=(Cursor &&) = delete;
            void setCursor(int,int);
            void reset();
            const std::pair<int,int>& getCursor() const ;
    };
  Tab() ;
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
  int height,width,slideIndex;

  void ver_scroll(int );
  void reset( );
  void horz_scroll(int );
  void draw_slide();
};

#endif
