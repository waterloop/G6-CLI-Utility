#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(){
    sockaddr_rc addr = { 0 };  
    char BT_address[17] = "34:FE:77:9D:C1:95";
    char response_buffer[1024] = { 0 };



    return 0; 
}

