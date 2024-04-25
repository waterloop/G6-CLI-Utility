#include "parser.h"
#include "common.h"

CommandType Parser::getCommandType(const std::string& command) {
    if (command == "BEGIN") return BEGIN;
    if (command == "END") return END;
    if (command == "AUTOPILOT") return AUTOPILOT;
    if (command == "RESET") return RESET;
    if (command == "BRAKE") return BRAKE;
    if (command == "ACCELERATE") return ACCELERATE;
    if (command == "DECELERATE") return DECELERATE;
    else return UNKNOWN;
}