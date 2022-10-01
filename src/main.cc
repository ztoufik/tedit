#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<string_view>
#include<exception>



#include<curses.h>



class EditorException:std::exception{
    public:
        EditorException(std::string& message):message(message){}
        EditorException(std::string&& message):message(message){}
    private:
        std::string message;
};

void init(){
    initscr();			/* Start curses mode 		  */
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    scrollok(stdscr,true);
}

void display_file_content(const char* filepath){
    std::string line;
    std::stringstream out_string;
    std::ifstream myfile (filepath);

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            out_string<<line<<'\n';
        }
        myfile.close();
        printw(out_string.str().c_str());
    }
    else{
        printw("unable to open file");
    }
}

int main(){
    init();

    display_file_content("/home/toufik/src/tedit/src/main.cc");

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */
    return 0; 
}
