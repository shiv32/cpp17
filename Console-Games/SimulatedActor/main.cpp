#include <iostream>
using namespace std;

class Actor
{
public:
    float x = 0, y = 0;

    void move(float dx, float dy)
    {
        x += dx;
        y += dy;

        cout << "Moved to (" << x << ", " << y << ")\n";
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    cout << "Game Started : (press w/a/s/d to move)\n";

    Actor player;

    char command;

    while (cin >> command)
    {
        if (command == 'w')
            player.move(0, 1);
        else if (command == 's')
            player.move(0, -1);
        else if (command == 'a')
            player.move(-1, 0);
        else if (command == 'd')
            player.move(1, 0);
        else
            break;
    }
}
