#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ===================== Direction =====================

enum class Direction
{
    Up,
    Down,
    Left,
    Right
};

// ===================== Entities =====================

struct Bullet
{
    int x, y;
    Direction dir;

    Bullet(int x_, int y_, Direction d)
        : x(x_), y(y_), dir(d) {}
};

struct Tank
{
    int x, y;
    Direction dir = Direction::Up;

    Tank(int x_, int y_) : x(x_), y(y_) {}

    void fire(vector<Bullet> &bullets)
    {
        bullets.emplace_back(x, y, dir);
    }
};

struct Enemy
{
    int x, y;
    bool alive = true;
};

// ===================== Strategy Pattern =====================

struct MoveStrategy
{
    virtual void move(Tank &, int w, int h) = 0;
    virtual ~MoveStrategy() = default;
};

struct MoveUp : MoveStrategy
{
    void move(Tank &t, int, int) override
    {
        if (t.y > 1)
            t.y--;
        t.dir = Direction::Up;
    }
};

struct MoveDown : MoveStrategy
{
    void move(Tank &t, int, int h) override
    {
        if (t.y < h - 2)
            t.y++;
        t.dir = Direction::Down;
    }
};

struct MoveLeft : MoveStrategy
{
    void move(Tank &t, int, int) override
    {
        if (t.x > 1)
            t.x--;
        t.dir = Direction::Left;
    }
};

struct MoveRight : MoveStrategy
{
    void move(Tank &t, int w, int) override
    {
        if (t.x < w - 2)
            t.x++;
        t.dir = Direction::Right;
    }
};

// ===================== Game Engine =====================

class GameEngine
{
    const int width = 25;
    const int height = 12;

    bool running = true;

    Tank player{width / 2, height - 2};
    Enemy enemy{width / 2, 2};

    vector<Bullet> bullets;
    vector<string> levelMap;

    MoveUp up;
    MoveDown down;
    MoveLeft left;
    MoveRight right;

public:
    GameEngine()
    {
        levelMap.resize(height, string(width, '.'));
    }

    void run()
    {
        while (running)
        {
            render();
            input();
            update();
        }
    }

private:
    void input()
    {
        char ch;
        cin >> ch;

        if (ch == 'w')
            up.move(player, width, height);
        else if (ch == 's')
            down.move(player, width, height);
        else if (ch == 'a')
            left.move(player, width, height);
        else if (ch == 'd')
            right.move(player, width, height);
        else if (ch == 'f')
            player.fire(bullets);
        else if (ch == 'q')
            running = false;
    }

    void update()
    {
        // Move bullets
        for (auto &b : bullets)
        {
            switch (b.dir)
            {
            case Direction::Up:
                b.y--;
                break;
            case Direction::Down:
                b.y++;
                break;
            case Direction::Left:
                b.x--;
                break;
            case Direction::Right:
                b.x++;
                break;
            }
        }

        // Bullet vs enemy
        for (auto &b : bullets)
        {
            if (enemy.alive && b.x == enemy.x && b.y == enemy.y)
            {
                enemy.alive = false;
            }
        }

        // Remove offscreen bullets
        bullets.erase(
            remove_if(bullets.begin(), bullets.end(),
                      [&](const Bullet &b)
                      {
                          return b.x < 0 || b.x >= width ||
                                 b.y < 0 || b.y >= height;
                      }),
            bullets.end());
    }

    void render()
    {
        system("clear"); // Linux/macOS
        // system("cls"); // Windows

        for (auto &row : levelMap)
            row.assign(width, '.');

        levelMap[player.y][player.x] = 'P';

        if (enemy.alive)
            levelMap[enemy.y][enemy.x] = 'E';

        for (auto &b : bullets)
            levelMap[b.y][b.x] = '*';

        for (auto &row : levelMap)
            cout << row << '\n';

        cout << "\n[w a s d] Move  [f] Fire  [q] Quit\n";
    }
};

// ===================== main =====================

int main()
{
    GameEngine game;
    game.run();
    return 0;
}
