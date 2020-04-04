#pragma once
#include "Kontroller.h"

class Apotheke 
{
	Kontroller* kontroller;
	Button* button;

public:

	/* this is the controller of the class .*/
	Apotheke(Kontroller* kont, Button* button);

	/* getter */
	Kontroller* get_kontroller() { return this->kontroller; }
};