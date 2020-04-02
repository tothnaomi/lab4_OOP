#pragma once
#include "Repository.h"

class Kontroller
{
	Repository repo;

public:

	void add_Medikament(std::string name, int konzentration, double preis);

	void loschen_Medikament(std::string name, int konzentration);

	void bearbeiten_Medikament_name(std::string name, int konzentration, std::string new_name);

	void bearbeiten_Medikament_konzentration(std::string name, int konzentration, int neue_konzentration);

	void bearbeiten_Medikament_menge(std::string name, int konzentration, int new_menge);

	void bearbeiten_Medikament_preis(std::string name, int konzentration, double neues_preis);
};