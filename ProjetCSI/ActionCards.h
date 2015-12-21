/*
Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
*/

#pragma once
#ifndef Hand_INCLUDED__   // if x.h hasn't been included yet...
#define hand_INCLUDED__

#include "TypeDeCartes.h"
#include <ctype.h>
#include <string>
#include <iostream>
#include "QueryResult.h"
#include "StartCard.h"
#include "Table.h"


class ActionCard : public NoSplit {
	std::string d;

	std::tuple<string, string, string, string> tuple;
	public: 
		
			ActionCard(std::string d): NoSplit(d), d(d){
			
				tuple = std::make_tuple(d, d, d, d);
			}
			std::tuple<string, string, string, string> getTuple() {
				return tuple;

			}

			void printRow(EvenOdd) {
				std::cout << static_cast<char>(toupper(d[0])) << static_cast<char>(toupper(d[0]))<<"  ";

			}
			//virtual void printRow(EvenOdd){}
			virtual QueryResult query() = 0;
			virtual void perfom(Table&, Player*, Player*,QueryResult) = 0;
	



};

#endif