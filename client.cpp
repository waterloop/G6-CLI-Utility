#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(){
    sockaddr_rc addr = { 0 };  
    char BT_address[18] = "34:FE:77:9D:C1:95";
    char response_buffer[1024] = { 0 };

    int s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM); 

    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = 1; // may need to cast to uint_8
    str2ba(BT_address, &addr.rc_bdaddr);

    int status = connect(s, (struct sockaddr* )&addr, sizeof(addr)); 

    if (status < 0) {
        std::cout << "OOPSIE POOPSIE NO CONNECTION 😒" << std::endl;
        return -1;
    }
    std::string command; 

    // begin CLI functionality

    return 0; 
}

