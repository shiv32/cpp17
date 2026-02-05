#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <memory>
#include <limits>

using namespace std;

// ================= Receiver =================
class Playlist
{
    std::list<std::string> songs;
    std::list<std::string>::iterator current;

public:
    Playlist() : current(songs.end())
    {
    }

    void load(const std::string &file)
    {
        std::ifstream in(file);
        std::string s;

        while (getline(in, s))
        {
            songs.push_back(s);
        }

        if (!songs.empty())
            current = songs.begin();
    }

    void save(const std::string &file)
    {
        std::ofstream out(file);

        for (auto &s : songs)
            out << s << "\n";
    }

    void addSong(const std::string &s)
    {
        songs.push_back(s);

        if (songs.size() == 1)
            current = songs.begin();
    }

    void removeCurrent()
    {
        if (songs.empty())
            return;

        current = songs.erase(current);

        if (current == songs.end() && !songs.empty())
            current = songs.begin();
    }

    void play()
    {
        if (!songs.empty())
            std::cout << "Playing: " << *current << "\n";
    }

    void next()
    {
        if (songs.empty())
            return;

        ++current;

        if (current == songs.end())
            current = songs.begin();

        play();
    }

    void prev()
    {
        if (songs.empty())
            return;

        if (current == songs.begin())
            current = songs.end();

        --current;

        play();
    }
};

// ================= Command Interface =================
class Command
{
public:
    virtual void execute() = 0;
    virtual bool modifiesState() const { return false; }
    virtual ~Command() = default;
};

// ================= Concrete Commands =================
class AddCommand : public Command
{
    Playlist &playlist;
    std::string song;

public:
    AddCommand(Playlist &p, std::string s) : playlist(p), song(std::move(s))
    {
    }

    void execute() override
    {
        playlist.addSong(song);
    }

    bool modifiesState() const override
    {
        return true;
    }
};

class RemoveCommand : public Command
{
    Playlist &playlist;

public:
    RemoveCommand(Playlist &p) : playlist(p)
    {
    }

    void execute() override
    {
        playlist.removeCurrent();
    }

    bool modifiesState() const override
    {
        return true;
    }
};

class PlayCommand : public Command
{
    Playlist &playlist;

public:
    PlayCommand(Playlist &p) : playlist(p)
    {
    }

    void execute() override
    {
        playlist.play();
    }
};

class NextCommand : public Command
{
    Playlist &playlist;

public:
    NextCommand(Playlist &p) : playlist(p)
    {
    }
    
    void execute() override
    {
        playlist.next();
    }
};

class PrevCommand : public Command
{
    Playlist &playlist;

public:
    PrevCommand(Playlist &p) : playlist(p)
    {
    }

    void execute() override
    {
        playlist.prev();
    }
};

// ================= Invoker (UI) =================
int main()
{
    Playlist playlist;
    playlist.load("../Songs/playlist.txt");

    int choice;
    while (true)
    {
        std::cout << "\n1.Add  2.Remove  3.Play  4.Next  5.Prev  6.Exit\nChoice: ";
        std::cin >> choice;
        std::cin.ignore();
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::unique_ptr<Command> cmd;

        if (choice == 1)
        {
            std::string song;
            std::cout << "Song name: ";
            getline(std::cin, song);
            cmd = std::make_unique<AddCommand>(playlist, song);
        }
        else if (choice == 2)
        {
            cmd = std::make_unique<RemoveCommand>(playlist);
        }
        else if (choice == 3)
        {
            cmd = std::make_unique<PlayCommand>(playlist);
        }
        else if (choice == 4)
        {
            cmd = std::make_unique<NextCommand>(playlist);
        }
        else if (choice == 5)
        {
            cmd = std::make_unique<PrevCommand>(playlist);
        }
        else if (choice == 6)
            break;

        if (cmd)
        {
            cmd->execute();

            if (cmd->modifiesState())
                playlist.save("../Songs/playlist.txt");
            else
            {
                // clog<<"no file update needed."<<endl;
            }
        }
    }

    return EXIT_SUCCESS;
}
