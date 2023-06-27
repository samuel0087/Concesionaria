#include "Persona.h"
Persona::Persona(std::string nombres = "", std::string apellidos = "", int dni = 0, Fecha fecha = Fecha(0,0,0), std::string nacionalidad = "", int genero = 0, bool estado = false) {
	strcpy(_nombres, nombres.c_str());
	strcpy(_apellidos, apellidos.c_str());
	_dni = dni;
	_fechaNacimiento = fecha;
	strcpy(_nacionalidad, nacionalidad.c_str());
	_genero = genero;
	_estado = estado;
}

void Persona::setNombres(std::string nombres) {
	strcpy(_nombres, nombres.c_str());
}

void Persona::setApellidos(std::string apellidos) {
	strcpy(_apellidos, apellidos.c_str());
}

void Persona::setDni(int dni) {
	_dni = dni;
}

void Persona::setFechaNacimiento(Fecha fecha) {
	_fechaNacimiento = fecha;
}

void Persona::setNacionalidad(std::string nacionalidad) {
	strcpy(_nacionalidad, nacionalidad.c_str());
}

void Persona::setGenero(int genero) {
	_genero = genero;
}

void Persona::setEstado(bool estado){
	_estado = estado;
}

std::string Persona::getNombres(){
	std::string nombres = _nombres;
	return nombres;
}

std::string Persona::getApellidos(){
	std::string apellidos = _apellidos;
	return apellidos;
}

int Persona::getDni(){
	return _dni;
}

Fecha Persona::getFechaNacimiento(){
	return _fechaNacimiento;
}

std::string Persona::getNacionalidad(){
	std::string nacionalidad = _nacionalidad;
	return nacionalidad;
}

int Persona::getGenero(){
	return _genero;
}

bool Persona::getEstado() {
	return _estado;
}