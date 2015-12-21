/*
Romario Chuela, 6545973, Project Final, CSI2772 Automne 2015
*/

#include "AnimalCardFactory.h"

int AnimalCardFactory:: count = 0;

AnimalCardFactory* AnimalCardFactory::getFactory() {
	count++;
	//Pour empcher de creer plus d'une instance de Animal factory
	if (count > 1) {
		throw logic_error("Cannot create another instance");
	}
	else {
		return new AnimalCardFactory();
	}
}