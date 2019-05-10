#include "UI.h"
#include <string>

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1. Administrator mode." << endl;
	cout << "2. User mode." << endl;
	cout << "0. Exit" << endl;
}

void UI::printRepositoryMenu()
{
	cout << endl;
	cout << "1. Add dog" << endl;
	cout << "2. Print all" << endl;
	cout << "3. Delete" << endl;
	cout << "4. Update" << endl;
	cout << "0. Exit" << endl;
}
void UI::printUserMenu()
{
	cout << endl; 
	cout << "1. See the dogs one by one." << endl;
	cout << "2. Adopt the current dog." << endl;
	cout << "3. Next dog." << endl;
	cout << "4. See the adoption list." << endl;
	cout << "0. Exit." << endl;

}

void UI::addToRepo()
{
	cout << "Breed: ";
	string breed;
	getline(cin, breed);
	cout << "Name: ";
	string name;
	getline(cin, name);
	cout << "Age: ";
	int age;
	cin >> age;
	cout << "Photo link: ";
	string photograph;
	getline(cin, photograph);
	getline(cin, photograph);
	Dog d = Dog(breed, name, age, photograph);
	ctrl.addToRepo(d);
}
void UI::getAll()
{

	Dog* dogs = ctrl.getAll();

	if (dogs == NULL)
		return;

	if (this->getSize() == 0) {
		cout << "No dog is registred." << endl;
		return;
	}

	for (int i = 0; i < this->getSize(); i++)
	{
		Dog d = dogs[i];
		cout << d.getBreed() << " " << d.getName() << " " << d.getAge() << " " << d.getPhotograph() << endl;
	}
}
void UI::remove() {
	cout << "Breed: ";
	string breed;
	getline(cin, breed);
	cout << "Name: ";
	string name;
	getline(cin, name);
	int x = this->ctrl.getSize();
	ctrl.remove(breed, name);
	int y = this->ctrl.getSize();
	if (x == y)
		cout << "The dog is not registred\n";
}
void UI::update() {
	cout << "Breed: ";
	string breed;
	getline(cin, breed);
	cout << "Name: ";
	string name;
	getline(cin, name);
	cout << "Breed: ";
	string newBreed;
	getline(cin, newBreed);
	cout << "Name: ";
	string newName;
	getline(cin, newName);
	cout << "Age: ";
	int newAge;
	cin >> newAge;
	cout << "Photo link: ";
	string newPhotograph;
	getline(cin, newPhotograph);
	ctrl.update(breed, name, newBreed, newName, newAge, newPhotograph);
}
void UI::addToAdoptionList() {
	cout << "Breed: ";
	string breed;
	getline(cin, breed);
	cout << "Name: ";
	string name;
	getline(cin, name);
	cout << "Age: ";
	int age;
	cin >> age;
	cout << "Photo link: ";
	string photograph;
	getline(cin, photograph);
	getline(cin, photograph);
	Dog d=Dog(breed, name, age, photograph);
	ctrl.addToAdoptionList(d);
}
void UI::seeOneByOne(){
	if (this->getSize() == 0) 
		cout << "No dogs registred";
	ctrl.start();
}
void UI::next() {
	ctrl.next();
}
void UI::seeAllAdopted() {
	DynamicVector<Dog> v = this->ctrl.getAdoptionList().getDogs();
	Dog* adoptedDogs = ctrl.getAllAdopted();
	if (adoptedDogs == NULL)
		return; 
	if (v.getSize() == 0) {
		cout << "There are no dogs to display." << endl;
		return;
	}

	for (int i = 0; i < v.getSize(); i++)
	{
		Dog d = adoptedDogs[i];
		cout << d.getBreed() << " - " << d.getName() << "; " << d.getAge() << ":" << d.getPhotograph() << endl;
	}

}
void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Select an option: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// repository management
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Select an option: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1: {
					this->addToRepo();
					break;
				}
				case 2: {
					this->getAll();
					break;
				}
				case 3: {
					this->remove();
					break;
				}
				case 4: {
					this->update();
					break;
				}
				}
			}
		}
		//user management
		if (command == 2)
		{
			while (true)
			{
			UI:printUserMenu();
				int commandUser{ 0 };
				cout << "Select an option"; 
				cin >> commandUser; 
				cin.ignore(); 
				if (commandUser == 0)
					break;
				switch (commandUser)
				{
				case 1: {
					this->seeOneByOne();
					break;
				}
				case 2: {
					this->addToAdoptionList();
					break;
				}
				case 3: {
					this->next();
					break;
				}
				case 4: {
					this->seeAllAdopted();
					break;
				}
			}

			}
		}
	}
}