#pragma once
#include <SFML/Audio.hpp>
#include <map>
#include <string>

class AudioManager
{
public:
    static AudioManager &getInstance();
    void loadSound(const std::string &name, const std::string &filename);
    void playSound(const std::string &name);

private:
    std::map<std::string, sf::SoundBuffer> buffers;
    std::map<std::string, sf::Sound> sounds;
    AudioManager() = default;
};
