#pragma once
#include "Auto.h"

Auto::Auto() {
	_idAuto = 0;
	_marca = "";
	_modelo = "";
	_cantidadPuertas = 0;
	_anioFabricacion = 0;
	_combustible = 0;
	_cilindraje = 0.0;
	_condicion = 0;
	_kilometraje = 0.0f;
	_estado = false;
}

Auto::Auto(int id, std::string marca, std::string modelo, int cantPuertas, int anio, int combustible, float cilindraje, bool condicion, float kilometraje, bool estado) {
	_idAuto = id;
	_marca = marca;
	_modelo = modelo;
	_cantidadPuertas = cantPuertas;
	_anioFabricacion = anio;
	_combustible = combustible;
	_cilindraje = cilindraje;
	_condicion = condicion;
	_kilometraje = kilometraje;
	_estado = estado;
}

//setters
void Auto::setId(int id) {
	_idAuto = id;
}

void Auto::setMarca(std::string marca) {
	_marca = marca;
}

void Auto::setModelo(std::string modelo) {
	_modelo = modelo;
}

void Auto::setCantidadPuertas(int cantPuertas) {
	_cantidadPuertas = cantPuertas;
}

void Auto::setAnioFabricacion(int anio) {
	_anioFabricacion = anio;
}

void Auto::setCombistible(int codCombustible) {
	_combustible = codCombustible;
}

void Auto::setCilindraje(float cilindraje) {
	_cilindraje = cilindraje;
}

void Auto::setCondicion(int condicion) {
	_condicion = condicion;
}

void Auto::setKilometraje(float km) {
	_kilometraje = km;
}

//getters
int Auto::getId(){
	return _idAuto;
}

std::string Auto::getMarca() {
	return _marca;
}

std::string Auto::getModelo() {
	return _modelo;
}

int Auto::getCantidadPuertas() {
	return _cantidadPuertas;
}

int Auto::getAnioFabricacion() {
	return _anioFabricacion;
}

int Auto::getCombustible() {
	return _combustible;
}

float Auto::getCilindraje() {
	return _cilindraje;
}


int Auto::getCondicion() {
	return _condicion;
}

float Auto::getKilometraje() {
	return _kilometraje;
}

bool Auto::getEstado() {
	return _estado;
}