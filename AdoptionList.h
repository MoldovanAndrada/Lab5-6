#pragma once
#include "Dog.h"
#include "DynamicVector.h"

class AdoptionList
{
private:
	DynamicVector<Dog> dogs;
	int current; 
public: 
	AdoptionList();
	
	void addToAdoptionList(const Dog &dog);
	Dog seeCurrent(); 
	void getNext();
	bool isEmpty();
	void start();
	Dog* getAllAdopted() const { return this->dogs.getDogs(); }
	DynamicVector<Dog> getDogs() const { return this->dogs; }
	
};