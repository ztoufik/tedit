#include<iostream>
#include<string>
#include<exception>



#include<stdlib.h>
#include<cctype>
#include<termios.h>
#include<curses.h>



//class EditorException:std::exception{
class EditorException{
    public:
        EditorException(std::string& message):message(message){}
        EditorException(std::string&& message):message(message){}
    private:
        std::string message;
};


int main(){
    initscr();			/* Start curses mode 		  */
	printw("Hello World !!!");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

	return 0;

    return 0;
}
