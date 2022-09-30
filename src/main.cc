#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<exception>



#include<curses.h>



class EditorException:std::exception{
    public:
        EditorException(std::string& message):message(message){}
        EditorException(std::string&& message):message(message){}
    private:
        std::string message;
};


int main(){
    initscr();			/* Start curses mode 		  */
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    scrollok(stdscr,true);

    std::string line;
    const std::string path="/home/toufik/src/tedit/src/main.cc";
    std::stringstream out_string;
    std::ifstream myfile (path);

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

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */
    return 0; 
}
