#include "Medikamente.h"
#include <string>

Medikament::Medikament(std::string name, int konzentration, int menge, double preis)
{
	this->name = name;
	this->konzentration = konzentration;
	this->menge = menge;
	this->preis = preis;
}

std::string Medikament::get_name()
{
	return this->name;
}

int Medikament::get_konzentration()
{
	return this->konzentration;
}

int Medikament::get_menge()
{
	return this->menge;
}

double Medikament::get_preis()
{
	return this->preis;
}

void Medikament::set_preis(double neues_preis)
{
	this->preis = neues_preis;
}

void Medikament::set_konzentration(int konzentration)
{
	this->konzentration = konzentration;
}

void Medikament::set_menge(int menge)
{
	this->menge = menge;
}

void Medikament::set_name(std::string name)
{
	this->name = name;
}