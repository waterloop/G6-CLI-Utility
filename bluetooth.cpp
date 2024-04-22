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
    return;
}


/*
gpt spawned this nightmare
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void sendBluetoothCommand(const std::string& command) {
    std::string device = "/dev/rfcomm0";  // Device file for the Bluetooth connection
    std::ofstream bt(device, std::ios::out);

    if (!bt.is_open()) {
        std::cerr << "Failed to open Bluetooth device." << std::endl;
        return;
    }

    // Send the command
    bt << command;
    bt.flush();
    std::cout << "Command sent: " << command << std::endl;

    // Wait for the response
    std::ifstream btIn(device, std::ios::in);
    std::string response;
    std::getline(btIn, response);
    std::cout << "Received response: " << response << std::endl;

    bt.close();
    btIn.close();
}

int main() {
    std::string command = "HELLO";
    sendBluetoothCommand(command);
    return 0;
}*/