#include "Menu.h"
Menu::Menu() {
	this->menuPrincipal();
}

void Menu::menuPrincipal() {
	int opc;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "        Concecionaria SOLARI" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 - AUTOS" << std::endl;
		std::cout << "--------" << std::endl;
		std::cout << "--------" << std::endl;
		std::cout << "0 - SALIR " << std::endl;
		std::cin >> opc;

		switch(opc){
			case 1:
				this->menuAutos();
				break;

			case 0:
				std::cout << "Gracias por usar mi programa, un gran saludo... atte: Samuel Medina :)" << std::endl;
				system("pause");
				break;
		}

	} while (opc != 0);


}

void Menu::menuAutos() {
	int opc;

	do {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "             Menu Autos" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "1 - Agregar al stock " << std::endl;
		std::cout << "2 - Listar Todo" << std::endl;
		std::cout << "--------" << std::endl;
		std::cout << "0 - Volver " << std::endl;
		std::cin >> opc;

		switch (opc) {
		case 1:
			managerA.agregar();
			break;

		case 2:
			managerA.listarTodo();
			break;

		case 0:
			system("cls");
			break;
		}
		system("pause");
	} while (opc != 0);
}