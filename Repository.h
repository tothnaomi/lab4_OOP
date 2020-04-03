#pragma once
#include <vector>
#include <string>
#include "Medikamente.h""

/* this is a repository for the medications */

class Repository
{
	friend class Kontroller;
	
	/* this attribute will store the last instruction for the redo and undo. Every instruction has a number. 
	1) loschen
	2) hinzufugen
	3) bearbeiten */

public:
	std::vector <Medikament> medikamenten;

	bool in_list(std::string name, int konzentration);

	void loschen_Medikament(std::string name, int konzentration);

};
