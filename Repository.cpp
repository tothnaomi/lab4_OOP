#include "Repository.h"
#include <exception>

bool Repository::in_list(std::string name, int konzentration)
{
	bool in_liste = false;
	for (auto med: this->medikamenten)
	{
		if (med.name == name && med.konzentration == konzentration)
		{
			in_liste = true;
			break;
		}
	}
	return in_liste;
}

