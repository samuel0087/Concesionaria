#include <stdio.h>
#include "AutosArchivo.h"

AutosArchivo::AutosArchivo(const char* ruta) {
	strcpy(_ruta, ruta);
}

int AutosArchivo::guardar(Auto reg) {
	FILE* archivoA = fopen(_ruta, "ab");

	if (archivoA == NULL) {
		return -1;
	}

	int result = fwrite(&reg, sizeof(Auto), 1, archivoA);
	fclose(archivoA);

	return result;
}

int AutosArchivo::guardar(Auto reg, int pos) {
	FILE* archivoA = fopen(_ruta, "rb+");

	if (archivoA == NULL) {
		return -1;
	}

	fseek(archivoA, sizeof(Auto) * pos, SEEK_SET);
	int result = fwrite(&reg, sizeof(Auto), 1, archivoA);
	fclose(archivoA);

	return result;
}

int AutosArchivo::buscarPorId(int id) {
	int cantRegistros = this->getCantidadRegistros();

	for (int i = 0; i < cantRegistros; i++) {
		Auto reg = this->leer(i);

		if (reg.getId() == id) {
			return i;
		}
	}

	return -1;
}

Auto AutosArchivo::leer(int pos) {
	Auto reg;
	reg.setId(-1);
	int cantRegistros = this->getCantidadRegistros();
	FILE* archivoA = fopen(_ruta, "rb+");

	if (archivoA == NULL) {
		return reg;
	}

	fseek(archivoA, sizeof(Auto) * pos, SEEK_SET);
	fread(&reg, sizeof(Auto), 1, archivoA);
	fclose(archivoA);

	return reg;
}

void AutosArchivo::leer(Auto* listRegs, int cantRegistros) {
	FILE* archivoA = fopen(_ruta, "rb+");

	if (archivoA == NULL) {
		return;
	}

	fread(listRegs, sizeof(Auto), cantRegistros, archivoA);
	fclose(archivoA);
}

int AutosArchivo::baja(int pos) {
	Auto reg = this->leer(pos);

	reg.setEstado(false);
	int result = this->guardar(reg, pos);

	return result;
}

int AutosArchivo::getCantidadRegistros() {
	FILE* archivoA = fopen(_ruta, "rb");

	if (archivoA == NULL) {
		return -1;
	}

	fseek(archivoA, 0, SEEK_END);
	int byte = ftell(archivoA);
	int cantRegistros = byte / sizeof(Auto);
	fclose(archivoA);

	return cantRegistros;
}
