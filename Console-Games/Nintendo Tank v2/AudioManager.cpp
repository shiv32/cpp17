#include "AudioManager.hpp"

AudioManager &AudioManager::getInstance()
{
    static AudioManager instance;
    return instance;
}

void AudioManager::loadSound(const std::string &name, const std::string &filename)
{
    sf::SoundBuffer buffer;
    if (buffer.loadFromFile(filename))
    {
        buffers[name] = buffer;
        sounds[name].setBuffer(buffers[name]);
    }
}

void AudioManager::playSound(const std::string &name)
{
    if (buffers.count(name))
    {
        sounds[name].play();
    }
}
