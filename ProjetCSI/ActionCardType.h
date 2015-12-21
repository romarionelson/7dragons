/*
Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
*/
#ifndef Hand_INCLUDED__   
#define hand_INCLUDED__
#pragma once

//#include "TypeDeCartes.h"
#include "ActionCards.h"
#include "Table.h"
#include <iostream>
#include <string>



class BearAction : public ActionCard {

	QueryResult result;
	std::string d;
	public:
			BearAction(std::string d): ActionCard(d),d(d){}
			

			QueryResult query() {
				 std::cout << "la carte Bear Action vous permet de  d'echanger votre main avec un autre joueur" << std::endl;
				 std::cout << "\nEntrer 1  pour executer l'action et 0 dans le cas contraire: " << std::endl;
				 std::cin >> result.action;
				 if (result.action) {
					 std::cout << "Veuillez entre l'index du joueur donc vous voulez la main, le nombre de joueurs vous est ennoncer plus haut" << std::endl;
					 std::cin >> result.indexMain;
				 }
			
				 
				 return result;

			}
			 void perfom(Table& table, Player* player,Player *end, QueryResult result) {
				 while (result.indexMain != 0) {
					 ++end;
					 result.indexMain--;

				 }


				 player->playerHand.hand.swap(end->playerHand.hand);

			 }

};

class DeerAction : public ActionCard {

	//Echange les animaux secret 
	std::string d;
	QueryResult result;
	public:
		DeerAction(std::string d) : ActionCard(d), d(d) {}

		QueryResult query() {
			 std::cout << "Vous avez pigez une carte (Deer Action) qui vous permet d'echanger votre animal secret contre quelqu'un d'autre" << std::endl;
			 
			 std::cout << "\nEntrer 1 pour executer l'action et 0 dans le cas contraire: " << std::endl;
			 std::cin >> result.action;
			 if (result.action) {
				 std::cout << "Parmis les joueurs mentionnez plus haut choisissez celui contre lequel vous voulez echanger votre carte" << std::endl;

				 std::cin >> result.IndexEchangeCarteSecret;
			 }
			

			 return result;

		 }
		 void perfom(Table&, Player* joueur, Player* end, QueryResult res) {
			
			 while (res.IndexEchangeCarteSecret != 0) {
				 ++end;
				 res.IndexEchangeCarteSecret--;

			 }
			 std::string temp = joueur->getSecretAnimal();
			 joueur->setSecretAnimal(end->getSecretAnimal());
			 end->setSecretAnimal(temp);


		 }


};

class HareAction : public ActionCard {
	std::string a;
	QueryResult result;
	public:
		HareAction(std::string a) : ActionCard(a),a(a) {}
	
		QueryResult query() {
			int i, j, k, l;
			std::cout << "Vous avez jouer une carte (Hare Action) qui vous permet de prendre une carte sur la table et de la jouer ailleur" << std::endl;
			std::cout << "Entrez les coordonner de la carte a prendre, en commencant par la colonne" << std::endl;
			std::cin >> i >> j;
			result.locationInitial = std::make_pair(i, j);
			std::cout << "\nEntrez maintenant les coordonner ou vous vous mettre la carte, en commencant par la colonne" << std::endl;
			std::cin >> k >> l;
			result.locationAplacer = std::make_pair(k, l);
			std::cout << "Entrer 1 pour executer l'action et 0 dans le cas contraire: " << std::endl;
			std::cin >> result.action;

			return result;

		}
		void perfom(Table& table , Player* player, Player*, QueryResult result ) {

			std::shared_ptr<AnimalCard> temp = table.pickAt(result.locationInitial.first, result.locationInitial.second);
			//Si la carte retourner est NULL, le joueur devra entrer de nouvelle coordonner
			while (!temp) {
				query();
			}

			table.addAt(temp, result.locationAplacer.first, result.locationAplacer.second);
		
		}

};

class MooseAction : public ActionCard {

	QueryResult result;
	std::string a;
	public:	
		MooseAction(std::string a) : ActionCard(a), a(a) {}

		QueryResult query() {


			std::cout << "Bravo, vous avez jouer une carte (Moose Action) qui vas permettre aux joueurs d'echanger leur cartes, \nle ";
			std::cout << "\njoueur 1 donne sa carte objectif au joueur 2 et le joueur 2 donne la sienne au joueur 3, et ainsi de suite" << std::endl;
			std::cout << "\nEntrer 1 pour executer l'action et 0 dans le cas contraire: " << std::endl;
			std::cin >> result.action;
			//std::vector<Player>::iterator iter = result.joueurs.begin();
			return result;

		}
		void perfom(Table&, Player*, Player*, QueryResult _result) {
		/*
		C'est le seul Perform() que j'ai implementer dans le main
		
		*/

		}
	

};

class WolfAction : public ActionCard {
	std::string a;
	QueryResult result;
	public:
		WolfAction(std::string a) : ActionCard(a), a(a) {}
		QueryResult query() {
			int i, j;
			std::cout << "Cette action (WOLF ACTION) vous permet de prendre une carte sur la table" << std::endl;
			std::cout << "\nEntrer 1 pour executer l'action et 0 dans le cas contraire: " << std::endl;
			std::cin >> result.action;
			
			std::cout << "Veuillez entrer l'index de la que vous voulez prendre en commencent par la colonne: \n";
			std::cin >> i >> j;
			result.indexCarte = std::make_pair(i, j);

			return result;

		}
		void perfom(Table& table, Player* joueur, Player*, QueryResult quer) {

			std::shared_ptr<AnimalCard> carte = table.pickAt(quer.indexCarte.first, quer.indexCarte.second);
			while (!carte) {
				/*
					S'il n'y a pas de carte a cette  position on rappelle la fonction query 
					pour que l'utilisateur entre une nouvelle carte
				*/
					query();

			}
			joueur->playerHand += carte; 

		}


};
#endif