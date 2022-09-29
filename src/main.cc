#include<iostream>
#include<string>
#include<exception>



#include<stdlib.h>
#include<cctype>
#include<termios.h>
#include<ncurses_dll.h>


#define CTRL_KEY(k) ((k) & 0x1f)
const int STDIN_FILENO=0;

//class EditorException:std::exception{
class EditorException{
    public:
        EditorException(std::string& message):message(message){}
        EditorException(std::string&& message):message(message){}
    private:
        std::string message;
};

struct termios orig_termios;
void disableRawMode() {
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios)){
        throw EditorException("failed to set terminal attrs");
    }
}

void enableRawMode() {
    if(tcgetattr(STDIN_FILENO, &orig_termios)==-1){
        throw EditorException("failed to get terminal attrs");
    }
    atexit(disableRawMode);
    struct termios raw = orig_termios;
    raw.c_iflag &= ~(ICRNL|IXON);
    raw.c_oflag &=~(OPOST);
    raw.c_lflag &= ~(ECHO|ICANON|ISIG|IEXTEN);
    raw.c_cflag |= (CS8);
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw)){
        throw EditorException("failed to set terminal attrs");
    }
}


int main(){
    enableRawMode();

    std::cout<<"enter charter"<<'\n';
    char c;
    while(std::cin.get(c)){
        if(iscntrl(c)){
            std::cout<<int(c)<<'\n';
            if(c==CTRL_KEY('q')){
                break;
            }
        }
        else{
            std::cout<<c<<':'<<int(c)<<'\n';
        }
    }
    return 0;
}
