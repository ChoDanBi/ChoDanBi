#pragma once


// ** Sound
#pragma comment(lib, "fmod_vc.lib")
#include <fmod.hpp>

using namespace FMOD;

typedef struct tagSoundInfo
{
	FMOD::Sound* SoundObj;
	FMOD::Channel* SoundChannel;
	int ChannelID;

}SOUNDINFO;