/**
Here’s a minimal C++17 program that detects if video/audio is playing in a browser (via MPRIS) or VLC.
This uses MPRIS over D-Bus (the same mechanism caffeine‑ng and playerctl use).
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <memory>
#include <sstream>
#include <cstdlib>

// Helper to run a command and capture output
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
    auto players = listMprisPlayers();
    bool anyPlaying = false;

    for (auto &p : players)
    {
        if (isPlayerPlaying(p))
        {
            std::cout << "[INFO] Playing: " << p << "\n";
            anyPlaying = true;
        }
    }

    if (!anyPlaying)
        std::cout << "[INFO] No video/audio playback detected.\n";

    return 0;
}
