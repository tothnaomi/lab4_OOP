#pragma once
#include "Kontroller.h"

class Apotheke 
{
	Kontroller* kontroller;
	Button* button;

public:

	Apotheke(Kontroller* kont, Button* button);

	Kontroller* get_kontroller() { return this->kontroller; }
};