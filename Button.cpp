#include "Button.h"

Kontroller* Button::get_kontroller()
{
	return this->kontroller;
}

void Button::set(std::string str, std::string name, int konzentration, std::string new_name, int new_concentration, int new_menge, double new_price)
{
	this->last_function = str;
	this->name = name;
	this->konzentration = konzentration;
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
		this->kontroller->add_Medikament(this->name, this->konzentration, this->new_menge, this->new_price);
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
		this->kontroller->add_Medikament(this->name, this->konzentration, this->new_menge, this->new_price);
	}
	else if (this->last_function == "new name")
	{

	}
}