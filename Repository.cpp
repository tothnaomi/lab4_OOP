#include "Repository.h"
#include <exception>

/* here are all the functions which are returning an object from the repotory, but they do not change the list with the medications */

bool Repository::in_list(std::string name, int konzentration)
{
	bool in_liste = false;
	for (auto med: this->medikamenten)
	{
		if (med.name == name && med.konzentration == konzentration)
		{
			in_liste = true;
			break;
		}
	}
	return in_liste;
}

std::vector<Medikament> Repository::Medikamente_die_eine_zeichenkette_enthalten(std::string zeichenkette)
{
	std::vector<Medikament> medikamente_mit_zeichenkette_in_name;
	for (int i = 0; i < this->medikamenten.size(); i++)
	{
		if (this->medikamenten[i].zeichenkette_in_name(zeichenkette))
		{
			medikamente_mit_zeichenkette_in_name.push_back(this->medikamenten[i]);
		}
	}
	return medikamente_mit_zeichenkette_in_name;
}