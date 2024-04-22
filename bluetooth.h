#include "common.h"

/*
enum CommandType {
    BEGIN,
    END,
    AUTOPILOT,
    RESET,
    BRAKE,
    ACCELERATE,
    DECELERATE
};

*/


class Bluetooth {
public:
    void sendRPCRequest(const std::string& command);
    void sendUnknownRequest(const std::string& command);
    void sendBeginRequest(const std::string& command);
    void sendEndRequest(const std::string& command);
    void sendAutopilotRequest(const std::string& command);
    void sendResetRequest(const std::string& command);
    void sendBrakeRequest(const std::string& command);
    void sendAccelerateRequest(const std::string& command);
    void sendDecelerateRequest(const std::string& command);

};