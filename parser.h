#ifndef p
#define p
#include<string>

class Parser {
public:
    std::string arg;
    CommandType getCommandType(const std::string& command);
};

#endif