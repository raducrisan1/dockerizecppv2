#include <iostream>
#include <cstring>
#include <cassert>
#include "zmq.h"

int main() {
    std::cout << "Server started." << std::endl;
    void *context = zmq_ctx_new();
    void *reply = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(reply, "tcp://*:5200");
    assert(rc == 0);
    while (true) {
        char buffer[100];
        zmq_recv(reply, buffer, 100, 0);
        buffer[99] = 0;
        std::cout << "received " << buffer << std::endl;

        if(!strcmp(buffer, "stop"))
            return 0;

        zmq_send(reply, "world", 5, 0);
    }
}