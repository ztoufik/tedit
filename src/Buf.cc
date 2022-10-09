#include<fstream>
#include<vector>
#include<string>

#include "TeditException.h"
#include "Buf.h"


Buf::Buf(const std::string& filepath):filepath(filepath){
    std::string line;
    std::ifstream myfile (filepath);
    if (myfile.is_open())
    {
        while(std::getline(myfile,line)){
            content.push_back(std::forward<std::string>(line));
        }
        myfile.close();
    }
    else{
        throw TeditException("can't open file "+filepath);
    }
}

std::vector<std::string>& Buf::get_content() {
    return content;
}
