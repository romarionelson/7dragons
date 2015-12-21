/*
Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
*/

#ifndef Hand_INCLUDED__   
#define hand_INCLUDED__

#pragma once
#include <string>
#include <iostream>
#include "Hand.h"

class Player {

	std::string secret_animal;
	std::string player_name;

	

	public: 
		Hand playerHand;
		Player(std::string secret_animal, std::string player_name) :secret_animal(secret_animal),
		player_name(player_name){

		}
		std::string swapSecretAnimal(std::string& animal) {
			std::string temp = secret_animal;

			secret_animal = animal;
			animal = temp;
			return temp;
		

	}
		void setSecretAnimal(std::string animal) {

			this->secret_animal = animal;
		}

	std::string getSecretAnimal() const {

		return secret_animal;
	}
	friend  std::ostream& operator<<(std::ostream& out, const Player& player) {
		
		out<<"Nom du joueur: "<<player.player_name << "\nAnimal secret du joueur: " << player.secret_animal<<" \nMain du joueur: \n" <<player.playerHand<< std::endl;
		
		return out;

	}

	std::string getName() {

		return player_name;
	}


};
#endif