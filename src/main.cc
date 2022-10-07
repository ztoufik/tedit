#include<curses.h>

#include"Buf.h"
#include"Tab.h"

int main(){
    Tab tab;
    const Buf buf("/home/toufik/src/tedit/src/main.cc");
    printw(buf.get_content().c_str());
    tab.loop();
    return 0;
}
