/*
Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
*/

#ifndef Hand_INCLUDED__   
#define hand_INCLUDED__

#include <iostream>
#include "ActionCardType.h"
#include <list>
#include "Exception.h"
#include <memory>

#include <iostream>

class Hand {

	int numOfCard = 0;
	
	public: 
		std::list < std::shared_ptr<AnimalCard>> hand;

		Hand& operator+=(std::shared_ptr<AnimalCard> animal) {
			
			hand.push_back(animal);
			
			numOfCard++;
			return *this;

		}
		Hand& operator-=(std::shared_ptr<AnimalCard> animal) {

		std::list< std::shared_ptr<AnimalCard>> ::iterator it = hand.begin();
		//iter->
		//*iter.setOrientation();
	
		
		if (it != hand.end())
			{
				hand.remove(animal);
				numOfCard--;
				
			}
			else {


				Exception exception("IllegalPick");
				throw exception;
			}
		
			return *this;

		}
		std::shared_ptr<AnimalCard> operator[](int index) {
			std::list< std::shared_ptr<AnimalCard>>::iterator iter = hand.begin();
			while (index != 0) {
				--index; 
				++iter;

			}
			return *iter;
		}

		int noCards() {

			return numOfCard;
		}

		

		friend std::ostream& operator<<(std::ostream& out, const Hand& _hand) {

			//out << "Animal secret du joueur: " << " Main du joueur: \n" << std::endl;

			std::list< std::shared_ptr<AnimalCard>>::const_iterator it = _hand.hand.begin();
			std::list< std::shared_ptr<AnimalCard>>::const_iterator itr = _hand.hand.begin();

			//animal->
			for (unsigned i = 0; i < _hand.hand.size(); ++i) {
				std::cout << i << "   ";
			}

			std::cout << std::endl;

			while (it != _hand.hand.end()) {
				
				(*it)->setOrientation(Orientation::UP);
				(*it)->printRow(EvenOdd::EVEN);
				++it;
				

			}
			std::cout << std::endl;
			//std::cout <<"\n"<< 1<<" ";
			
			while (itr != _hand.hand.end()) {

				(*itr)->setOrientation(Orientation::DOWN);
				(*itr)->printRow(EvenOdd::EVEN);
				++itr;


			}
			std::cout << std::endl;
			
			return out;
			
		}

};
#endif