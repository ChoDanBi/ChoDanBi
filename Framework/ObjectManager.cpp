#include "ObjectManager.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = nullptr;


void ObjectManager::AddObject(Object* _Object)
{
	// ** 키값으로 탐색후 탐색이 완료된 결과물을 반환.
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object->GetKey());

	// ** 만약 결과물이 존재하지 않는다면....
	if (iter == ObjectList.end())
	{
		// ** 새로운 리스트를 생성.
		list<Object*> TempList;

		// ** 생성된 리스트에 해당 오브젝트를 추가.
		TempList.push_back(_Object);

		// ** 오브젝트가 추가된 리스트를 맵에 삽입.
		ObjectList.insert(make_pair(_Object->GetKey(), TempList));
	}
	// ** 결과물이 존재 한다면...
	else
		// ** 해당 리스트에 오브젝트를 추가
		iter->second.push_back(_Object);
}

void ObjectManager::Release()
{
	// ** 안전한 삭제.
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
