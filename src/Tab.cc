#include<iostream>
#include<memory>


#include<curses.h>



#include "Tab.h"

Tab::Tab() : c{0, 0} {
    init(); 
    getmaxyx(stdscr,height,width);
    slideIndex=1;
}

Tab::Tab(const std::string &filepath):Tab() {
      buf=std::make_shared<Buf>(filepath);
  }

void Tab::init(){
    initscr();			/* Start curses mode 		  */
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    scrollok(stdscr,true);
}

void Tab::tab_scroll(int shift){
    slideIndex+=shift;
    auto& lines=buf->get_content();
    if(slideIndex>=0){
        clear();
        refresh();
        addstr("\ntest\n");
        for(int i=0;i<height && (slideIndex+i)<lines.size();i++){
            addstr(lines[slideIndex+i].c_str());
            addstr("\n");
        }
    }
    else{
        slideIndex=0;
    }
}

void Tab::loop(){
    auto& lines=buf->get_content();
    for(int i=0;i<height;i++){
        if(i==height-1)
            addstr((lines[i]).c_str());
        else
            addstr((lines[i]+'\n').c_str());
    }
    int c,xc,yc;
    while (1) {
        getyx(stdscr,yc,xc);
        c=getch();
        switch(c){
            case 'b':
                tab_scroll(1);
                break;
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
