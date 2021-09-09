#pragma once
#include "Headers.h"

class Scene;
class SceneManager
{
private:
	static SceneManager* Instance;
public:
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SceneManager;

		return Instance;
	}
private:
	Scene* pSceneState;
public:
	void SetScene(SCENEID _SceneID);
	void Update();
	void Render(HDC _hdc);
	void Release();
private:
	SceneManager() : pSceneState(nullptr) {}
public:
	~SceneManager() { Release(); }
};

