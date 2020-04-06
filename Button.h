#pragma once
#include <string>
#include "Kontroller.h"

class Button
{
	Kontroller* kontroller;

public:

	std::string last_function; // the name of the last command
	std::string name; // the name of the medication
	int konzentration; // concentration of the medication
	int menge; // quantity of the medication
	double price; // price of medication 
	std::string new_name;
	int new_menge;
	double new_price;
	int new_concentration;

	// setter
	void set_kontroller(Kontroller* kont);
	
	// getter
	Kontroller* get_kontroller();

	// setter for all the attributes (these are changing)
	void set(std::string, std::string, int,int ,double, std::string, int, int, double);

	/* a redo functionality, which calls again the last function. We need this functionality only for the add function */
	void redo();

	/* this is the undo functionality, which undos the last called command. E.g: if the last command was the add, the undo command will be delete
	for the added medication. We need this functiinality for the add, delete, change name, change price, change concentration and change
	quantity funtions */
	void undo();
};