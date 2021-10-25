#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "SoundManager.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Release();
}


void MainUpdate::Initialize()
{
	m_hdc = GetDC(g_hWnd);
	SoundManager::GetInstance()->Initialize();
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/Hit by jeckkech Id-391668.wav", "Hit");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/«ì«Ù«ë«¢«Ã«×.mp3", "Clear");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/á³«­«Ã«¯.mp3", "Crash");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/bensound-funnysong.mp3", "Stage");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/bensound-inspire.mp3", "Wait");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/bensound-clearday.mp3", "Ending");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/bensound-evolution.mp3", "Boss");
	SoundManager::GetInstance()->LoadSoundDate("../Resource/Sound/Ì½ïÒ¡¢«Ü«¿«óäãù»46.mp3", "Buy");

	SceneManager::GetInstance()->SetScene(SCENEID::LOGO);
}

void MainUpdate::Update()
{
	SceneManager::GetInstance()->Update();

	InputManager::GetInstance()->CheckKey();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render(m_hdc);
}

void MainUpdate::Release()
{
	
}
