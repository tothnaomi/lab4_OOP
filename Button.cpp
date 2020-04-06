#include "Button.h"

Kontroller* Button::get_kontroller()
{
	return this->kontroller;
}

void Button::set(std::string str, std::string name, int konzentration,int menge, double preis, std::string new_name, int new_concentration, int new_menge, double new_price)
{
	this->last_function = str;
	this->name = name;
	this->konzentration = konzentration;
	this->menge = menge;
	this->price = preis;
	this->new_name = new_name;
	this->new_concentration = new_concentration;
	this->new_menge = new_menge;
	this->new_price = new_price;
}

void Button::set_kontroller(Kontroller* kont)
{
	this->kontroller = kont;
}

void Button::redo()
{
	/* we need redo only for the add function*/
	if (this->last_function == "add")
	{
		this->kontroller->add_Medikament(this->name, this->konzentration, this->menge, this->price);
	}
}

void Button::undo()
{
	/* we need undo for add, delete, change name, change concentration, change quantity and change price */
	if (this->last_function == "add")
	{
		this->kontroller->loschen_Medikament(this->name, this->konzentration);
	}
	else if (this->last_function == "delete")
	{
		this->kontroller->add_Medikament(this->name, this->konzentration, this->menge, this->price);
	}
	else if (this->last_function == "new name")
	{
		this->kontroller->bearbeiten_Medikament_name(this->new_name, this->konzentration, this->name);
	}
	else if (this->last_function == "new concentration")
	{
		this->kontroller->bearbeiten_Medikament_konzentration(this->name, this->new_concentration, this->konzentration);
	}
	else if (this->last_function == "new menge")
	{
		this->kontroller->bearbeiten_Medikament_menge(this->name, this->konzentration, this->menge);
	}
	
	else if (this->last_function == "new price")
	{
		this->kontroller->bearbeiten_Medikament_preis(this->name, this->new_price, this->price);
	}
}