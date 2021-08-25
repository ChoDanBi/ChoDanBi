#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;

		return Instance;
	}
private:
	// ** �÷��̾�
	Object* pPlayer;

	// ** ������Ʈ ����Ʈ
	map<string, list<Object*>> ObjectList;
public:
	void AddObject(Object* _Object);
	void Release();
public:
	// ** �÷��̾ ��ȯ.
	Object* GetPlayer() { return pPlayer; }
	void SetPlayer(Object* _pPlayer) { pPlayer = _pPlayer; }

	// ** map �����̳ʸ� ����ϰ��ִ� ObjectList�� ��ȯ.
	map<string, list<Object*>>* GetObjectList() { return &ObjectList; }


	// ** map �����̳ʸ� ����ϰ��ִ� ObjectList�� ���Ե� list �� Ž���Ͽ� ��ȯ.
	list<Object*>* FindList(string _Key) 
	{
		map<string, list<Object*>>::iterator iter = ObjectList.find(_Key);

		// ** �������� �ʴ� key������ nullptr�� ��ȯ.
		if (iter == ObjectList.end())
			return nullptr;

		return &iter->second;
	}
private:
	ObjectManager() : pPlayer(nullptr) { }
public:
	~ObjectManager() { Release(); }
};

