/*
Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
*/

#ifndef Hand_INCLUDED__   
#define hand_INCLUDED__

#pragma once
#include <utility>
#include <iostream>
#include <vector>
#include "Player.h"

 class QueryResult {

	
	public:
		

	//ID de la carte a ramasser sur la table et la garder;
	std::pair<int, int> indexCarte;
	//Determine si le joueur veux proceder a l'action ou non
	bool action = false;
	int IndexEchangeCarteSecret;


	//determine si le joueur veux faire tourner les mains 
	bool rotate = false;

	//Ces deux paire sont utiliser par le HareAction, elle prend une paire de coordonner pour mettre dans une 
	//autre place
	std::pair<int, int> locationInitial;
	std::pair<int, int> locationAplacer;
	int k, l; 
	//HareAction hare;

	//prend l'animal secret d'un des joueur
	int indexMain;






};
#endif