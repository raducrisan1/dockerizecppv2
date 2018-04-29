#include <iostream>
#include <cstring>
#include <cassert>
#include <csignal>
#include <unistd.h>
#include "zmq.h"

void handler(int arg) {
    std::cout << "Term signal received. Value is: " << arg << std::endl;
}

int main() {
    std::cout << "Server started." << std::endl;
    void *context = zmq_ctx_new();
    void *reply = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(reply, "tcp://*:5200");
    assert(rc == 0);

    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    signal(SIGILL, handler);
    signal(SIGCHLD, handler);
    signal(SIGABRT, handler);

    while (true) {
        char buffer[100];
        zmq_recv(reply, buffer, 100, 0);
        buffer[99] = 0;
        std::cout << "received " << buffer << std::endl;

        if(!strcmp(buffer, "stop"))
            return 0;

        zmq_send(reply, "world", 5, 0);
        sleep(1);
    }
}