#include<curses.h>

#include"Buf.h"
#include"Tab.h"

int main(){
    Tab tab("/home/toufik/src/tedit/src/main.cc");
    tab.loop();
    return 0;
}
