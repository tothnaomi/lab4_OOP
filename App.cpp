#include <iostream>
#include "Repository.h"
#include "Medikamente.h"
#include "Kontroller.h"
#include "UI.h"

int main()
{
	Repository repo = Repository();
	Kontroller kontroller = Kontroller();
	kontroller.set_repo(&repo);

	while (true)
	{
		std::cout << "What do you want to do? 1: add, 2: delete, 3: changing something, 4:" << std::endl;
		int option;
		std::cin >> option;
		if (option == 1)
		{
			std::cout << "Name:";
			std::string name;
			std::cin >> name;
			std::cout << "Concentration:";
			int konzentration;
			std::cin >> konzentration;
			std::cout << "Quantity:";
			int menge;
			std::cin >> menge;
			std::cout << "Price:";
			double preis;
			std::cin >> preis;
			kontroller.add_Medikament(name, konzentration, menge, preis);
			/*for (auto el : (*kontroller.repo).medikamenten)
			{
				std::cout << el.get_name() << " " << el.get_konzentration() << " " << el.get_menge() << " " << el.get_preis() << std::endl;
			}*/
		}
		else if (option == 2)
		{
			std::cout << "Name:";
			std::string name;
			std::cin >> name;
			std::cout << "Concentration:";
			int konzentration;
			std::cin >> konzentration;
			kontroller.loschen_Medikament(name, konzentration);
			/*for (auto el : (*kontroller.repo).medikamenten)
			{
				std::cout << el.get_name() << " " << el.get_konzentration() << " " << el.get_menge() << " " << el.get_preis() << std::endl;
			}*/
		}
		else if (option == 3)
		{
			int option2;
			std::cout << "Where do you want to change? ";
			std::string name;
			int konzentration;
			std::cout << "Name of medication:";
			std::cin >> name;
			std::cout << "Concentration of medication:";
			std::cin >> konzentration;
			std::cout << "What do you want to change? 1:name, 2:concentration, 3: quantity, 4:price ";
			std::cin >> option2;
			if (option2 == 1)
			{
				std::string new_name;
				std::cout << "New name:";
				std::cin >> new_name;
				kontroller.bearbeiten_Medikament_name(name, konzentration, new_name);
				for (auto el : (*kontroller.repo).medikamenten)
				{
					std::cout << el.get_name() << " " << el.get_konzentration() << " " << el.get_menge() << " " << el.get_preis() << std::endl;
				}
			}
			else if (option2 == 2)
			{
				int konz;
				std::cout << "New concentration:";
				std::cin >> konz;
				kontroller.bearbeiten_Medikament_konzentration(name, konzentration, konz);
				for (auto el : (*kontroller.repo).medikamenten)
				{
					std::cout << el.get_name() << " " << el.get_konzentration() << " " << el.get_menge() << " " << el.get_preis() << std::endl;
				}
			}
			else if (option2 == 3)
			{
				int menge;
				std::cout << "New quantity:";
				std::cin >> menge;
				kontroller.bearbeiten_Medikament_menge(name, konzentration, menge);
				for (auto el : (*kontroller.repo).medikamenten)
				{
					std::cout << el.get_name() << " " << el.get_konzentration() << " " << el.get_menge() << " " << el.get_preis() << std::endl;
				}
			}
			else if (option2 == 4)
			{
				double new_price;
				std::cout << "New price:";
				std::cin >> new_price;
				kontroller.bearbeiten_Medikament_preis(name, konzentration, new_price);
				for (auto el : (*kontroller.repo).medikamenten)
				{
					std::cout << el.get_name() << " " << el.get_konzentration() << " " << el.get_menge() << " " << el.get_preis() << std::endl;
				}
			}
			else
				break;
		}
		else
			break;

	}
	
	return 0;
}