#include <iostream>
#include "Repository.h"
#include "Medikamente.h"
#include "Kontroller.h"
#include "UI.h"

int main()
{
	Medikament aspirin = Medikament("Aspirin", 20, 50, 22.5);
	Medikament nurofen = Medikament("Nurofen", 10, 70, 18.75);
	Medikament gripovit = Medikament("Gripovit", 15, 2, 19.5);

	Repository repo = Repository();
	Kontroller kontroller = Kontroller();
	kontroller.set_repo(&repo);

	kontroller.add_Medikament("Aspirin", 20, 50, 22.5);

	kontroller.add_Medikament("Aspirin", 20, 50, 22.5);

	kontroller.add_Medikament("Nurofen", 10, 70, 18.75);
	

	kontroller.loschen_Medikament("Nurofen", 10);
	for (auto el : (*kontroller.repo).medikamenten)
	{
		std::cout << el.get_name() << " " << el.get_menge() << std::endl;
	}
	

	return 0;
}