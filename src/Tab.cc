#include<memory>


#include<curses.h>



#include "Tab.h"

Tab::Tab(const std::string &filepath)  {
      Tab();
      buf=std::make_shared<Buf>(filepath);
  }
void Tab::init(){
    initscr();			/* Start curses mode 		  */
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    scrollok(stdscr,true);
}

void Tab::loop(){
    printw(buf->get_content().c_str());
    int c,xc,yc;
    while (1) {
        getyx(stdscr,yc,xc);
        c=getch();
        switch(c){
            case KEY_RIGHT:
                xc++;
                move(yc,xc);
                break;
            case KEY_LEFT:
                xc--;
                move(yc,xc);
                break;
            case KEY_UP:
                yc--;
                move(yc,xc);
                break;
            case KEY_DOWN:
                yc++;
                move(yc,xc);
                break;
            case 'q': 
                refresh();			/* Print it on to the real screen */
                endwin();			/* End curses mode		  */
                return;
        };
    }
}
