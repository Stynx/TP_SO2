#include "Object.h"

Objecto::Objecto(int x, int y) {
	
	this->_xx = x;
	this->_yy = y;

	int i;

	i = 1 + (rand() % 4);

	if (i == 1) {
		//Vitaminhas
		
	}
	else
		if (i == 2) {
			//Orangebull
		}
		else
			if (i == 3) {
				//Pedra
			}
			else 
				if (i == 4) {
					//rebucado de cafeina
				}
	
}

string Objecto::getTipe() {
	return _tipe;
}

int Objecto::getX() {
	return _xx;
}

int Objecto::getY() {
	return _yy;
}

int Objecto::getSlowness(){
	return _slowness;
}

int Objecto::getVelocity() {
	return _velocity;
}

void Objecto::setHealth(int value) {
	this->_health = value;
}

void Objecto::setSlowness(int value) {
	this->_slowness = value;
}

void Objecto::setTipe(string t) {
	this->_tipe = t;
}

void Objecto::setXX(int x) {
	this->_xx = x;
}

void Objecto::setYY(int y) {
	this->_yy = y;
}






