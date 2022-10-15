#include<iostream>
#include<memory>
#include<map>


#include<curses.h>



#include "../inc/Tab.h"


Tab::Cursor::Cursor(int x,int y):xy(x,y){ }

void Tab::Cursor::setCursor(int x,int y){
    xy.first=x;
    xy.second=y;
    move(y,x);
}

void Tab::Cursor::reset(){
    const auto& xy=getCursor();
    setCursor(xy.first,xy.second);
}
const std::pair<int,int>& Tab::Cursor::getCursor() const {
    return xy;
}

Tab::Tab() : c(0, 0) {
    init(); 
    getmaxyx(stdscr,height,width);
    slideIndex=0;
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

void Tab::reset(){
    clear();
    refresh();
}

void Tab::draw_slide(){
    reset();
    auto& lines=buf->get_content();
    int linesCount=lines.size();
    for(int i=0;i<height && (slideIndex+i)<linesCount;i++){
        if(i==height-1){
            addstr((lines[slideIndex+i]).c_str());
        }
        else{
            addstr((lines[slideIndex+i]+"\n").c_str());
        }
    }
    c.reset();
}

void Tab::ver_scroll(int shift){
    int linesCount=buf->get_content().size();
    int remainedLines=linesCount-slideIndex;

    if(remainedLines<height && shift>0){
        return;
    }

    if(slideIndex<=0 && shift < 0){
        slideIndex=0;
        return;
    }
    slideIndex+=shift;
    draw_slide();
}

void Tab::loop(){
    draw_slide();
    int c;
    int xc,yc;
    while (1) {
        const auto& xy=this->c.getCursor();
        c=getch();
        switch(c){
            case 'b':
                ver_scroll(1);
                break;
            case 'c':
                ver_scroll(-1);
                break;
            case KEY_RIGHT:
                if(xy.first==width-1){
                    xc=0;
                    if(xy.second==height-1){
                        ver_scroll(1);
                    }else{
                        yc=xy.second+1;
                    }
                }
                else{
                    xc=xy.first+1;yc=xy.second;
                }
                this->c.setCursor(xc,yc);
                break;
            case KEY_LEFT:
                if(xy.first==0){
                    xc=width-1;
                    if(xy.second==0){
                        ver_scroll(-1);
                    }else{
                        yc=xy.second-1;
                    }
                }
                else{
                    xc=xy.first-1;yc=xy.second;
                }
                this->c.setCursor(xc,yc);
                break;
            case KEY_UP:
                if(xy.second==0){
                    ver_scroll(-1);
                }
                else{
                    this->c.setCursor(xy.first,xy.second-1);
                }
                break;
            case KEY_DOWN:
                if(xy.second==height-1){
                    ver_scroll(1);
                }
                else{
                    this->c.setCursor(xy.first,xy.second+1);
                }
                break;
            case 'q': 
                refresh();			/* Print it on to the real screen */
                endwin();			/* End curses mode		  */
                return;
        };
    }
}
