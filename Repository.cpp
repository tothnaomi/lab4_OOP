#include "Repository.h"
#include <exception>

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


void Repository::loschen_Medikament(std::string name, int konzentration)
{
	if (in_list(name, konzentration))
	{
		// delete the medication
		for (int i = 0; i < this->medikamenten.size(); i++)
		{
			if (this->medikamenten[i].name == name && this->medikamenten[i].konzentration == konzentration)
			{
				this->medikamenten.erase(this->medikamenten.begin()+i);
				break;
			}
		}
	}
	else
	{
		std::exception the_medication_is_not_in_the_repository;
		throw the_medication_is_not_in_the_repository;
	}
}