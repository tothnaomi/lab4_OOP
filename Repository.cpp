#include "Repository.h"
#include <exception>

/* NOTE TO MYSELF: CRUD -> create, read, update, delete */

/* here are all the functions which are returning an object from the repository, but they do not change the list with the medications */

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
bool Repository::in_liste(std::string name, int konzentration, int menge, double preis)
{
	bool in_listen = false;
	for (auto med : this->medikamenten)
	{
		if (med.name == name && med.konzentration == konzentration && med.menge == menge && med.preis == preis)
		{
			in_listen = true;
			break;
		}
	}
	return in_listen;
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

std::vector<Medikament> Repository::Medikamente_die_knapp_sind(int x)
{

	std::vector<Medikament> medikamente_mit_menge_kleiner_als_x;
	for (int i = 0; i < this->medikamenten.size(); i++)
		if (this->medikamenten[i].get_menge() <= x)
		{
			medikamente_mit_menge_kleiner_als_x.push_back(this->medikamenten[i]);

		}
	return medikamente_mit_menge_kleiner_als_x;
}

std::vector<Medikament> Repository::Medikamente_mit_gleiche_preis(double y)
{
	std::vector<Medikament> medikamente_mit_gleiche_preis;
	for(int i= 0; i <this->medikamenten.size(); i++)
		if (this->medikamenten[i].get_preis() == y)
		{
			medikamente_mit_gleiche_preis.push_back(this->medikamenten[i]);
		}
	return medikamente_mit_gleiche_preis;

}