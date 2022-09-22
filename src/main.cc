#include<iostream>



#include<stdlib.h>
#include<cctype>
#include<termios.h>


const int STDIN_FILENO=0;

struct termios orig_termios;
void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);
    struct termios raw = orig_termios;
    raw.c_iflag &= ~IXON;
    raw.c_lflag &= ~(ECHO|ICANON|ISIG);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}


int main(){
    enableRawMode();



    std::cout<<"enter charter"<<std::endl;
    char c;
    while(std::cin.get(c) && c!='q'){
        if(iscntrl(c)){
            std::cout<<int(c)<<std::endl;
        }
        else{
            std::cout<<c<<':'<<int(c)<<std::endl;
        }
    }
    std::cout<<"charcter "<<c<<std::endl;
    return 0;
}
