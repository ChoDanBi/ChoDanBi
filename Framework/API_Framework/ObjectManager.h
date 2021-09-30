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

	// ** �÷��̾�
	Object* pPlayer;

	//�������� ����
	Object* pButton;

	// ** ������Ʈ ����Ʈ
	
	vector<Object*> BulletList;
	vector<Object*> EnemyList;
	vector<Object*> EBulletList;
	
	list<Object*> EnableList;
	map<string, list<Object*>> DisableList;
public:
	// ** �ʱ�ȭ
	void Initialize();

	// ** ��ü ����
	Object* CreateObject(string _Key);

	// ** �����̳ʿ��� ��ü�� ã��
	void FindObject(string _Key);

	// ** ��ü ����
	Object* CreateObject(string _Key, Vector3 _Position);

	// ** �����̳ʿ��� ��ü�� ã��
	void FindObject(string _Key, Vector3 _Position);

	// ** ��ü �߰�.
	void AddObject(string _strKey);

	// ** ����� ���̻� ������� �ʴ� ������Ʈ ȸ��
	void RecallObject(Object* _Object);

	// ** ���� Ÿ���� ��ġ�� ���´�.
	Object* GetTarget(Vector3 _Pos);


	void Release();
public:
	// ** �÷��̾ ��ȯ.
	Object* GetPlayer() { return pPlayer; }
	void SetPlayer(Object* _pPlayer) { pPlayer = _pPlayer; }

	Object* GetButton() { return pButton; }
	void SetButton(Object* _pButton) { pButton = _pButton; }

	// ** map �����̳ʸ� ����ϰ��ִ� ObjectList�� ��ȯ.
	list<Object*>* GetEnableList() { return &EnableList; }
	map<string, list<Object*>>* GetDisableList() { return &DisableList; }

	
	vector<Object*>* GetBulletList() { return &BulletList; }
	vector<Object*>* GetEnemyList() { return &EnemyList; }
	vector<Object*>* GetEnemyBullet() { return &EBulletList; }

	void AddBullet(Vector3 _vPos);



	// ** map �����̳ʸ� ����ϰ��ִ� ObjectList�� ���Ե� list �� Ž���Ͽ� ��ȯ.
	list<Object*>* FindList(string _Key) 
	{
		map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

		// ** �������� �ʴ� key������ nullptr�� ��ȯ.
		if (iter == DisableList.end())
			return nullptr;

		return &iter->second;
	}
private:
	ObjectManager() : pPlayer(nullptr) { }
public:
	~ObjectManager() { Release(); }
};

