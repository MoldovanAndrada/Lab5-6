#pragma once
#include "Repository.h"
#include "AdoptionList.h"
#include <iostream>
using namespace std;

class Controller
{
private:
	Repository repo;
	AdoptionList dogs; 

public:
	Controller(const Repository& repo) : repo(repo) {}
	/*Function that adds a dog element to the repository
	in:dog-an instance of Dog class
	out:
	*/

	Repository getRepo()const { return this->repo; }
	AdoptionList getAdoptionList() const { return this->dogs; }


	void addToRepo(const Dog& dog);
	void addToAdoptionList(const Dog& dog);

	/*Function that returns the vector of elements
	*/
	Dog* getAll()const { return this->repo.getAll(); }
	Dog* getAllAdopted() { return this->dogs.getAllAdopted(); }

	void remove(string breed, string name);
	void update(string breed, string name, string newBreed, string newName, int newAge, string newPhotograph);
	/*Function that returns the number of dog objects in repository
	*/

	
	int getSize() const { return this->repo.getSize(); };


	void next() { this->dogs.getNext(); }

	bool isEmpty() { return this->dogs.isEmpty(); }
	void start();
	void next();

};