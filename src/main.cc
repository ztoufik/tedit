#include<curses.h>

#include "../inc/Buf.h"
#include "../inc/Tab.h"

int main(){
    Tab tab("/home/toufik/src/tedit/test.txt");
    tab.loop();
    return 0;
}
