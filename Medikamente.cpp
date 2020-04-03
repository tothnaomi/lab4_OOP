#include "Medikamente.h"
#include <string>

Medikament::Medikament(std::string name, int konzentration, int menge, double preis)
{
	this->name = name;
	this->konzentration = konzentration;
	this->menge = menge;
	this->preis = preis;
}

bool Medikament::operator< (const Medikament& other)
{
	return this->name < other.name;
}

bool Medikament::zeichenkette_in_name(std::string zeichenkette)
{
	char* str = &zeichenkette[0];
	char* name_ptr = &(this->name[0]);
	while (*name_ptr != '\0')
	{
		if (*name_ptr == *str)
			break;
		else
			name_ptr++;
	}
	name_ptr++; str++;
	while (*str != '\0' || *name_ptr != '\0')
	{
		if (*name_ptr != *str) return false;
		else
		{
			name_ptr++; str++;
		}
	}
	return true;
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