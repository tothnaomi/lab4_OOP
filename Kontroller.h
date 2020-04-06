#pragma once
#include "Repository.h"
#include "Button.h"

class Kontroller
{
	friend class Apotheke;
	friend class Button;
	Repository* repo;
	Button* button;

public:
	
	/* setter */
	void set_repo(Repository* repo, Button* b);

	/* the function adds to the list of objects the medication with name name, concentration konzentration, quantity menge and price prise. 
	These values are given as parameters to the function */
	void add_Medikament(std::string name, int konzentartion, int menge, double preis);

	/* the function deletes from the list of objects the medication with name name and concentration konzentration 
	These values are given as parameters to the function */
	void loschen_Medikament(std::string name, int konzentration);

	/* this function changes the name of a given medication, which is identified by the name and the concentration */
	void bearbeiten_Medikament_name(std::string name, int konzentration, std::string new_name);

	/* this function changes the concentration of a given medication, which is identified by the name and the concentration */
	void bearbeiten_Medikament_konzentration(std::string name, int konzentration, int neue_konzentration);

	/* this function changes the quantity of a given medication, which is identified by the name and the concentration */
	void bearbeiten_Medikament_menge(std::string name, int konzentration, int new_menge);

	/* this function changes the price of a given medication, which is identified by the name and the concentration */
	void bearbeiten_Medikament_preis(std::string name, int konzentration, double neues_preis);

	/* getter of the class */
	Repository* get_repo() { return this->repo; }
};