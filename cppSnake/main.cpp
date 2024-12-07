// sudo apt-get install libncurses5-dev libncursesw5-dev
//  compile using g++ main.cpp -lncurses; then run ./a.out on terminal
//  the snake that gets 20 points first wins. If a snake eats itself or touches the boundary before that - the other snake wins.

#include <ncurses.h>
#include <cstdlib>

bool gameOver;
const int width = 20, height = 20;

int x, y, fruitX, fruitY, score;

#define SNAKE_GREEN 1
#define RED_FOOD 2
#define BLUE_BORDER 3

enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

const int maxSnakeLen = 100;
// think of each X & Y elem as linked to he corresponding element in Y/X
int tailX[maxSnakeLen], tailY[maxSnakeLen]; // this has to be an array and not a len - because he snake can curve
// to do: try using a queue? // no - becuase need to check for collisions with head;
// todo: dynamic array in C++? // no becuase dont want snake to not fit on board
int nTail = 0;

void Setup()
{

    // init screen
    initscr();
    clear();
    noecho(); // The echo and noecho routines control whether characters typed by the user are echoed by getch as they are typed
    cbreak();
    curs_set(0); // hide cursor

    if (has_colors() == true)
    {
        start_color();
        init_pair(SNAKE_GREEN, COLOR_GREEN, COLOR_WHITE);
        init_pair(RED_FOOD, COLOR_RED, COLOR_WHITE);
        init_pair(BLUE_BORDER, COLOR_BLUE, COLOR_WHITE);
    }

    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;

    // fruit must be located randomly on map
    fruitX = rand() % (width) + 1;
    fruitY = rand() % (height) + 1;

    // init score
    score = 0;
}

void Draw()
{
    clear();

    // board
    for (int i = 0; i < width + 2; i++)
    {
        // 0th a nd 1st arg are cooordinates
        attron(COLOR_PAIR(BLUE_BORDER));
        mvprintw(0, i, "+");
    }
    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            // creates boundary
            if (i == 0 || i == width + 1)
            {
                attron(COLOR_PAIR(BLUE_BORDER));
                mvprintw(i, j, "+");
            }
            else if (j == 0 || j == height + 1)
            {
                attron(COLOR_PAIR(BLUE_BORDER));
                mvprintw(i, j, "+");
            }

            // Snake head
            else if (i == y && j == x)
            {
                attron(COLOR_PAIR(SNAKE_GREEN));
                mvprintw(i, j, "O");
            }
            // fruit
            else if (i == fruitY && j == fruitX)
            {
                attron(COLOR_PAIR(RED_FOOD));
                mvprintw(i, j, "@");
            }
            // NOT HEAD - but still part of snake
            else
            {
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        attron(COLOR_PAIR(SNAKE_GREEN));
                        mvprintw(i, j, "o");
                    }
                }
            }
        }
    }
    // display score on bottom left
    attron(COLOR_PAIR(BLUE_BORDER));
    mvprintw(23, 0, "Score %d", score);

    // for debugg
    // display tail len on bottom left
    mvprintw(26, 0, "tail len %d", nTail);

    // refresh will display all of this
    refresh();
}

void Input()
{
    // how what you do affects things

    // NOTIFIES HAT IS IT KEYPAD INPUT
    keypad(stdscr, TRUE);

    // SNAKE KEEPS MOVING INTHA DIRECTION ONCE THE ARROW IS PRESSED (you dont have to keep pressing it)
    halfdelay(1);

    int c = getch(); // get char

    switch (c)
    {
    case KEY_LEFT:
        dir = LEFT;
        break;
    case KEY_RIGHT:
        dir = RIGHT;
        break;
    case KEY_UP:
        dir = UP;
        break;
    case KEY_DOWN:
        dir = DOWN;
        break;
    case 113: // user presses q to quit
        gameOver = true;
        break;
    }
}

void PrintWithColor()
{
    if (has_colors() == FALSE)
    {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
}

void Logic()
{
    // we are manually moving each segment of the snake to the next positon
    // potenital optimization - just change the last piece

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    // for changing direction
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        // user does nothing
        break;
    }

    if (x > width || x < 1 || y > height || y < 1)
    {
        gameOver = true;
    }

    // if you get a fruit
    if (x == fruitX && y == fruitY)
    {
        score++;
        // fruit position must change
        fruitX = rand() % (width) + 1;
        fruitY = rand() % (height) + 1;

        // increment tail
        nTail++;
    }

    // go through each tail piece and see if it is the same as head - collisiion check
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
        }
    }
}

int main()
{
    Setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }

    getch();
    endwin();
}