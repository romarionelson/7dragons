/*
Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
*/

#ifndef Hand_INCLUDED__   
#define hand_INCLUDED__

#pragma once
#include <iostream>
#include <memory>
#include <string>
#include "ActionCardType.h"
#include <ctype.h>

//#include "Joker.h"
//#include "Hand.h"
using namespace std;

class Table {

	//unique_ptr<int*[]> smp_pi(new int*[5]);
	shared_ptr<AnimalCard> tableau[103][103];
	

public:
	Table() {
		//N'importe quel carte peut parier avec la carte de depart (denoter S)
		tableau[52][52] = shared_ptr<AnimalCard> (new StartCard("s")); //new StartCard()

	}

	//ajoute un animal a la position demander et retourne ccombien d'animeaux sont parier avec 
	int addAt(std::shared_ptr<AnimalCard> card, int row, int col) {
		int parite = 0;

		//MyClass *m = dynamic_cast<MyClass *>(ptr);
		//Parmis ces cast un seul sera utiliser parce que lors  du test (if) les autres pointeurs retourneront
		//null car il ne pointeront pas a la bonne classe
		

		if (tableau[row][col + 1]) {

			if (std::get<1>(card->getTuple()) == std::get<0>(tableau[row][col + 1]->getTuple())
				|| std::get<1>(tableau[row][col + 1]->getTuple()) == "j" 
				|| std::get<1>(tableau[row][col + 1]->getTuple()) == "s") {
				++parite;
			}



			if (std::get<3>(card->getTuple()) == std::get<2>(tableau[row][col + 1]->getTuple())
				&& std::get<3>(card->getTuple()) != std::get<1>(card->getTuple()))
				 {
				++parite;
			}
		}


		if(tableau[row + 1][col]){
			if (std::get<2>(card->getTuple()) == std::get<0>(tableau[row + 1][col]->getTuple()) 
			|| std::get<0>(tableau[row + 1][col]->getTuple()) =="s" 
			|| std::get<0>(tableau[row + 1][col]->getTuple()) == "j") {
			++parite;
			}
		
			if (std::get<3>(card->getTuple()) == std::get<1>(tableau[row + 1][col]->getTuple())
			&& std::get<1>(tableau[row + 1][col]->getTuple()) != "s" && 
			 std::get<0>(tableau[row + 1][col]->getTuple()) !=  "j")
			 {
			++parite;
		}
}
		if (tableau[row-1][col]) {
			if (std::get<0>(card->getTuple()) == std::get<2>(tableau[row - 1][col]->getTuple())
				|| std::get<2>(tableau[row - 1][col]->getTuple()) == "j" 
				|| std::get<2>(tableau[row - 1][col]->getTuple()) == "s") {
				++parite;
			}
			if (std::get<1>(card->getTuple()) == std::get<3>(tableau[row-1][col]->getTuple())
				&& std::get<2>(tableau[row - 1][col]->getTuple()) != "s"
				&& std::get<3>(tableau[row - 1][col]->getTuple()) !="j")
				
				
				 {
				++parite;
			}
		}	
		if (tableau[row][col - 1]) {
			if (std::get<0>(card->getTuple()) == std::get<1>(tableau[row][col - 1]->getTuple())
				|| std::get<1>(tableau[row][col - 1]->getTuple()) == "j" 
				|| std::get<0>(tableau[row][col - 1]->getTuple()) == "s") {
				++parite;
			}
			if (std::get<2>(card->getTuple()) == std::get<3>(tableau[row][col - 1]->getTuple()) 
				&& std::get<3>(tableau[row ][col-1]->getTuple()) != "s"
				&& std::get<1>(tableau[row][col-1]->getTuple()) != "j")

			 {
				++parite;
			}
		}
		//Si la parite un moins que un, sa ve dire que le placement nest pas valide donc la 
		//carte n'a pas ete placer

		//if (parite < 1) {
		//	Exception exception("Illegal placement");
		//	throw exception;
		//}
		if(parite>0){
		
		tableau[row][col] = card;
}
		return parite;

	}
	//Retire la carte a la position demander et retourne s'il n'y a pas de carte
	std::shared_ptr<AnimalCard> pickAt(int row, int col) {

		if (tableau[row][col]) {
			shared_ptr<AnimalCard> temp = tableau[row][col];
			tableau[row][col] = NULL;
			return temp;
		}
		else {

			return NULL;
		}


	}
	//retourne la carte à cette position (retourne null si il y a aucune carte).

