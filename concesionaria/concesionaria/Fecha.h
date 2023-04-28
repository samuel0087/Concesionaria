#pragma once
#include <string>

class Fecha
{
private:
	int _dia;
	int _mes;
	int _anio;

	bool anioBisiesto(int);
	int cantidadDiaMes(int, int);
	void agregarDia();
	void restarDia();

public:
	//constructor
	Fecha();
	Fecha(int, int, int);
	
	//setters
	void setDia(int);
	void setMes(int);
	void setAnio(int);

	//getters
	int getDia();
	int getMes();
	int getAnio();
	void agregarDias(int canDias);
	std::string toString();
};

