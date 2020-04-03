#pragma once
#include <string>

class Button
{
	friend class Medikament;
	friend class Repository;
	friend class Kontroller;

public:
	std::string last_function;
	std::string name;
	int konzentration;
	std::string new_name;
	int new_menge;
	double new_price;
	int new_concentration;

	void set(std::string str, std::string name, int konzentration, std::string new_name, int new_concentration, int new_menge, double new_price)
	{
		this->last_function = str;
		this->new_name = new_name;
		this->new_concentration = new_concentration;
		this->new_menge = new_menge;
		this->new_price = new_price;

		this->name = name;
		this->konzentration = konzentration;
	}
};