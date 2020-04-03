#include "Kontroller.h"
#include <iostream>

void Kontroller::set_repo(Repository* repo)
{
	this->repo = repo;
}

void Kontroller::add_Medikament(std::string name, int konzentration, int menge, double preis)
{
	//this->repo.add_Medikament(name, konzentration, menge, preis);
	// if it is already in repo -> we have to update the quantity of it
	if ((*this->repo).in_list(name, konzentration) == 1)
	{
		// we have to find the medication 
		for (int i = 0; i < (*this->repo).medikamenten.size(); i++)
		{
			if ((*this->repo).medikamenten[i].get_name() == name && (*this->repo).medikamenten[i].get_konzentration() == konzentration)
			{
				int new_menge = menge + (*this->repo).medikamenten[i].get_menge();
				(*this->repo).medikamenten[i].set_menge(new_menge);
				break;
			}
		}
	}

	else
	{
		Medikament new_med = Medikament(name, konzentration, menge, preis);
		(*this->repo).medikamenten.push_back(new_med);
	}
}

void Kontroller::loschen_Medikament(std::string name, int konzentration)
{
	if ((*this->repo).in_list(name, konzentration))
	{
		// delete the medication
		for (int i = 0; i < (*this->repo).medikamenten.size(); i++)
		{
			if ((*this->repo).medikamenten[i].get_name() == name && (*this->repo).medikamenten[i].get_konzentration() == konzentration)
			{
				(*this->repo).medikamenten.erase((*this->repo).medikamenten.begin() + i);
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