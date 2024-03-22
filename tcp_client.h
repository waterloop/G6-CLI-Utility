#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
// #include "services.pb.h" // uncomment when the service is compiled

/* header file to define behaviour for all messages.
// this is basically a virtual class (i think). 
it wont really have any member variables. It's more so a way to separate 
our functions. I think these are called interfaces in most applications 
but some people say they are virtual functions. i really dont know and 
honestly i dont care. we are gonna do some basic socketing tho. If you need
a reference for how this works, please check out these resources
https://github.com/jzarnett/ece252/blob/master/lectures/compiled/L07-Sockets.pdf
https://github.com/jzarnett/ece252/blob/master/lectures/compiled/L08-Network_Communication.pdf
Thank you Zarnett for being the goat <3
*/

class TCP_Client{
    public:



};