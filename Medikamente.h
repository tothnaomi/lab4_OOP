#pragma once
#include <string>

class Medikament
{
	std::string name;
	int konzentration;
	int menge;
	double preis;
public:
	/* constructor for the class */
	Medikament(std::string name, int konzentration, int menge, double preis);

	bool is_knapp_oder_nicht(int menge);

	/* getters */
	std::string get_name();

	int get_konzentration();

	int get_menge();

	double get_preis();

	/* setter */

	void set_preis(double neues_preis);

	void set_menge(int menge);

	void set_konzentration(int konzentration);

	void set_name(std::string name);

};