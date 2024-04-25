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
    CommandType getCommandType(const std::string& command);
};



#endif