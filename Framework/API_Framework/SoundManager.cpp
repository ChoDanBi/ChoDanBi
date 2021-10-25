#include "SoundManager.h"

SoundManager* SoundManager::Instance = nullptr;


void SoundManager::Initialize()
{
	// ** FMOD를 생성.
	FMOD::System_Create(&m_pSystem);

	// ** 32개의 채널을 갖겠다.
	if (FMOD_OK != m_pSystem->init(32, FMOD_INIT_NORMAL, nullptr))
	{
		cout << "Initialization Error." << endl;
		return;
	}
}

void SoundManager::LoadSoundDate(const char* _FileName, string _Key)
{
	SOUNDINFO* SoundInfo = new SOUNDINFO;

	if (FMOD_OK != m_pSystem->createSound(_FileName, FMOD_LOOP_OFF, 0, &SoundInfo->SoundObj))
	{
		cout << "Date Load Error!!" << endl;
		return;
	}

	SoundInfo->ChannelID = 0;
	SoundInfo->SoundObj->setMusicChannelVolume(SoundInfo->ChannelID, 0.5f);

	SoundList.insert(make_pair(_Key, SoundInfo));
}

void SoundManager::StramingUpdate()
{
	m_pSystem->update();
}

void SoundManager::OnPlaySound(string _Key)
{
	// ** 사운드를 찾는다.
	map<string, SOUNDINFO*>::iterator iter = SoundList.find(_Key);

	// ** 만약에 찾는 사운드가 없다면...
	if (iter == SoundList.end())
	{
		// ** 사운드 데이터가 없다는 메시지를 띄운후 종료시킴..
		cout << "Sound date does not exits." << endl;
		return;
	}

	// ** 사운드를 재생 시킴..
	if (FMOD_OK != m_pSystem->playSound(iter->second->SoundObj, 0, false, &iter->second->SoundChannel))
	{
		cout << "문제가 생겼습니다." << endl;
		return;
	}
}

void SoundManager::Release()
{
	for (map<string, SOUNDINFO*>::iterator iter = SoundList.begin();
		iter != SoundList.end(); ++iter)
	{
		iter->second->SoundObj->release();
		iter = SoundList.erase(iter);
	}
	SoundList.clear();
}

void SoundManager::VolumeUp()
{
	if (Volume < SOUND_VOLUME_MAX)
	{
		Volume += SOUND_VOLUME;

		for (map<string, SOUNDINFO*>::iterator iter = SoundList.begin();
			iter != SoundList.end(); ++iter)
		{
			iter->second->SoundChannel->setVolume(Volume);
		}
	}
}

void SoundManager::VolumeDown()
{
	if (Volume > SOUND_VOLUME_MIN)
	{
		Volume -= SOUND_VOLUME;

		for (map<string, SOUNDINFO*>::iterator iter = SoundList.begin();
			iter != SoundList.end(); ++iter)
		{
			iter->second->SoundChannel->setVolume(Volume);
		}
	}
}
