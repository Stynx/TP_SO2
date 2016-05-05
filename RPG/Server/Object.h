#pragma once

#ifndef __OBJECTO_H__
#define __OBJECTO_H__

#include<string>
#include <iostream>
#include <vector>

#include "Player.h"

using namespace std;

class Objecto {
	string _tipe;
	int _xx;
	int _yy;
	int _health;
	int _velocity;
	int _slowness;

public:

	Objecto(int x, int y);
	Player *p;

	//Gets
	string getTipe();
	int getX();
	int getY();
	int getVelocity();
	int getSlowness();

	//Sets
	void setTipe(string t);
	void setHealth(int value);
	void setVelocity(int value);
	void setSlowness(int value);
	void setYY(int y);
	void setXX(int x);

	//Member Function 



};

#endif