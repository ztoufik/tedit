#include<curses.h>

#include"Buf.h"
#include"Tab.h"

int main(){
    Tab tab("/home/toufik/src/tedit/test.txt");
    tab.loop();
    return 0;
}
