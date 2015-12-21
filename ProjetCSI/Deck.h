/*
Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
*/

#pragma once
#ifndef Hand_INCLUDED__  
#define hand_INCLUDED__
#include "AnimalCard.h"
#include <ctype.h>
#include <memory>
#include <deque>
#include <vector>

template<class T> class Deck : public std::vector<T>{
	
	
	public: 

		T draw() {
			T a = this->back();
			this->pop_back();
			return a;


		}


};
#endif