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
		std::cout << "3 - Buscar" << std::endl;
		std::cout << "4 - Modificar" << std::endl;
		std::cout << "5 - Eliminar" << std::endl;
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

		case 3:
			managerA.buscar();
			break;

		case 4:
			managerA.modificar();
			break;
			
		case 5:
			managerA.baja();
			break;

		case 0:
			system("cls");
			break;
		}
	} while (opc != 0);
}