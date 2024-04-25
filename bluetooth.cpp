#include "bluetooth.h"
#include "parser.h"
#include "client.h"
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

void Bluetooth::sendRPCRequest(const std::string& command){
    Parser parser;
    int s = createSocket();
    CommandType cmdType = parser.getCommandType(command);

    switch (cmdType){
        case BEGIN:
            sendBeginRequest(command);
            break;
        case END:
            sendEndRequest(command);
            break;
        case AUTOPILOT:
            sendAutopilotRequest(command);
            break;
        case RESET:
            sendResetRequest(command);
            break;
        case BRAKE:
            sendBrakeRequest(command);
            break;
        case ACCELERATE:
            sendAccelerateRequest(command);
            break;
        case DECELERATE:
            sendDecelerateRequest(command);
            break;
        case UNKNOWN:
            this->sendUnknownRequest(command); // send the unknown request message to the pi
            break;
        default:
            return;
    }
}

// Repetition in case future changes need to be made to requests
void Bluetooth::sendBeginRequest(const std::string& command) {
    int w = write(s, command, len(command));
    if (w < 0) {
        std::cout << "REQUEST FAILED (┬┬﹏┬┬)" << std::endl;
    }
}

void Bluetooth::sendEndRequest(const std::string& command) {
    int w = write(s, command, len(command));
    if (w < 0) {
        std::cout << "REQUEST FAILED (┬┬﹏┬┬)" << std::endl;
    }
}

void Bluetooth::sendAutopilotRequest(const std::string& command) {
    int w = write(s, command, len(command));
    if (w < 0) {
        std::cout << "REQUEST FAILED (┬┬﹏┬┬)" << std::endl;
    }
}

void Bluetooth::sendResetRequest(const std::string& command) {
    int w = write(s, command, len(command));
    if (w < 0) {
        std::cout << "REQUEST FAILED (┬┬﹏┬┬)" << std::endl;
    }
}

void Bluetooth::sendBrakeRequest(const std::string& command) {
    int w = write(s, command, len(command));
    if (w < 0) {
        std::cout << "REQUEST FAILED (┬┬﹏┬┬)" << std::endl;
    }
}

void Bluetooth::sendAccelerateRequest(const std::string& command) {
    int w = write(s, command, len(command));
    if (w < 0) {
        std::cout << "REQUEST FAILED (┬┬﹏┬┬)" << std::endl;
    }
}

void Bluetooth::sendDecelerateRequest(const std::string& command) {
    int w = write(s, command, len(command));
    if (w < 0) {
        std::cout << "REQUEST FAILED (┬┬﹏┬┬)" << std::endl;
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