#pragma once
#include "Kontroller.h"

class Apotheke 
{
	Kontroller* kontroller;

public:

	Apotheke(Kontroller* kont);

	Kontroller* get_kontroller() { return this->kontroller; }

	void redo_button();
};