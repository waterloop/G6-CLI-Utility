#include "parser.h"
#include "common.h"

// validate specs:
// must get current state of pod
// if pod returns 'ok' to a state change req, we can proceed with the state change 
bool Parser::validate(std::string s){
    bool flag = false;
    for(auto word : VALID_COMMANDS){
        if (word == s) {
            flag = true;
        }
    }
    if (flag){
        // TODO:
        // send req to pod
        // if pod returns a status of "OK", we will return true
        return true;
    }
    else {
        return false;
    }

}


int Parser::execute(std::string s){
    

    return 0;
}

CommandType Parser::getCommandType(const std::string& command){
    
}