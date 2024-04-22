#include <iostream>
#include <string>
#include "parser.h"

/*
    ARGPARSE:
        while loop to read in cin commands
        parser to handle each invocation of command 

*/
int main(){
    std::string command;
    Parser parser = Parser(); 
    while(std::cin >> command){
        if(command == "BEGIN"){
            parser.arg = command;
            parser.validate(command);
        }

    }


    std::cout << "Hello" << std::endl;
    return 0;
}