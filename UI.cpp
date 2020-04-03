#include "UI.h"
#include <iostream>

Apotheke::Apotheke(Kontroller* kont)
{
	this->kontroller = kont;
}

void Apotheke::redo_button()
{
	
	if (this->get_kontroller()->button->last_function == "add")
	{
		this->kontroller->add_Medikament(this->get_kontroller()->button->name, this->get_kontroller()->button->konzentration, this->get_kontroller()->button->new_menge, this->get_kontroller()->button->new_price);
	}
	if (this->get_kontroller()->button->last_function == "delete")
	{
		this->kontroller->loschen_Medikament(this->get_kontroller()->button->name, this->get_kontroller()->button->konzentration);
	}
}