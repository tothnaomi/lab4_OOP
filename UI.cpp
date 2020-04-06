#include "UI.h"
#include <iostream>

/* this class uses the repository and the kontroller as well to "create" a drugstore */

Apotheke::Apotheke(Kontroller* kont, Button* button)
{
	this->kontroller = kont;
	this->button = button;
}