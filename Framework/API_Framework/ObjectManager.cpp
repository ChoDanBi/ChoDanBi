#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Prototype.h"
#include "Enemy.h"

ObjectManager* ObjectManager::Instance = nullptr;

void ObjectManager::Initialize()
{
	PrototypeObject = new Prototype;
	PrototypeObject->CreatePrototype();
}

Object* ObjectManager::CreateObject(string _Key)
{
	// ** ���ο� ��ü�� �������־�� �Ѵ�. ������ ���� ��ü�� ��������ϴ� ������� ������ ���̴�.
	// ** �׷����� ���� ������ü�� �����ϴ��� ã�´�.
	Object* pProtoObject = PrototypeObject->FindPrototypeObject(_Key);

	// ** ������ü�� ���ٸ�....
	if (pProtoObject == nullptr)
		return nullptr;
	// ** ���� ��ü�� �ִٸ�...
	else
	{
		// ** ������ü�� ���� �����Ѵ�.
		Object* pObject = pProtoObject->Clone();
		pObject->Initialize();

		return pObject;
	}
}

// ** Prototype ���� �� �۾�
void ObjectManager::FindObject(string _Key)
{
	// ** DisableList�� �����Ϸ��� ������Ʈ�� �ִ��� Ȯ��.
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

	// ** ������.....
	if (iter == DisableList.end() || iter->second.empty())
	{
		Object* pObject = CreateObject(_Key);

		if (pObject == nullptr)
			return;

		// ** DisableList ����
		EnableList.push_back(pObject);
	}
	else
	{
		Object* pObject = iter->second.front();
		pObject->Initialize();

		// ** DisableList ����
		EnableList.push_back(pObject);
		iter->second.pop_front();
	}
}

Object* ObjectManager::CreateObject(string _Key, Vector3 _Position)
{
	// ** ���ο� ��ü�� �������־�� �Ѵ�. ������ ���� ��ü�� ��������ϴ� ������� ������ ���̴�.
	// ** �׷����� ���� ������ü�� �����ϴ��� ã�´�.
	Object* pProtoObject = PrototypeObject->FindPrototypeObject(_Key);

	// ** ������ü�� ���ٸ�....
	if (pProtoObject == nullptr)
		return nullptr;
	// ** ���� ��ü�� �ִٸ�...
	else
	{
		// ** ������ü�� ���� �����Ѵ�.
		Object* pObject = pProtoObject->Clone();
		pObject->Initialize();
		pObject->SetPosition(_Position);

		return pObject;
	}
}

// ** Prototype ���� �� �۾�
void ObjectManager::FindObject(string _Key, Vector3 _Position)
{
	// ** DisableList�� �����Ϸ��� ������Ʈ�� �ִ��� Ȯ��.
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

	// ** ������.....
	if (iter == DisableList.end() || iter->second.empty())
	{
		Object* pObject = CreateObject(_Key, _Position);

		if (pObject == nullptr)
			return;

		// ** DisableList ����
		EnableList.push_back(pObject);
	}
	else
	{
		Object* pObject = iter->second.front();
		pObject->Initialize();
		pObject->SetPosition(_Position);

		// ** DisableList ����
		EnableList.push_back(pObject);

		iter->second.pop_front();
	}
}

void ObjectManager::AddObject(string _strKey)
{
	// ** Ű������ Ž���� Ž���� �Ϸ�� ������� ��ȯ.
	map<string, list<Object*>>::iterator Disableiter = DisableList.find(_strKey);

	for (int i = 0; i < 5; ++i)
	{
		//** Object ��ü�� ����. 
		Object* pObj = ObjectFactory<Enemy>::CreateObject();

		// ** ���� ������� �������� �ʴ´ٸ�....
		if (Disableiter == DisableList.end())
		{
			// ** ���ο� ����Ʈ�� ����.
			list<Object*> TempList;

			TempList.push_back(pObj);

			// ** ������Ʈ�� �߰��� ����Ʈ�� �ʿ� ����.
			DisableList.insert(make_pair(_strKey, TempList));
		}
		// ** ������� ���� �Ѵٸ�...
		else
			// ** �ش� ����Ʈ�� ������Ʈ�� �߰�
			Disableiter->second.push_back(pObj);
	}
}

void ObjectManager::RecallObject(Object* _Object)
{
	map<string, list<Object*>>::iterator iter = DisableList.find(_Object->GetKey());

	// ** ���� ������� �������� �ʴ´ٸ�....
	if (iter == DisableList.end())
	{
		// ** ���ο� ����Ʈ�� ����.
		list<Object*> TempList;

		TempList.push_back(_Object);

		// ** ������Ʈ�� �߰��� ����Ʈ�� �ʿ� ����.
		DisableList.insert(make_pair(_Object->GetKey(), TempList));
	}
	// ** ������� ���� �Ѵٸ�...
	else
		// ** �ش� ����Ʈ�� ������Ʈ�� �߰�
		iter->second.push_back(_Object);
}

void ObjectManager::Release()
{
	// ** ������ ����.
	::Safe_Delete(pPlayer);

	for (map<string, list<Object*>>::iterator iter = DisableList.begin();
		iter != DisableList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			::Safe_Delete((*iter2));
		}
		iter->second.clear();
	}
	DisableList.clear();

	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		::Safe_Delete((*iter));
	}
	EnableList.clear();
}
