#pragma once
#include <vector>
#include <string>
#include "Medikamente.h""

/* this is a repository for the medications */

class Repository
{
	std::vector <Medikament> apotheke;
	/* this attribute will store the last instruction for the redo and undo. Every instruction has a number. */
	int last_instruction = 0; 

public:

	bool in_list(std::string name, int konzentration);

	Medikament find_medikament(std::string name, int konzentration);

	std::vector <Medikament> string_in_name(std::string zeichenkette);
	
	std::vector<Medikament> knappe_Medikamente(int menge);

};
