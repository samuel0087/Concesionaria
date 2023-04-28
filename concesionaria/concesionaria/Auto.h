#pragma once
#include <string>
#include "fecha.h"

class Auto
{
	private: 
		int _idAuto;
		std::string _marca;
		std::string _modelo;
		int _anioFabricacion;
		int _conbustible;
		float _cilindraje;
		int _condicion;

	public:
		Auto();
		Auto(int id, std::string marca, std::string modelo, int anio, int condicion, float cilindraje);

		void setId(int id);
		void setMarca(std::string marca);
		void setModelo(std::string modelo);
		void setAnioFabricacion(int anio);
		void setCombistible(int codCombustible);
		void setCilindraje(float cilindraje);
		void setCondicion(int condicion);

		int getId();
		std::string getMarca();
		std::string getModelo();
		int getAnioFabricacion();
		std::string getCombustible();
		float getCilindraje();
		std::string getCondicion();
};

