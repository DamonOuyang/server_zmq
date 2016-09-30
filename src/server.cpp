//============================================================================
// Name        : server.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <zmq.hpp>
#include <ctime>
using namespace std;

int main() {
	//  Prepare our context and socket
	zmq::context_t context(1);
	zmq::socket_t socket(context, ZMQ_REP);
	socket.bind("tcp://*:5555");
	// struct timespec tv = {1,0};
	int i = 0;
	int a = clock();
	zmq::message_t reply(100);
	memcpy((void *) reply.data(), "server", 100);
	while (1) {
		zmq::message_t request;
//  Wait for next request from client
		socket.recv(&request);
//       char s[500]={0};
//       memcpy(s,request.data(),5);
//        std::cout <<s<< std::endl;

//  Do some 'work'
// sleep(1);
//        if(nanosleep(&tv, NULL) == -1)
//        {
//            exit(-1);
//        }
		//  Send reply back to client
		//	zmq::message_t reply(100);
		//memcpy((void *) reply.data(), "server", 100);
		for (int i = 0; i < 100000; ++i) {
			socket.send(reply);
		}
		int b = clock();
		std::cout << "time is " << double((b - a) / 1000) << std::endl;
		//std::cout << i++ << std::endl;
	}

	return 0;
}
