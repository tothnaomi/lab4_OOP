#pragma once
#include <string>

class Medikament
{
	friend class Repository;
	std::string name;
	int konzentration;
	int menge;
	double preis;
public:
	/* constructor for the class */
	Medikament(std::string name, int konzentration, int menge, double preis);

	bool operator< (const Medikament& other);

	bool zeichenkette_in_name(std::string zeichenkette);

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