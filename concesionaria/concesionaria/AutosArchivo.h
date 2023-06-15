#include "Auto.h"
#include <cstring>

class AutosArchivo {
private:
	char _ruta[50];

public:
	AutosArchivo(const char* ruta);
	int guardar(Auto reg);
	int guardar(Auto reg, int pos);
	int buscarPorId(int id);
	Auto leer(int pos);
	void leer(Auto* listRegs, int cantRegistros);
	int baja(int pos);
	int getCantidadRegistros();
};