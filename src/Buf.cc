#include<fstream>
#include<sstream>
#include<string>

#include "TeditException.h"
#include "Buf.h"


Buf::Buf(const std::string& filepath):filepath(filepath){
    std::string line;
    std::ifstream myfile (filepath);
    if (myfile.is_open())
    {
        content<<myfile.rdbuf();
        myfile.close();
    }
    else{
        throw TeditException("can't open file "+filepath);
    }
}

std::string Buf::get_content() const{
    return content.str();
}