	std::shared_ptr<AnimalCard> get(int row, int col) {
		if (tableau[row][col]) {

			return tableau[row][col];
		}
		else {

			return NULL;
		}

	}

	//Methode pour imprimer la table

	friend std::ostream& operator<<(std::ostream& out, const Table& table) {

		//Ce tableau nous dira quel case dans le tableau contient une carte et quel n'en contient pas
		//dans ce cas si tab[i][j]=-1 on saura qu'il n'y pas pas de carte dans cette case
		int maxRow = 0;
		int maxCol = 0;
		int col ;
		int row;
		int colEnd;
		int rowEnd;
		bool col1 = false;
		bool row1 = false;
		
		//tab[52][52] = 0;
		
		for (int i = 0; i < 103; ++i) {
			for (int j = 0; j < 103; ++j) {
				if ((table.tableau[j][i])){

					col1 = true;
			}
			}
			if (col1) {
				col = i;
				break;
			}
		}


	
		//changed 0 to col

		
		for (int i = 0; i < 103; ++i) {
			for (int j = col; j < 103; ++j) {
				if ((table.tableau[i][j])) {

					row1 = true;
				}
			}
			if (row1) {

				row = i;
				break;
			}
		}
		//std::cout << "Row " << row << " Col " << col << std::endl;
		//std::cout << "Row " << row << " Col " << col << std::endl;
		bool d = false;
		//////////////////////////////////////////////////////////// added 0 instead of row and col
		for (int i = row; i < 103; ++i) {
			d = false;
			for (int j = col; j < 103; ++j) {
				if ((table.tableau[i][j])) {
					
					d = true;
					continue;
				}
			}
			if (d==false) {
				rowEnd = i-1;
				break;
			}
		}
		bool _d = false;
		// addded 0 instead of row and continue
		for (int i = row+1; i < 103; ++i) {
			_d = false;
			for (int j = col; j < 103; ++j) {
				if ((table.tableau[j][i])) {

					_d = true;

				}
			}
			if (!_d) {
				colEnd = i;
				break;
			}
		}


		for (int i = 0; i < colEnd - col; ++i) {
			std::cout << i << "   ";
		}
		std::cout << std::endl;

		for (int i = row; i <= rowEnd; ++i) {

			for (int j = col; j <= colEnd; j++) {


				if ((table.tableau[i][j])) {
					table.tableau[i][j]->setOrientation(Orientation::UP);
					table.tableau[i][j]->printRow(EvenOdd::EVEN);
					
				}
				else {
					std::cout << "    ";
				}
			}

			std::cout << "\n";
			for (int j = col; j < colEnd; j++) {


				if ((table.tableau[i][j])) {
					table.tableau[i][j]->setOrientation(Orientation::DOWN);
					table.tableau[i][j]->printRow(EvenOdd::EVEN);

				}
				else {
					std::cout << "    ";
				}



			}
			std::cout << std::endl;
			}
			
		
		return out;
		}

		//Fonction qui regarde si un joueur a gagner

		bool win(std::string& _animal) {
			
			std::string animal =  _animal.substr(0, 1);
			int count = 0;
			for (int i = 0; i < 103; i++) {
				for (int j = 0; j < 103; ++j) {
					if (tableau[i][j]) {
						////
						if (std::get<0>(tableau[i][j]->getTuple()) == animal || std::get<1>(tableau[i][j]->getTuple()) == animal ||
							std::get<2>(tableau[i][j]->getTuple()) == animal || std::get<3>(tableau[i][j]->getTuple()) == animal || std::get<0>(tableau[i][j]->getTuple()) == "s"
							|| std::get<0>(tableau[i][j]->getTuple()) == "j") {

							++count;
						}
					}
					///


				}


			}


			if (count >= 12) {
				return true;
			}
			else {
				return false;

			}


		}



		
	
};



#endif