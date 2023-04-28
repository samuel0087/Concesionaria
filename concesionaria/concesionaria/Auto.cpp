#pragma once
#include "Auto.h"

Auto::Auto() {
	_idAuto = 0;
	_marca = "";
	_modelo = "";
	_anioFabricacion = 0;
	_conbustible = 0;
	_cilindraje = 0.0;
	_condicion = 0;
}

Auto::Auto(int id, std::string marca, std::string modelo, int anio, int condicion, float cilindraje) {
	_idAuto = id;
	_marca = marca;
	_modelo = modelo;
	_anioFabricacion = anio;
	_condicion = condicion;
	_cilindraje = cilindraje;
}

void Auto::setId(int id) {
	_idAuto = id;
}

void Auto::setMarca(std::string marca) {
	_marca = marca;
}

void Auto::setModelo(std::string modelo) {
	_modelo = modelo;
}

void Auto::setAnioFabricacion(int anio) {
	_anioFabricacion = anio;
}

void Auto::setCombistible(int codCombustible) {
	_conbustible = codCombustible;
}

void Auto::setCilindraje(float cilindraje) {
	_cilindraje = cilindraje;
}

void Auto::setCondicion(int condicion) {
	_condicion = condicion;
}

int Auto::getId(){
	return _idAuto;
}

std::string Auto::getMarca() {
	return _marca;
}

std::string Auto::getModelo() {
	ret
}

int getAnioFabricacion();
std::string getCombustible();
float getCilindraje();
std::string getCondicion();