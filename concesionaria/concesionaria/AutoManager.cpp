#include "AutoManager.h"

void AutoManager::agregar() {
	
}

void AutoManager::buscar() {
	int id;

	//pedir id
	std::cout << "Ingrese Id del auto: ";
	std::cin >> id;

	//verificar si ese id existe
	int pos = _archivoA.buscarPorId(id);

	if (pos >= 0) {
		std::cout << "No existe ningun registro con ese numero Id..." << std::endl;
	}

	//Leer el registro del archivo
	Auto reg = _archivoA.leer(pos);

	//mostrar registro
	this->mostrar(reg);
}

void AutoManager::modificar() {

}

void AutoManager::baja() {

}

void AutoManager::listarTodo() {

}

void AutoManager::mostrar(Auto reg) {
	if (!reg.getEstado()) {
		return;
	}
	std::cout << "Numero de registro :" << reg.getId() << std::endl;
	std::cout << "Marca  :" << reg.getMarca() << std::endl;
	std::cout << "Modelo :" << reg.getModelo() << std::endl;
	std::cout << "Puertas :" << reg.getCantidadPuertas() << std::endl;
	std::cout << "Anio   :" << reg.getAnioFabricacion() << std::endl;
	std::cout << "Combustible :" << reg.getCombustible() << std::endl;
	std::cout << "Motor :" << reg.getCilindraje() << std::endl;
	std::cout << "Condicion :" << reg.getCondicion() << std::endl;
	std::cout << "Kilometros" << reg.getKilometraje() << std::endl;
}

int AutoManager::existeId(int id) {
	return _archivoA.buscarPorId(id) >= 0;
}

int AutoManager::generarId() {
	int cantRegistros = _archivoA.getCantidadRegistros();
	return cantRegistros+1;
}