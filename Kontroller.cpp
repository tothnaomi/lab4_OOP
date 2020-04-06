#include "Kontroller.h"
#include <iostream>

/* here are all the functions which are changign something in the list of medications (in our case this is the repository) */

void Kontroller::set_repo(Repository* repo, Button* b)
{
	this->repo = repo;
	this->button = b;
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
	this->button->set("add", name, konzentration, menge, preis, "" , -1, menge, preis);
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
				this->button->set("delete", name, konzentration, (*this->repo).medikamenten[i].get_menge(), (*this->repo).medikamenten[i].get_preis(),  "", -1,-1, -1);
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


void Kontroller::bearbeiten_Medikament_name(std::string name, int konzentration, std::string new_name)
{
	if ((*this->repo).in_list(name, konzentration))
	{
		for (int i=0;i<(*this->repo).medikamenten.size();i++)
		{
			if ((*this->repo).medikamenten[i].get_name()==name && (*this->repo).medikamenten[i].get_konzentration()==konzentration)
			{
				(*this->repo).medikamenten[i].set_name(new_name);
				this->button->set("new name", name, konzentration, -1, -1,new_name, -1, -1, -1);
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

void Kontroller::bearbeiten_Medikament_konzentration(std::string name, int konzentration, int neue_konzentration)
{
	if ((*this->repo).in_list(name, konzentration))
	{
		for (int i = 0; i < (*this->repo).medikamenten.size(); i++)
		{
			if ((*this->repo).medikamenten[i].get_name() == name && (*this->repo).medikamenten[i].get_konzentration() == konzentration)
			{
				(*this->repo).medikamenten[i].set_konzentration(neue_konzentration);
				this->button->set("new concentration", name, konzentration,-1, -1,  "", neue_konzentration, -1, -1);
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

void Kontroller::bearbeiten_Medikament_menge(std::string name, int konzentration, int new_menge)
{
	if ((*this->repo).in_list(name, konzentration))
	{
		for (int i = 0; i < (*this->repo).medikamenten.size(); i++)
		{
			if ((*this->repo).medikamenten[i].get_name() == name && (*this->repo).medikamenten[i].get_konzentration() == konzentration)
			{
				this->button->set("new menge", name, konzentration, (*this->repo).medikamenten[i].get_menge(), -1, "", -1, new_menge, -1);
				(*this->repo).medikamenten[i].set_menge(new_menge);
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


void Kontroller::bearbeiten_Medikament_preis(std::string name, int konzentration, double neues_preis)
{
	if ((*this->repo).in_list(name, konzentration))
	{
		for (int i = 0; i < (*this->repo).medikamenten.size(); i++)
		{
			if ((*this->repo).medikamenten[i].get_name() == name && (*this->repo).medikamenten[i].get_konzentration() == konzentration)
			{
				this->button->set("new price", name, konzentration,-1, (*this->repo).medikamenten[i].get_preis(), "", -1, -1, neues_preis);
				(*this->repo).medikamenten[i].set_preis(neues_preis);
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