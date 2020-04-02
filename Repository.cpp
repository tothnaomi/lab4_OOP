#include "Repository.h"

bool Repository::in_list(std::string name, int konzentration)
{
	bool in_liste = false;
	for (auto medikamente : this->apotheke)
	{
		if (medikamente.name == name && medikamente.konzentration == konzentration)
		{
			in_liste = true;
			break;
		}
	}
	return in_liste;
}