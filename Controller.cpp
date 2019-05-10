#include "Controller.h"

void Controller::addToRepo(const Dog& dog) {
	repo.add(dog);
}

void Controller::remove(string breed, string name) {
	repo.remove(breed, name);
}

void Controller::update(string breed, string name, string newBreed, string newName, int newAge, string newPhotograph)
{
	repo.update(breed, name, newBreed, newName, newAge, newPhotograph);
}

void Controller::addToAdoptionList(const Dog &dog)
{
	dogs.addToAdoptionList(dog);
	repo.remove(dog.getBreed(),dog.getName());
}
void Controller::start()
{
	Dog d;
	d=dogs.seeCurrent();
	cout << d.getBreed() << " - " << d.getName() << "; " << d.getAge() << ":" << d.getPhotograph() << endl;
}
void Controller::next()
{
	dogs.getNext();
}