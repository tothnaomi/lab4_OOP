#include <iostream>
#include "Repository.h"
#include "Medikamente.h"
#include "Kontroller.h"
#include "UI.h"
#include "Button.h"

void print(std::vector<Medikament> v)
{
	for (auto el : v)
	{
		std::cout << el.get_name() << " " << el.get_konzentration() << " " << el.get_menge() << " " << el.get_preis() << std::endl;
	}
}

int main()
{
	
	Repository repo = Repository();
	Kontroller kontroller = Kontroller();
	Button button;
	button.set_kontroller(&kontroller);
	kontroller.set_repo(&repo, &button);
	Apotheke smile = Apotheke(&kontroller, &button);

	while (true)
	{
		std::cout << "What do you want to do? 1: add, 2: delete, 3: changing something, 4: string in name, 5:redo, 6:undo, 7:check medicaments that has less than x amounts, 8:check medicaments with y price" << std::endl;
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
			smile.get_kontroller()->add_Medikament(name, konzentration, menge, preis);
			/*for (auto el : (*kontroller.repo).medikamenten)
			{
				std::cout << el.get_name() << " " << el.get_konzentration() << " " << el.get_menge() << " " << el.get_preis() << std::endl;
			}*/
			print((*smile.get_kontroller()->get_repo()).medikamenten);
		}
		else if (option == 2)
		{
			std::cout << "Name:";
			std::string name;
			std::cin >> name;
			std::cout << "Concentration:";
			int konzentration;
			std::cin >> konzentration;
			smile.get_kontroller()->loschen_Medikament(name, konzentration);
			/*for (auto el : (*kontroller.repo).medikamenten)
			{
				std::cout << el.get_name() << " " << el.get_konzentration() << " " << el.get_menge() << " " << el.get_preis() << std::endl;
			}*/
			print((*smile.get_kontroller()->get_repo()).medikamenten);
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
				smile.get_kontroller()->bearbeiten_Medikament_name(name, konzentration, new_name);
				print((*smile.get_kontroller()->get_repo()).medikamenten);
			}
			else if (option2 == 2)
			{
				int konz;
				std::cout << "New concentration:";
				std::cin >> konz;
				smile.get_kontroller()->bearbeiten_Medikament_konzentration(name, konzentration, konz);
				print((*smile.get_kontroller()->get_repo()).medikamenten);
			}
			else if (option2 == 3)
			{
				int menge;
				std::cout << "New quantity:";
				std::cin >> menge;
				smile.get_kontroller()->bearbeiten_Medikament_menge(name, konzentration, menge);
				print((*smile.get_kontroller()->get_repo()).medikamenten);
			}
			else if (option2 == 4)
			{
				double new_price;
				std::cout << "New price:";
				std::cin >> new_price;
				smile.get_kontroller()->bearbeiten_Medikament_preis(name, konzentration, new_price);
				print((*smile.get_kontroller()->get_repo()).medikamenten);
			}
			else
				break;
		}
		else if (option == 4)
		{
			std::string str;
			std::cout << "String:";
			std::cin >> str;
			std::vector<Medikament> v = smile.get_kontroller()->get_repo()->Medikamente_die_eine_zeichenkette_enthalten(str);
			print(v);
		}
		else if (option == 7)
		{
			int x;
			
			std::cout << "What is the minimum amount of a medicament before it's considered scarce?";
			std::cin >> x;
			std::vector<Medikament> w = smile.get_kontroller()->get_repo()->Medikamente_die_knapp_sind(x);
			print(w);
			
		}
		else if (option == 8)
		{
			double y;
		
			std::cout << "What is the price of the medications you want to check?";
			std::cin >> y;
			std::vector<Medikament> u = smile.get_kontroller()->get_repo()->Medikamente_mit_gleiche_preis(y);
			print(u);

		}
		else if (option == 5)
		{
			button.redo();
			print((*smile.get_kontroller()->get_repo()).medikamenten);
		}
		else if (option == 6)
		{
			button.undo();
			print((*smile.get_kontroller()->get_repo()).medikamenten);
		}
			break;
		

	}
	return 0;
}