/*
Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
*/

#ifndef Hand_INCLUDED__   
#define hand_INCLUDED__

#pragma once
#include "Deck.h"
#include "ActionCardType.h"
#include <algorithm>
#include <random>
#include "Joker.h"
#include <chrono>




class AnimalCardFactory {

	static int count;

	std::string animal[5]{ "b", "d", "h", "m", "w" };

public:
	Deck<std::shared_ptr<AnimalCard> > deck;


	AnimalCardFactory() {
		

		//Nosplit 
		for (int i = 0; i < 5; i++) {
			deck.push_back(shared_ptr<AnimalCard>(new NoSplit(animal[i])));
			//15 carte d'actions (1 animal pour 3 cartes)

		}
		for (int j = 0; j < 3; ++j) {
			deck.push_back(shared_ptr<ActionCard>(new BearAction(animal[0])));
		}
		for (int j = 0; j < 3; ++j) {
			deck.push_back(shared_ptr<ActionCard>(new HareAction(animal[2])));
		}
		for (int j = 0; j < 3; ++j) {
			deck.push_back(shared_ptr<ActionCard>(new WolfAction(animal[4])));
		}
		for (int j = 0; j < 3; ++j) {
			deck.push_back(shared_ptr<ActionCard>(new DeerAction(animal[1])));
		}
		for (int j = 0; j < 3; ++j) {
			deck.push_back(shared_ptr<ActionCard>(new MooseAction(animal[3])));
		}

		//la lettre j representera le joker, n'importe quel carte peut etre parier a cette carte

		deck.push_back(shared_ptr<AnimalCard>(new Joker("j")));
		//Split2

		deck.push_back(shared_ptr<AnimalCard>(new Split2(animal[0], animal[1], false)));
		deck.push_back(shared_ptr<AnimalCard>(new Split2(animal[0], animal[2], false)));
		deck.push_back(shared_ptr<AnimalCard>(new Split2(animal[1], animal[3], false)));
		deck.push_back(shared_ptr<AnimalCard>(new Split2(animal[2], animal[4], false)));
		deck.push_back(shared_ptr<AnimalCard>(new Split2(animal[3], animal[4], false)));
		deck.push_back(shared_ptr<AnimalCard>(new Split2(animal[4], animal[0], true)));
		deck.push_back(shared_ptr<AnimalCard>(new Split2(animal[2], animal[1], true)));
		deck.push_back(shared_ptr<AnimalCard>(new Split2(animal[1], animal[4], true)));
		deck.push_back(shared_ptr<AnimalCard>(new Split2(animal[2], animal[3], true)));
		deck.push_back(shared_ptr<AnimalCard>(new Split2(animal[3], animal[0], true)));
		//Split3

		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[0], animal[1], animal[2], true)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[0], animal[1], animal[3], true)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[2], animal[3], animal[4], true)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[3], animal[4], animal[0], true)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[1], animal[2], animal[4], true)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[4], animal[0], animal[1], true)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[3], animal[4], animal[2], true)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[2], animal[1], animal[3], true)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[0], animal[3], animal[4], true)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[3], animal[2], animal[1], true)));

		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[0], animal[1], animal[2], false)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[1], animal[2], animal[3], false)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[1], animal[3], animal[4], false)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[3], animal[4], animal[0], false)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[4], animal[3], animal[0], false)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[3], animal[2], animal[1], false)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[2], animal[1], animal[0], false)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[4], animal[0], animal[2], false)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[3], animal[4], animal[1], false)));
		deck.push_back(shared_ptr<AnimalCard>(new Split3(animal[0], animal[2], animal[4], false)));

		//Split4

		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[0], animal[1], animal[2], animal[3])));
		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[1], animal[2], animal[3], animal[4])));
		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[2], animal[3], animal[4], animal[0])));
		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[3], animal[2], animal[1], animal[0])));
		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[4], animal[2], animal[3], animal[1])));
		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[1], animal[4], animal[2], animal[3])));
		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[0], animal[4], animal[1], animal[2])));
		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[0], animal[2], animal[4], animal[3])));
		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[0], animal[3], animal[1], animal[2])));
		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[1], animal[3], animal[0], animal[4])));
		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[4], animal[1], animal[0], animal[3])));
		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[2], animal[4], animal[0], animal[1])));
		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[2], animal[0], animal[1], animal[4])));
		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[1], animal[0], animal[3], animal[2])));
		deck.push_back(shared_ptr<AnimalCard>(new Split4(animal[3], animal[0], animal[4], animal[2])));


		std::random_shuffle(deck.begin(), deck.end());

	}

	Deck<std::shared_ptr<AnimalCard> > getDeck() {

	
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
		return deck;

	}
	static AnimalCardFactory* getFactory();


};

#endif