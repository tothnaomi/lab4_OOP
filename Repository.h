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

	/* gives back true, if the medication with name name and concentration konzentration is in the list of objects and false otherwise/ */
	bool in_list(std::string name, int konzentration);

	/* returns all the medications which name contains the string given as parameter */
	std::vector<Medikament> Medikamente_die_eine_zeichenkette_enthalten(std::string zeichenkette);
};
