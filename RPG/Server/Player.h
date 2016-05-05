#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Objecto;

class Player {

	string _name;
	int _life = 100;
	static int _id_inc;
	int _id;
	int _slowness;
	bool inGame;

public:
	Player(string n);
	~Player();
	vector <Objecto *> ob;

	//Gets
	int getLife();
	int getID();
	int getSlowness();
	string getName();
	
	//Sets
	void setLife(int l);
	void setName(string n);
	void setSlowness(int value);

	//Member Function


	

	
};