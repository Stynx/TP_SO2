#include "Objecto.h"

Objecto::Objecto(string t, int x, int y) {
	tipo = t;
	id = Oid;
	xx = x;
	yy = y;
	Oid++;
}

string Objecto::getTipo() {
	return tipo;
}

int Objecto::getId() {
	return id;
}

int Objecto::getX() {
	return xx;
}

int Objecto::getY() {
	return yy;
}