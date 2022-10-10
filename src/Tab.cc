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
    auto& lines=buf->get_content();
    int linesCount=lines.size();
    slideIndex+=shift;
    int remainedLines=linesCount-slideIndex;
    if(slideIndex<0){
        slideIndex=0;
        return;
    }
    if(remainedLines<height){
        slideIndex-=shift;
        return;
    }

    clear();
    refresh();
    for(int i=0;i<height && (slideIndex+i)<linesCount;i++){
        if(i==height-1){
            addstr((lines[slideIndex+i]).c_str());
        }
        else{
            addstr((lines[slideIndex+i]+"\n").c_str());
        }
    }
}

void Tab::loop(){
    auto& lines=buf->get_content();
    for(int i=0;i<height;i++){
            if(i==height-1){
                addstr((lines[i]).c_str());
            }
            else{
                addstr((lines[i]+"\n").c_str());
            }
    }
    int c,xc,yc;
    while (1) {
        getyx(stdscr,yc,xc);
        c=getch();
        switch(c){
            case 'b':
                tab_scroll(1);
                break;
            case 'c':
                tab_scroll(-1);
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
