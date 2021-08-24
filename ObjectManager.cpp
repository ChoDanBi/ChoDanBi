#include "ObjectManager.h"

ObjectManager* ObjectManager::Instance = nullptr;

void ObjectManager::AddObject(Object* _Object,string _Key)
{
	list<Object*> Temp;
	Temp.push_back(new Object(_Object));
	ObjectList[_Key] = Temp;
}

void ObjectManager::Release()
{
	delete ObjectList;
	ObjectList = nullptr;
	delete Player;
	Player = nullptr;
}
