#pragma once
#include "Headers.h"
#include "Include.h"



class SoundManager
{
private:
	static SoundManager* Instance;
public:
	static SoundManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SoundManager;
		return Instance;
	}
private:
	FMOD::System* m_pSystem;
	map<string, SOUNDINFO*> SoundList;
	bool		Playing = false;
	float		Volume;
public:
	void Initialize();
	void LoadSoundDate(const char* _FileName, string _Key);
	void StramingUpdate();
	void OnPlaySound(string _Key);
	void OnPlaySoundDot(string _Key);
	void StopSound(string _Key);
	void Release();

	void VolumeUp();
	void VolumeDown();
private:
	SoundManager() { }
public:
	~SoundManager() { Release(); }
};

