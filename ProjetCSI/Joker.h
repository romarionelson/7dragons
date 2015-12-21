/*
	Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
*/

#pragma once
#include "TypeDeCartes.h"
#include <string>


class Joker : public NoSplit {

	std::string first;

	public:

	Joker(std::string first) : NoSplit(first), first(first) {

		tuple = std::make_tuple(first, first, first, first);
	}


	std::tuple<string, string, string, string> getTuple() {
		return tuple;

	}

};

