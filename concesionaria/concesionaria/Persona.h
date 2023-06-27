#pragma once
#include "Fecha.h"
#include <cstring>
#include <string>

class Persona
{
	protected:
		char _nombres[35];
		char _apellidos[35];
		int _dni;
		Fecha _fechaNacimiento;
		char _nacionalidad[20];
		int _genero;
		bool _estado;

	public:

		Persona(std::string nombres, std::string apellidos, int dni, Fecha fecha, std::string nacionalidad, int genero, bool estado);
		void setNombres(std::string nombres);
		void setApellidos(std::string apellidos);
		void setDni(int dni);
		void setFechaNacimiento(Fecha fecha);
		void setNacionalidad(std::string nacionalidad);
		void setGenero(int genero);
		void setEstado(bool estado);
		
		std::string getNombres();
		std::string getApellidos();
		int getDni();
		Fecha getFechaNacimiento();
		std::string getNacionalidad();
		int getGenero();
		bool getEstado();
};

