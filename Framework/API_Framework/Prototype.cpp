#include "Prototype.h"

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"


Prototype::Prototype()
{

}

Prototype::~Prototype()
{

}


void Prototype::CreatePrototype()
{
	Transform TransInfo;

	PrototypeList["Player"] = new Player(TransInfo);
	PrototypeList["Enemy"] = new Enemy(TransInfo);
	PrototypeList["Bullet"] = new Bullet(TransInfo);
}

Object* Prototype::FindPrototypeObject(string _Key)
{
	map<string, Object*>::iterator iter = PrototypeList.find(_Key);

	if (iter == PrototypeList.end())
	{
		//ERROR_MESSAGE("���� ������ ��ü ������ �����ϴ�.", _Key);
		
		Sleep(500);
		return nullptr;
	}

	return iter->second;
}
