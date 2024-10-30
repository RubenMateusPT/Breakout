#include "AudioManager.h"

#include <iostream>
#include <ostream>

AudioManager::AudioManager()
{
    if(_instance)
    {
        std::cout << "Error: Instance already exists" << std::endl;
    }
    else
    {
        musicPlayer = new sf::Music();
        
        for (int i = 0; i < STARTING_SFX_OBJECTS; ++i)
        {
            sfxPlayers.emplace_back(new sf::Sound());
        }
    }
}

AudioManager::~AudioManager()
{
    std::cout << "Destroying Singleton Instance of AudioManager" << std::endl;

    if(musicPlayer->getStatus() == sf::Sound::Playing)
    {
        musicPlayer->stop();
    }
    delete musicPlayer;

    for (int i = 0; i < sfxPlayers.size(); i++)
    {
        delete sfxPlayers[i];
    }
    sfxPlayers.clear();
}

AudioManager& AudioManager::getInstance()
{
    if(!_instance)
    {
        _instance = new AudioManager();
    }

    return *_instance;
}

//Music Controls
int AudioManager::addMusicFile(std::string fileName)
{
    musicFiles.push_back(fileName);
    return (musicFiles.size() - 1);
}

void AudioManager::playMusic(int index, bool loopMusic)
{
    musicPlayer->stop();
    
    auto result = musicPlayer->openFromFile(musicFiles[index]);
    if(result == false)
    {
        std::cout << "ERROR: File is invalid" << std::endl;
        return;
    }
    
    musicPlayer->setLoop(loopMusic);
    
    musicPlayer->play();
}



//SFX Controls
int AudioManager::addSoundFile(std::string fileName)
{
    sf::SoundBuffer* soundFile = new sf::SoundBuffer();
    auto result = soundFile->loadFromFile(fileName);

    if(result == false)
    {
        std::cout << "ERROR: File is invalid" << std::endl;
        return -1; //Flags that there was an error adding sound to memory
    }

    sfxFiles.push_back(soundFile);
    return (sfxFiles.size() - 1);
}

void AudioManager::playSound(int index)
{
    sf::Sound* sfxPlayer = nullptr;

    for(int i = 0; i < sfxPlayers.size(); i++)
    {
        auto candidate = sfxPlayers[i];
        if(candidate->getStatus() == sf::Sound::Stopped)
        {
            sfxPlayer = candidate;
            break;
        }
    }
    
    if(sfxPlayer == nullptr)
    {
        sfxPlayer = new sf::Sound();
        sfxPlayers.push_back(sfxPlayer);
    }

    sfxPlayer->setBuffer(*sfxFiles[index]);
    sfxPlayer->setLoop(false);
    sfxPlayer->play();
}


