#include "Player.h"

int Player::_id_inc = 0;

Player::Player(string n){
	n = this->_name;

	setLife(10);
	setSlowness(5);

	_id_inc++;
	_id = _id_inc;

}

Player::~Player(){
}

string Player::getName() {
	return _name;
}

int Player::getSlowness() {
	return _slowness;
}

int Player::getLife(){
	return _life;
}

int Player::getID(){
	return _id;
}

void Player::setLife(int l){
	this->_life = l;
}

void Player::setName(string n){
	this->_name = n;
}

void Player::setSlowness(int value){

	this->_slowness = value;
}