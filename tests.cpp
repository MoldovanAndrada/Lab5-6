#include "tests.h"
#include "Repository.h"
#include "Controller.h"
#include <assert.h>

void test_domain() {
	Dog d{ "Ogar","Bella",2,"https://www.click.ro/sites/default/files/styles/articol/public/medias/2015/04/05/bichon_maltese.jpg?itok=4WdSkPJX" };
	Dog d1{ "Ogar","Max",2,"https://www.click.ro/sites/default/files/styles/articol/public/medias/2015/04/05/bichon_maltese.jpg?itok=4WdSkPJX" };
	assert(d1 == d);
	assert(d.getBreed() == "Ogar");
	assert(d.getName() == "Bella");
	assert(d.getAge() == 2);
	assert(d.getPhotograph() == "https://www.click.ro/sites/default/files/styles/articol/public/medias/2015/04/05/bichon_maltese.jpg?itok=4WdSkPJX");

	d.setBreed("Ciobanesc");
	d.setName("Cora");
	d.setAge(6);
	d.setPhotograph("https://www.click.ro");
	assert(d.getBreed() == "Ciobanesc");
	assert(d.getName() == "Cora");
	assert(d.getPhotograph() == "https://www.click.ro");
}
void test_repo() {
	Repository repo;
	Controller ctrl = Controller(repo);

	assert(ctrl.getSize() == 0);
	Dog d{ "Ogar","Max",2,"https://www.click.ro/sites/default/files/styles/articol/public/medias/2015/04/05/bichon_maltese.jpg?itok=4WdSkPJX" };
	ctrl.addToRepo(d);
	assert(ctrl.getSize() == 1);
	Dog d2{ "Dalmatian","Alma",1,"https://suntfericita.manager.ro/dbimg/images/LKBCD00Z.jpg" };
	assert(ctrl.getSize() == 2);
	ctrl.remove("Ogar", "Max");
	assert(ctrl.getSize() == 1);
	ctrl.update("Dalmatian", "Alma", "Ciobanesc", "Cora", 5, "https://www.youtube.com/watch?v=p1muCWIktbY");

}