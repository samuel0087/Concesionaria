#pragma once
#include <string>

class Auto
{
	private: 
		int _idAuto;
		std::string _marca;
		std::string _modelo;
		int _cantidadPuertas;
		int _anioFabricacion;
		int _combustible;
		float _cilindraje;
		int _condicion;
		float _kilometraje;
		bool _estado;

	public:
		Auto();
		Auto(int id, std::string marca, std::string modelo,int cantPuertas, int anio,int combustible, float cilindraje, int condicion, float kilometraje, bool estado );

		void setId(int id);
		void setMarca(std::string marca);
		void setModelo(std::string modelo);
		void setCantidadPuertas(int cantPuertas);
		void setAnioFabricacion(int anio);
		void setCombistible(int codCombustible);
		void setCilindraje(float cilindraje);
		void setCondicion(int condicion);
		void setKilometraje(float km);
		void setEstado(bool estado);

		int getId();
		std::string getMarca();
		std::string getModelo();
		int getCantidadPuertas();
		int getAnioFabricacion();
		int getCombustible();
		float getCilindraje();
		int getCondicion();
		float getKilometraje();
		bool getEstado();
};

