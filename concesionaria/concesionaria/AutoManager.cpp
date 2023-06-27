#include "AutoManager.h"

void AutoManager::agregar() {
	int id = this->generarId();
	Auto aux = this->cargar(id);

	this->mostrar(aux);

	char opc;
	std::cout << "¿Desea guardar este registro?" << std::endl;
	std::cout << "      S - si     N - no" << std::endl;
	std::cin >> opc;

	if (opc != 'S' && opc != 's') {
		std::cout << "Operacion cancelada... :)" << std::endl;
		return;
	}

	int result = _archivoA.guardar(aux);

	if (result > 0) {
		std::cout << "Registro guardado" << std::endl;
	}
	else {
		std::cout << "No se pudo guardar este registro" << std::endl;
	}
}

void AutoManager::buscar() {
	int id;

	//pedir id
	std::cout << "Ingrese Id del auto: ";
	std::cin >> id;

	//verificar si ese id existe
	int pos = _archivoA.buscarPorId(id);

	if (pos < 0) {
		std::cout << "No existe ningun registro con ese numero Id..." << std::endl;
		return;
	}

	//Leer el registro del archivo
	Auto reg = _archivoA.leer(pos);

	//mostrar registro
	this->mostrar(reg);
}

void AutoManager::modificar() {
	int id;

	std::cout << "Ingrese Id del auto: ";
	std::cin >> id;

	int pos = _archivoA.buscarPorId(id);

	if (pos < 0) {
		std::cout << "No existe ningun registro con ese numero Id..." << std::endl;
		return;
	}
	
	Auto reg = _archivoA.leer(pos);
	this->mostrar(reg);

	char opc;
	std::cout << "¿Desea modificar este registro?" << std::endl;
	std::cout << "      S - si     N - no" << std::endl;
	std::cin >> opc;

	if (opc != 'S' && opc != 's') {
		std::cout << "Operacion cancelada... :)" << std::endl;
		return;
	}

	reg = this->cargar(id);
	int result = _archivoA.guardar(reg, pos);

	if (result > 0) {
		std::cout << "Registro modificado" << std::endl;
	}
	else {
		std::cout << "No se pudo modificar este registro" << std::endl;
	}

}

void AutoManager::baja() {
	int id;

	//pedir id
	std::cout << "Ingrese Id del auto: ";
	std::cin >> id;

	//verificar si ese id existe
	int pos = _archivoA.buscarPorId(id);

	if (pos < 0) {
		std::cout << "No existe ningun registro con ese numero Id..." << std::endl;
		return;
	}

	//Leer el registro del archivo
	Auto reg = _archivoA.leer(pos);

	//mostrar registro
	this->mostrar(reg);

	char opc;
	std::cout << "¿Esta seguro de que quiere eliminar el registro?" << std::endl;
	std::cout << "          S - si     N - no" << std::endl;
	std::cin >> opc;

	if (opc != 'S' && opc != 's') {
		std::cout << "Operacion cancelada... :)" << std::endl;
		return;
	}

	reg.setEstado(false);
	int result = _archivoA.guardar(reg, pos);

	if (result > 0) {
		std::cout << "Registro eliminado" << std::endl;
	}
	else {
		std::cout << "No se pudo eliminar registro" << std::endl;   
	}
		

}

void AutoManager::listarTodo() {
	int cantRegistros = _archivoA.getCantidadRegistros();
	Auto* autos = new Auto[cantRegistros];

	if (autos == nullptr) {
		std::cout << "No se pudo listar los registros... :(" << std::endl;
		return;
	}

	_archivoA.leer(autos, cantRegistros);

	this->mostrarTodo(autos, cantRegistros);

}

void AutoManager::mostrar(Auto reg) {
	system("cls");
	std::cout << "Numero de registro :" << reg.getId() << std::endl;

	if (!reg.getEstado()) {
		std::cout << "Registro dado de baja" << std::endl;
		return;
	}
	std::cout << "Marca  :" << reg.getMarca() << std::endl;
	std::cout << "Modelo :" << reg.getModelo() << std::endl;
	std::cout << "Puertas :" << reg.getCantidadPuertas() << std::endl;
	std::cout << "Anio   :" << reg.getAnioFabricacion() << std::endl;
	std::cout << "Combustible :" << reg.getCombustible() << std::endl;
	std::cout << "Motor :" << reg.getCilindraje() << std::endl;
	std::cout << "Condicion :" << reg.getCondicion() << std::endl;
	std::cout << "Kilometros: " << reg.getKilometraje() << std::endl;
}

void AutoManager::mostrarTodo(Auto* autos, int cantRegistros) {
	system("cls");

	std::cout << std::left;
	std::cout << std::setw(10) << "Marca";
	std::cout << std::setw(30) << "Modelo";
	std::cout << std::setw(4) << "CP";
	std::cout << std::setw(6) << "Anio";
	std::cout << std::setw(5) << "Comb";
	std::cout << std::setw(5) << "Motor";
	std::cout << std::setw(5) << "Cond";
	std::cout << std::setw(15) << "Kilometros" << std::endl;

	std::cout << "-----------------------------------------------------------------------------------" << std::endl;

	for (int i = 0; i < cantRegistros; i++) {
		if (autos[i].getEstado()) {
			std::cout << std::left;
			std::cout << std::setw(10) << autos[i].getMarca();
			std::cout << std::setw(30) << autos[i].getModelo();
			std::cout << std::setw(4) << autos[i].getCantidadPuertas();
			std::cout << std::setw(6) << autos[i].getAnioFabricacion();
			std::cout << std::setw(5) << autos[i].getCombustible();
			std::cout << std::setw(7) << autos[i].getCilindraje();
			std::cout << std::setw(5) << autos[i].getCondicion();
			std::cout << std::setw(15) << autos[i].getKilometraje() << std::endl;
		}
	}
}

Auto AutoManager::cargar(int id) {
	std::string marca, modelo;
	int cantidadPuertas, anioFabricacion, combustible, condicion;
	float cilindraje, kilometraje;

	std::cout << "--------------------------------" << std::endl;
	std::cout << "      Registro numero: " << id << std::endl;
	std::cout << "--------------------------------" << std::endl;

	std::cout << "Marca: ";
	std::cin.ignore();
	getline(std::cin, marca);

	std::cout << "Modelo: ";
	getline(std::cin, modelo);

	std::cout << "Cantidad de puertas: ";
	std::cin >> cantidadPuertas;

	std::cout << "Anio Fabricacion: ";
	std::cin >> anioFabricacion;

	std::cout << "Combustible (1 - Nafta, 2 - Diesel, 3 - Electrico): ";
	std::cin >> combustible;

	std::cout << "Cilindraje del motor: ";
	std::cin >> cilindraje;

	std::cout << "Condicion (1 - 0 Km, 2 - Usado): ";
	std::cin >> condicion;

	std::cout << "Kilometraje: ";
	std::cin >> kilometraje;

	Auto aux = Auto(id, marca, modelo, cantidadPuertas, anioFabricacion, combustible, cilindraje, condicion, kilometraje, true);

	return aux;
}

int AutoManager::existeId(int id) {
	return _archivoA.buscarPorId(id) >= 0;
}

int AutoManager::generarId() {
	int cantRegistros = _archivoA.getCantidadRegistros();

	if (cantRegistros < 0) {
		cantRegistros = 0;
	}

	return cantRegistros+1;
}