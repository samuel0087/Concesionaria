#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Auto.h"
#include "AutosArchivo.h"

class AutoManager{
	public:
		void agregar();
		void buscar();
		void modificar();
		void baja();
		void listarTodo();
	
	private:
		AutosArchivo _archivoA = AutosArchivo("autos.dat");

		int existeId(int id);
		int generarId();
		Auto cargar(int id);
		void mostrar(Auto reg);
		void mostrarTodo(Auto* autos, int cantRegistros);
};

