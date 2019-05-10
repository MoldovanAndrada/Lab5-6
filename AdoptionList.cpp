#include "AdoptionList.h"
AdoptionList::AdoptionList()
{
	this->current = 0;
}

void AdoptionList::addToAdoptionList(const Dog& dog)
{
	this->dogs.add(dog);
}

Dog AdoptionList::seeCurrent()
{
	if (this->current == this->dogs.getSize())
		this->current = 0;
	return this->dogs[this->current];
}
void AdoptionList::getNext()
{
	if (this->dogs.getSize() == 0)
		return;
	this->current++;
	Dog currentDog = this->seeCurrent();
}
bool AdoptionList::isEmpty()
{
	return this->dogs.getSize() == 0;
}


