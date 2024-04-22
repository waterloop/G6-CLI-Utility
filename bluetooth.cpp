#include "bluetooth.h"
#include "parser.h"


void Bluetooth::sendRPCRequest(const std::string& command){
    Parser parser;
    CommandType cmdType = parser.getCommandType(command);
    switch (cmdType){
        case BEGIN:
            sendBeginRequest(command);
        case END:
            sendEndRequest(command);
        case AUTOPILOT:
            sendAutopilotRequest(command);
        case RESET:
            sendResetRequest(command);
        case BRAKE:
            sendBrakeRequest(command);
        case ACCELERATE:
            sendAccelerateRequest(command);
        case DECELERATE:
            sendDecelerateRequest(command);
        case UNKNOWN:
            this->sendUnknownRequest(command); // send the unknown request message to the pi
        default:
            return;
    }
}
void Bluetooth::sendUnknownRequest(const std::string& command){

}