#include <string>
enum CommandType {
    BEGIN,
    END,
    AUTOPILOT,
    RESET,
    BRAKE,
    ACCELERATE,
    DECELERATE,
    UNKNOWN
};
const std::string VALID_COMMANDS[] = {"BEGIN", "END", "AUTOPILOT", "RESET", 
                                        "BRAKE", "ACCELERATE", "DECELERATE"};

const int HEARTBEAT_RATE = 50; // in milliseconds



//define message formats
