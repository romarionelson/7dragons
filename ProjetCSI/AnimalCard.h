/*
Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
*/

#ifndef Hand_INCLUDED__   
#define hand_INCLUDED__



#pragma once
#include <iostream>

#include <string>
using namespace std;
enum class Orientation {
	UP, DOWN

};

enum class EvenOdd {
	EVEN, ODD

};
class AnimalCard {
	
	Orientation orientation;
	EvenOdd evenOdd;

public:
	/*
	C'est avec la tructure Tuple que j'ai décidé de stocker mes variables pour chaque class
	Ca veux tout simplement dire par exemple que pour la classe Noplit les 4 variables seront 
	les meme tandis que dans Split4 les 4 valeurs seront differente
	*/
	virtual std::tuple<string, string, string, string> getTuple() = 0;
	
	/*
		J'ai choisi d'implementer toute ses methodes individuellement dans chaque sous classe

	*/
	virtual void setOrientation(Orientation) = 0;
	virtual void setRow(EvenOdd)=0;
	virtual void printRow(EvenOdd)=0;
	virtual EvenOdd getRow()=0;



};
#endif