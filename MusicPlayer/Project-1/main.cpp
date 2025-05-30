#include <SFML/Audio.hpp>
#include <iostream>
#include <filesystem>
#include <vector>
#include <thread>
#include <atomic>

namespace fs = std::filesystem;

std::atomic<bool> running(true);
std::atomic<char> command('\0');

void input_thread() {
    while (running) {
        char c;
        std::cin >> c;
        command = c;
        if (c == 'q') {  // optional: stop input thread on 'q'
            running = false;
            break;
        }
    }
}

int main() {
    std::string musicDir = "../music";
    std::vector<fs::path> tracks;

    for (const auto& entry : fs::directory_iterator(musicDir)) {
        if (entry.path().extension() == ".wav") {
            tracks.push_back(entry.path());
        }
    }

    if (tracks.empty()) {
        std::cout << "No .wav files found in " << musicDir << "\n";
        return 1;
    }

    size_t index = 0;
    sf::Music music;
    std::thread input(input_thread);

    while (running) {
        std::cout << "Now Playing: " << tracks[index].filename() << "\n";

        if (!music.openFromFile(tracks[index].string())) {
            std::cerr << "Failed to open " << tracks[index] << "\n";
            continue;
        }

        music.play();

        bool track_stopped = false;
        while (!track_stopped && running) {
            char c = command.load();

            if (c == 'p') {
                music.pause();
                std::cout << "Paused\n";
                command = '\0';
            } else if (c == 'r') {
                music.play();
                std::cout << "Resumed\n";
                command = '\0';
            } else if (c == 's') {
                music.stop();
                std::cout << "Stopped\n";
                command = '\0';

                while (running) {
                    c = command.load();
                    if (c == 'r') {
                        music.play();
                        std::cout << "Resumed\n";
                        command = '\0';
                        break;
                    } else if (c == 'n') {
                        index = (index + 1) % tracks.size();
                        command = '\0';
                        track_stopped = true;
                        break;
                    } else if (c == 'q') {
                        running = false;
                        command = '\0';
                        track_stopped = true;
                        break;
                    }
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            } else if (c == 'n') {
                music.stop();
                index = (index + 1) % tracks.size();
                command = '\0';
                track_stopped = true;
            } else if (music.getStatus() == sf::SoundSource::Stopped) {
                index = (index + 1) % tracks.size();
                track_stopped = true;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    input.join();
    std::cout << "Exited cleanly.\n";

    return 0;
}
