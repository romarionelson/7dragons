#pragma once
#include <iostream>
#include <string>
using namespace std;


class Exception {
	std::string msg;
	/*
	Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
	*/
public:
	Exception(string m) : msg(m) {
	}
	void setMessage(string m) {
		msg = m;
	}
	
	string getMessage() {
		return msg;
	}
	void report() {
		std::cout << "Mon exception : " << msg << std::endl;
	}




		
};
