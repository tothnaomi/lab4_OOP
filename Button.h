#pragma once
#include <string>
#include "Kontroller.h"

class Button
{
	Kontroller* kontroller;

public:
	std::string last_function;
	std::string name;
	int konzentration;
	int menge;
	double price;
	std::string new_name;
	int new_menge;
	double new_price;
	int new_concentration;

	void set_kontroller(Kontroller* kont);
	
	Kontroller* get_kontroller();

	void set(std::string, std::string, int,int ,double, std::string, int, int, double);

	void redo();

	void undo();
};