#pragma once

#include "Objecto.h"

#ifndef __OBJECTO_H__
#define __OBJECTO_H__

#include<string>
using namespace std;

class Objecto {
	/*static*/ int Oid;
	string tipo;
	int  id;
	int xx;
	int yy;

public:

	Objecto(string t, int x, int y);
	string getTipo();
	int getId();
	int getX();
	int getY();
};

#endif