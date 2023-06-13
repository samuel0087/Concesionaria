#pragma once
#include <iostream>
#include "Auto.h"
#include "AutosArchivo.h"

class AutoManager{
	public:
		void agregar();
		void buscar();
		void modificar();
		void baja();
		void listarTodo();
		void mostrar(Auto reg);
	
	private:
		AutosArchivo _archivoA = AutosArchivo("autos.dat");

		int existeId(int id);
		int generarId();
};

