#include "ObjectManager.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = nullptr;


void ObjectManager::AddObject(Object* _Object)
{
	// ** Ű������ Ž���� Ž���� �Ϸ�� ������� ��ȯ.
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object->GetKey());

	// ** ���� ������� �������� �ʴ´ٸ�....
	if (iter == ObjectList.end())
	{
		// ** ���ο� ����Ʈ�� ����.
		list<Object*> TempList;

		// ** ������ ����Ʈ�� �ش� ������Ʈ�� �߰�.
		TempList.push_back(_Object);

		// ** ������Ʈ�� �߰��� ����Ʈ�� �ʿ� ����.
		ObjectList.insert(make_pair(_Object->GetKey(), TempList));
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

	for (map<string, list<Object*>>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			::Safe_Delete((*iter2));
		}
		iter->second.clear();
	}
	ObjectList.clear();
}
