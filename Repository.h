#pragma once
#include <vector>
#include <string>
#include "Medikamente.h""

/* this is a repository for the medications */

class Repository
{
	friend class Kontroller;

public:
	std::vector <Medikament> medikamenten;

	bool in_list(std::string name, int konzentration);

};
