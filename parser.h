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
    
    //void read(std::string command);
    bool validate(const std::string s);
    int execute(const std::string s);
    CommandType getCommandType(const std::string& command);
};



#endif