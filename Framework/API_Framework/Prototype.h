#pragma once
#include "Headers.h"

class Object;
class Prototype
{
private:
	map<string, Object*> PrototypeList;
public:
	void CreatePrototype();
	Object* FindPrototypeObject(string _Key);
public:
	Prototype();
	~Prototype();
};

