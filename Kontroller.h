#pragma once
#include "Repository.h"
#include "Button.h"

class Kontroller
{
	friend class Apotheke;
	friend class Button;
	Repository* repo;
	Button* button;

public:
	
	void set_repo(Repository* repo, Button* b);

	void add_Medikament(std::string name, int konzentartion, int menge, double preis);

	void loschen_Medikament(std::string name, int konzentration);

	void bearbeiten_Medikament_name(std::string name, int konzentration, std::string new_name);

	void bearbeiten_Medikament_konzentration(std::string name, int konzentration, int neue_konzentration);

	void bearbeiten_Medikament_menge(std::string name, int konzentration, int new_menge);

	void bearbeiten_Medikament_preis(std::string name, int konzentration, double neues_preis);

	Repository* get_repo() { return this->repo; }
};