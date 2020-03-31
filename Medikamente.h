#pragma once
#include <string>

class Medikation
{
	std::string name;
	int konzentration;
	int menge;
	double preis;
public:
	/* constructor for the class */
	Medikation(std::string name, int konzentration, int menge, double preis);

	/* getters */
	std::string get_name();

	int get_konzentration();

	int get_menge();

	double get_preis();

	/* setter */

	void set_preis(double neues_preis);
};