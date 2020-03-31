#include "Medikamente.h"
#include <string>

Medikation::Medikation(std::string name, int konzentration, int menge, double preis)
{
	this->name = name;
	this->konzentration = konzentration;
	this->menge = menge;
	this->preis = preis;
}

std::string Medikation::get_name()
{
	return this->name;
}

int Medikation::get_konzentration()
{
	return this->konzentration;
}

int Medikation::get_menge()
{
	return this->menge;
}

double Medikation::get_preis()
{
	return this->preis;
}

void Medikation::set_preis(double neues_preis)
{
	this->preis = neues_preis;
}