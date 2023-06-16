#pragma once
#include <iostream>
#include <string>
#include "AutoManager.h"

class Menu
{
	private:
		AutoManager managerA;

	public:
		Menu();
		void menuPrincipal();
		void menuAutos();
};

