#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

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
    bool fromEnemy;
};

struct Tank
{
    int x, y;
    Direction dir = Direction::Up;
    bool alive = true;

    void fire(vector<Bullet> &bullets, bool enemy = false)
    {
        bullets.push_back({x, y, dir, enemy});
    }
};

struct Enemy
{
    Tank tank;
};

// ===================== Strategy =====================
struct MoveStrategy
{
    virtual void move(Tank &, int, int) = 0;
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
    const int width = 30;
    const int height = 15;

    Tank player{width / 2, height - 2};
    vector<Enemy> enemies;
    vector<Bullet> bullets;

    vector<string> map;
    bool running = true;
    bool win = false;

    MoveUp up;
    MoveDown down;
    MoveLeft left;
    MoveRight right;

public:
    GameEngine()
    {
        srand(time(nullptr));
        map.resize(height, string(width, '.'));

        // Hidden enemy spawn (top area)
        for (int i = 0; i < 3; ++i)
        {
            enemies.push_back({Tank{2 + rand() % (width - 4), 1}});
        }
    }

    void run()
    {
        while (running)
        {
            render();
            input();
            update();
        }
        render();
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
        enemyAI();
        moveBullets();
        checkCollisions();
        checkGameState();
    }

    void enemyAI()
    {
        for (auto &e : enemies)
        {
            if (!e.tank.alive)
                continue;

            int r = rand() % 10;
            if (r < 2)
                up.move(e.tank, width, height);
            else if (r < 4)
                down.move(e.tank, width, height);
            else if (r < 6)
                left.move(e.tank, width, height);
            else if (r < 8)
                right.move(e.tank, width, height);
            else
                e.tank.fire(bullets, true);
        }
    }

    void moveBullets()
    {
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

        bullets.erase(remove_if(bullets.begin(), bullets.end(),
                                [&](const Bullet &b)
                                {
                                    return b.x < 0 || b.x >= width || b.y < 0 || b.y >= height;
                                }),
                      bullets.end());
    }

    void checkCollisions()
    {
        for (auto &b : bullets)
        {
            if (!b.fromEnemy && b.x == player.x && b.y == player.y)
                continue;

            for (auto &e : enemies)
            {
                if (e.tank.alive && !b.fromEnemy &&
                    b.x == e.tank.x && b.y == e.tank.y)
                {
                    e.tank.alive = false;
                }
            }

            if (b.fromEnemy &&
                b.x == player.x && b.y == player.y)
            {
                player.alive = false;
            }
        }
    }

    void checkGameState()
    {
        if (!player.alive)
        {
            running = false;
            win = false;
        }

        if (all_of(enemies.begin(), enemies.end(),
                   [](const Enemy &e)
                   { return !e.tank.alive; }))
        {
            running = false;
            win = true;
        }
    }

    void render()
    {
        system("clear"); // Linux/macOS
        // system("cls"); // Windows

        for (auto &row : map)
            row.assign(width, '.');

        if (player.alive)
            map[player.y][player.x] = 'P';

        for (auto &e : enemies)
            if (e.tank.alive)
                map[e.tank.y][e.tank.x] = 'E';

        for (auto &b : bullets)
            map[b.y][b.x] = '*';

        for (auto &row : map)
            cout << row << '\n';

        if (!running)
        {
            cout << "\n=====================\n";
            cout << (win ? " YOU WIN! " : " GAME OVER ");
            cout << "\n=====================\n";
        }
        else
        {
            cout << "\n[w a s d] Move  [f] Fire  [q] Quit\n";
        }
    }
};

// ===================== main =====================
int main()
{
    GameEngine game;
    game.run();
    return 0;
}
