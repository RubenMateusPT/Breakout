#pragma once
#include <queue>
#include <stack>
#include <vector>
#include <SFML/Audio.hpp>

class AudioManager
{
    //Singleton
private:
    static AudioManager* _instance;
    
    AudioManager();
    ~AudioManager();

public:
    static AudioManager& getInstance();

    //Object Pooling for SFX
private:
    std::vector<std::string> musicFiles;
    sf::Music* musicPlayer;

    const int STARTING_SFX_OBJECTS = 0;
    std::vector<sf::SoundBuffer*> sfxFiles;
    std::vector<sf::Sound*> sfxPlayers;
    
public:
    //Music Controller
    int addMusicFile(std::string fileName);
    void playMusic(int index, bool loopMusic);

    //SFX Controller
    int addSoundFile(std::string fileName);
    void playSound(int index);
};
