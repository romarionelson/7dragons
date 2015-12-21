/*
Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
*/

#ifndef Hand_INCLUDED__  
#define hand_INCLUDED__

#pragma once
#include "AnimalCard.h"
#include <tuple>
#include <string>
#include <iostream>


//#include <functional>

using namespace std;

class NoSplit : public AnimalCard {
	//there are 5 animals 
	//bear, deer, hare, moose, wolf
	//std::tuple<string> tuple;
	Orientation orientation;
	EvenOdd evenOdd;
	std::string first;
	
public:
	
	std::tuple<string, string, string, string> tuple;
	
	NoSplit(string first) :first(first)
		 {
		//std::cout << "Appel au constructeur \n";
		tuple = std::make_tuple(first, first, first, first);

	}

	std::tuple<string, string, string, string> getTuple() {
		return tuple;

	}

	
	 EvenOdd getRow() {

		return evenOdd;
	}
	//Change l'orientation de la carte 
	 void setOrientation(Orientation o) {
		this->orientation = o;

	}
	//utiliser par printrow lors de l'affichage de la carte
	 void setRow(EvenOdd e_o) {

		this->evenOdd = e_o;
	}
	//affiche les 2 charactere correspondant a la carte 
	//dans ce cas peut importe l'orientation de la carte les meme 
	//charactere seront impprimer
	void printRow(EvenOdd _e) {
		
		if (EvenOdd::EVEN == _e) {
			if (Orientation::UP == orientation) {
				std::cout << std::get<0>(tuple) << std::get<1>(tuple)<< "  ";
			}
			else {

				std::cout << std::get<2>(tuple) << std::get<3>(tuple)<< "  ";
			}

		}
		else {
			if (Orientation::UP == orientation) {
				std::cout << std::get<2>(tuple) << std::get<3>(tuple)<< "  ";
			}
			else {

				std::cout << std::get<0>(tuple) << std::get<1>(tuple)<< "  ";


			}


		}
	}


};
class Split2 : public AnimalCard {
	
	Orientation orientation;
	EvenOdd evenOdd;
	std::string first, second;
	bool flag=false;
public:
	std::tuple<string, string, string, string> tuple;
	Split2(std::string _first, std::string _second, bool flag) : first(_first), second(_second), flag(flag) {


		if (flag) {
			//std::cout << "Appel au constructeur \n";
			tuple = std::make_tuple(_first, _second, _first, _second);

		}
		else {

			tuple = std::make_tuple(_first, _first, _second, _second);

		}

		


	}
	//Change l'orientation de la carte 
	 void setOrientation(Orientation o) {
		this->orientation = o;

	}
	 EvenOdd getRow() {

		 return evenOdd;
	 }
	//utiliser par printrow lors de l'affichage de la carte
	 void setRow(EvenOdd e_o) {

		this->evenOdd = e_o;
	}
	//affiche les 2 charactere correspondant a la carte 
	 //prints two characters for the specified row
	 void printRow(EvenOdd _e) {
		 setRow(_e);

		 // std::cout << std::get<2>(tuple) << std::get<3>(tuple) << endl;
		 // std::cout << std::get<0>(tuple) << std::get<1>(tuple) << endl;

		 if (Orientation::UP == orientation && EvenOdd::EVEN == _e) {
			 std::cout << std::get<0>(tuple) << std::get<1>(tuple) <<"  ";
		 }
		 else if (Orientation::UP == orientation && EvenOdd::ODD == _e) {
			 std::cout << std::get<2>(tuple) << std::get<3>(tuple) << "  ";
		 }
		 else if (Orientation::DOWN == orientation && EvenOdd::EVEN == _e) {
			 std::cout << std::get<2>(tuple) << std::get<3>(tuple) << "  ";

		 }
		 else {
			 std::cout << std::get<0>(tuple) << std::get<1>(tuple) << "  ";
		 }



	 }

	 std::tuple<string, string, string, string> getTuple() {
		 return tuple;

	 }

};
class Split3 : public AnimalCard {


	Orientation orientation;
	EvenOdd evenOdd;
	string first, second, third; 
public:
	//la tuple  va contenir les differents animaux
	std::tuple<string, string, string, string> tuple;
	bool flag; 
	Split3(string first, string second, string third, bool flag) :
		first(first), second(second), third(third), flag(flag) {
		if (flag) {

			tuple = std::make_tuple(first, second, first, third);

		}
		else {
			tuple = std::make_tuple(first, first, second, third);

		}
		

	}
	//Change l'orientation de la carte 
	 void setOrientation(Orientation o) {
		this->orientation = o;

	}
	//utiliser par printrow lors de l'affichage de la carte
	 void setRow(EvenOdd e_o) {

		this->evenOdd = e_o;
	}
	//affiche les 2 charactere correspondant a la carte 
	 void printRow(EvenOdd _e) {
			 setRow(_e);

			 // std::cout << std::get<2>(tuple) << std::get<3>(tuple) << endl;
			 // std::cout << std::get<0>(tuple) << std::get<1>(tuple) << endl;

			 if (Orientation::UP == orientation && EvenOdd::EVEN == _e) {
				 std::cout << std::get<0>(tuple) << std::get<1>(tuple) << "  ";
			 }
			 else if (Orientation::UP == orientation && EvenOdd::ODD == _e) {
				 std::cout << std::get<2>(tuple) << std::get<3>(tuple) << "  ";
			 }
			 else if (Orientation::DOWN == orientation && EvenOdd::EVEN == _e) {
				 std::cout << std::get<2>(tuple) << std::get<3>(tuple) << "  ";

			 }
			 else {
				 std::cout << std::get<0>(tuple) << std::get<1>(tuple) << "   ";
			 }



		 }

	 

	EvenOdd getRow() {

		return evenOdd;
	}

	std::tuple<string, string, string, string> getTuple() {
		return tuple;

	}

};

class Split4 : public AnimalCard {
	
	Orientation orientation;
	string first, second, third, fourth;
	EvenOdd evenOdd;
public:
	std::tuple<string, string, string, string> tuple;
	Split4(string first, string second, string third, string fourth) :
		first(first), second(second), third(third), fourth(fourth){

		tuple = std::make_tuple(first, second, third, fourth);

	}
	//Change l'orientation de la carte 
	 void setOrientation(Orientation o) {
		this->orientation = o;

	}
	//utiliser par printrow lors de l'affichage de la carte
	 void setRow(EvenOdd e_o) {

		this->evenOdd = e_o;
	}
	//affiche les 2 charactere correspondant a la carte 
	 void printRow(EvenOdd _e) {
		 setRow(_e);

		 // std::cout << std::get<2>(tuple) << std::get<3>(tuple) << endl;
		 // std::cout << std::get<0>(tuple) << std::get<1>(tuple) << endl;

		 if (Orientation::UP == orientation && EvenOdd::EVEN == _e) {
			 std::cout << std::get<0>(tuple) << std::get<1>(tuple) << "  ";
		 }
		 else if (Orientation::UP == orientation && EvenOdd::ODD == _e) {
			 std::cout << std::get<2>(tuple) << std::get<3>(tuple) << "  ";
		 }
		 else if (Orientation::DOWN == orientation && EvenOdd::EVEN == _e) {
			 std::cout << std::get<2>(tuple) << std::get<3>(tuple) << "  ";

		 }
		 else {
			 std::cout << std::get<0>(tuple) << std::get<1>(tuple) << "  ";
		 }



	 }
	 EvenOdd getRow() {

		 return evenOdd;
	 }

	 std::tuple<string, string, string, string> getTuple() {
		 return tuple;

	 }
};
#endif