/*
Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
*/

#include "ActionCardType.h"
#include "Table.h"
#include "Player.h"
#include "AnimalCardFactory.h"
#include <vector>
#include "Deck.h"

int main() {


	std::cout << " -----------------------------------------------\n";
	std::cout << "|                                               |\n";
	std::cout << "|                BONNE AVENTURE                 |\n";
	std::cout << "|                                               |\n";
	std::cout << " -----------------------------------------------\n";
	//AnimalCardFactory factory;
	QueryResult result;



	int index = 0;
	Table table;
	AnimalCardFactory *factory1= AnimalCardFactory::getFactory();
	Deck<std::shared_ptr<AnimalCard> > deck = factory1->getDeck();
	

	//Cette variable regarde si un joueur a gagner
	bool win = false;
	std::string tab[5]{ "bear","deer", "hare", "moose", "wolf" };

	int noJoueurs;
	do {
		std::cout << "Entrer le nombre de joueurs (etre 2 et 5): \n";
		std::cin >> noJoueurs;
	} while (noJoueurs < 2 || noJoueurs>5);

	std::cout << "Vous avez entrer: " << noJoueurs << " joueurs \n";
	Player ** pl = new Player*[noJoueurs];
	std::string names;
	cout << "Entrer le noms des joueurs: \n";



	for (int i = 0; i < noJoueurs; ++i) {
		std::cin >> names;
		pl[i] = new Player(tab[i], names);

	}

	for (int i = 0; i < noJoueurs; ++i) {
		for (int j = 0; j < 3; ++j) {

			pl[i]->playerHand += deck.draw();
		}

	}

	//La boucle commence
	while (!win) {
	//Numero de la carte a choisir
	int choisiCarte = 0;
	//Coordoner de la position d'ou la carte sera placer sur la carte
	int row, col;
	//Partiter de la carte
	int parite = 0;

	std::shared_ptr<AnimalCard> carteAjouer;

	for (int i = 0; i < noJoueurs; ++i) {
		//J'imprime la table
		std::cout << "Voici la table actuelle" << std::endl;
		std::cout << table << std::endl;
		//Prend une carte dans le deck et le met dans la main
		pl[i]->playerHand += deck.draw();
		std::cout << (*pl[i]);
		do {
			std::cout << "Veuillez choisir une carte dans vos mains en choisisant ";
			std::cout << "parmis les index au dessus de votre main, c'est a dire entre 0 et " << pl[i]->playerHand.hand.size() - 1 << std::endl;
			std::cin >> choisiCarte;

		} while (choisiCarte < 0 || choisiCarte > pl[i]->playerHand.noCards());
		
		carteAjouer = pl[i]->playerHand[choisiCarte]; //Updated 
		pl[i]->playerHand -= carteAjouer;

		do {
			std::cout << "Entrer une position valide pour placer votre carte" << std::endl;
			std::cin >> row >> col;
			parite = table.addAt(carteAjouer, row, col);


		} while (parite < 1);

		///////////////

		for (int i = 0; i < noJoueurs; ++i) {
			win = table.win(pl[i]->getSecretAnimal());
			if (win) std::cout << "Bravo! Le joueur ayant comme animal secret pour " << pl[i]->getSecretAnimal() << " a Triompher haut la main \n\n"; break;
		}
		//I was here 
		std::shared_ptr<ActionCard> card = std::dynamic_pointer_cast<ActionCard>(carteAjouer);
		if (card !=nullptr) {
			
			if (std::dynamic_pointer_cast<MooseAction>(card)) {
				result = card->query();

				if (result.action) {
					//c'est ici que l'echange des cartes secrete entre les joueurs se fait
					std::string temp = pl[noJoueurs - 1]->getSecretAnimal();
					for (int index = noJoueurs - 2; index >= 0; --index) {
						pl[index + 1]->setSecretAnimal(pl[index]->getSecretAnimal());
					}

					pl[0]->setSecretAnimal(temp);
				}
				else {
					std::cout << "Vous avez choisi de ne pas executer l'action donc vous recevez un nombre de cartes correspont a la parite sur la table" << std::endl;
					while (parite != 0) {

						pl[i]->playerHand +=  deck.draw();
						--parite;
					}
				}
			}
			
			
			
			else {
				result = card->query();
				if (result.action) {
					card->perfom(table, pl[i], pl[0], result);
				}
				else {

					std::cout << "Vous avez choisi de ne pas executer l'action donc vous recevez un nombre de cartes correspont a la parite sur la table" << std::endl;
					while (parite != 0) {

						pl[i]->playerHand += deck.draw();
						--parite;
					}
				}

			}
		}
		else {
			while (parite != 0) {

				pl[i]->playerHand += deck.draw();
				--parite;
			}


		}
	
	}
	
}



	delete[] pl;
	system("pause");
	return 0;
}
