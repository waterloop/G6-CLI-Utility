#ifndef p
#define p
// control object for parsing all args


// functions:
// read()
// validate()
// exception_handler()
#include<string>

class Parser {
public:
    std::string arg;
    Parser(); // init parser object
    
    //void read(std::string command);
    bool validate();
    
};



#endif