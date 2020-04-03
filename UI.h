#pragma once
#include "Kontroller.h"

class Apotheke 
{
	Kontroller kontroller;

public:

	Apotheke(Kontroller kont);

	void set_kontroller(Kontroller kont) { this->kontroller = kont; }
};