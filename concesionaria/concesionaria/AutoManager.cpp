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

	std::cout << "------------------------------------" << std::endl;
	std::cout << "      Lista de autos en stock" << std::endl;
	std::cout << "------------------------------------" << std::endl;

	for (int i = 0; i < cantRegistros; i++) {
		this->mostrar(autos[i]);
		std::cout << "------------------------------------" << std::endl;
	}

}

void AutoManager::mostrar(Auto reg) {
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
	std::cout << "Kilometros" << reg.getKilometraje() << std::endl;
}

int AutoManager::existeId(int id) {
	return _archivoA.buscarPorId(id) >= 0;
}

int AutoManager::generarId() {
	int cantRegistros = _archivoA.getCantidadRegistros();
	return cantRegistros+1;
}