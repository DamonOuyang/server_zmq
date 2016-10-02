//============================================================================
// Name        : zmq_server.cpp
// Author      : siwei
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <iostream>
//#include <zmq.hpp>
//#include <ctime>
//#include <string>
//using namespace std;
//
//int main() {
//	double a = clock();
//	zmq::context_t contest(1);
//	zmq::socket_t pub(contest, ZMQ_PUB);
//	pub.bind("tcp://*:5563");
//	string s="siweilxy";
//	string title="A";
//	zmq::message_t message(title.length());
//	zmq::message_t message1(s.length());
//	memcpy( message.data(), title.data(), title.length());
//	memcpy(message1.data(),s.data(),s.length());
//	std::cout<<"start"<<std::endl;
//	while (1) {
//		std::cout<<"send"<<std::endl;
//		pub.send(message,ZMQ_SNDMORE);
//		pub.send(message1);
//	}
//	double b = clock();
//	std::cout << (b - a) / CLOCKS_PER_SEC << std::endl;
//	return 0;
//}
#include "zhelpers.hpp"
#include <string>
using namespace std;
int main() {
	//  Prepare our context and publisher
	zmq::context_t context(1);
	zmq::socket_t publisher(context, ZMQ_PUB);
	publisher.bind("tcp://*:5563");
	string title = "A";
	string s = "siweilxy";
	while (1) {
		//  Write two messages, each with an envelope and content
		//s_sendmore(publisher, "A");
		zmq::message_t message(title.size());
		memcpy(message.data(), title.data(), title.size());
		publisher.send(message, ZMQ_SNDMORE);
		//publisher.send(message);
		//s_send(publisher, "We don't want to see this");
		zmq::message_t message1(s.size());
		memcpy(message1.data(), s.data(), s.size());
		publisher.send(message1);

		//s_sendmore(publisher, "B");
		//s_send(publisher, "We would like to see this");
		//sleep(1);
	}
	return 0;
}
