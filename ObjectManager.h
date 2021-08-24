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
	Object* Player;

	// ** ������Ʈ ����Ʈ
	map<string, list<Object*>> ObjectList;
public:
	void AddObject(Object* _Object, string _Key);
	void Release();
public:
	// ** �÷��̾ ��ȯ.
	Object* GetPlayer() { return Player; }

	// ** map �����̳ʸ� ����ϰ��ִ� ObjectList�� ��ȯ.
	map<string, list<Object*>> GetObjectList() { return ObjectList; }

	// ** map �����̳ʸ� ����ϰ��ִ� ObjectList�� ���Ե� list �� Ž���Ͽ� ��ȯ.
	// ** �������� �ʴ� key������ nullptr�� ��ȯ.
	list<Object*>* FindList(string _Key) 
	{
		map<string, list<Object*>>::iterator iter = ObjectList.find(_Key);

		if (iter == ObjectList.end())
			return nullptr;

		return &iter->second;
	}
private:
	ObjectManager() : Player(nullptr) { }
public:
	~ObjectManager() { Release(); }
};

