#include <iostream>
#include <string>
#include <array>
#include <cstdio>
#include <thread>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <signal.h>

#include <vector>
#include <memory>
#include <cstdlib>

pid_t inhibitor_pid = -1;

void inhibit()
{
    if (inhibitor_pid > 0)
        return; // already running
    inhibitor_pid = fork();
    if (inhibitor_pid == 0)
    {
        execlp("systemd-inhibit", "systemd-inhibit",
               "--what=handle-lid-switch:sleep",
               "--who=caffeine-cli",
               "--why=Preventing sleep",
               "sleep", "infinity",
               (char *)nullptr);
        _exit(1);
    }
    std::cout << "[ACTION] >>> Started systemd-inhibit\n";
}

void uninhibit()
{
    if (inhibitor_pid > 0)
    {
        kill(inhibitor_pid, SIGTERM);
        inhibitor_pid = -1;
        std::cout << "[ACTION] <<< Stopped systemd-inhibit\n";
    }
}

std::string execCmd(const std::string &cmd)
{
    std::array<char, 256> buffer{};
    std::string result;
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe)
        return "";
    while (fgets(buffer.data(), buffer.size(), pipe))
        result += buffer.data();
    pclose(pipe);
    return result;
}

// Return a list of active MPRIS player bus names
std::vector<std::string> listMprisPlayers()
{
    std::vector<std::string> players;
    std::string cmd = "dbus-send --session --dest=org.freedesktop.DBus "
                      "--type=method_call --print-reply /org/freedesktop/DBus "
                      "org.freedesktop.DBus.ListNames";
    std::string out = execCmd(cmd);
    std::istringstream iss(out);
    std::string line;
    while (std::getline(iss, line))
    {
        auto pos = line.find("string \"org.mpris.MediaPlayer2.");
        if (pos != std::string::npos)
        {
            auto start = line.find("\"") + 1;
            auto end = line.find_last_of("\"");
            players.push_back(line.substr(start, end - start));
        }
    }
    return players;
}

// Check if a player is in "Playing" state
bool isPlayerPlaying(const std::string &player)
{
    std::string cmd = "dbus-send --session --print-reply "
                      "--dest=" +
                      player + " "
                               "/org/mpris/MediaPlayer2 org.freedesktop.DBus.Properties.Get "
                               "string:'org.mpris.MediaPlayer2.Player' string:'PlaybackStatus'";
    std::string out = execCmd(cmd);
    return out.find("string \"Playing\"") != std::string::npos;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    std::cout << "Caffeine-CLI"<< "\n";

    while (true)
    {
        auto players = listMprisPlayers();
        bool anyPlaying = false;

        for (auto &p : players)
        {
            if (isPlayerPlaying(p))
            {
               // std::cout << "[INFO] Playing: " << p << "\n";
                anyPlaying = true;
                inhibit();
            }
        }

        if (!anyPlaying)
        {
            //std::cout << "[INFO] No video/audio playback detected.\n";
            uninhibit();
        }
    }
    return 0;
}
