/*
Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
*/

#pragma once
#include "ActionCards.h"
#include <string>


class StartCard : public NoSplit {
	std::string first;
	std::tuple<string, string, string, string> tuple;

	public:
		StartCard(std::string first): NoSplit(first), first(first){
		
			tuple = std::make_tuple(first, first, first, first);
		}


		std::tuple<string, string, string, string> getTuple() {
			return tuple;

		}
		

	
		

};