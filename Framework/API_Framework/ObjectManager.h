#pragma once
#include "Headers.h"

class Object;
class Prototype;
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
	Prototype* PrototypeObject;

	// ** 플레이어
	Object* pPlayer;

	// ** 오브젝트 리스트
	list<Object*> EnableList;
	map<string, list<Object*>> DisableList;
public:
	// ** 초기화
	void Initialize();

	// ** 객체 생성
	Object* CreateObject(string _Key);

	// ** 컨테이너에서 객체를 찾음
	void FindObject(string _Key);

	// ** 객체 생성
	Object* CreateObject(string _Key, Vector3 _Position);

	// ** 컨테이너에서 객체를 찾음
	void FindObject(string _Key, Vector3 _Position);

	// ** 객체 추가.
	void AddObject(string _strKey);

	// ** 사용후 더이상 사용하지 않는 오브젝트 회수
	void RecallObject(Object* _Object);

	void Release();
public:
	// ** 플레이어를 반환.
	Object* GetPlayer() { return pPlayer; }
	void SetPlayer(Object* _pPlayer) { pPlayer = _pPlayer; }


	// ** map 컨테이너를 사용하고있는 ObjectList를 반환.
	list<Object*>* GetEnableList() { return &EnableList; }
	map<string, list<Object*>>* GetDisableList() { return &DisableList; }


	// ** map 컨테이너를 사용하고있는 ObjectList에 포함된 list 를 탐색하여 반환.
	list<Object*>* FindList(string _Key) 
	{
		map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

		// ** 존재하지 않는 key값에는 nullptr를 반환.
		if (iter == DisableList.end())
			return nullptr;

		return &iter->second;
	}
private:
	ObjectManager() : pPlayer(nullptr) { }
public:
	~ObjectManager() { Release(); }
};

