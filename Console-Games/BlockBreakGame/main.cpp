// sudo apt-get install libncurses5-dev libncursesw5-dev
//  compile using g++ main.cpp -lncurses; then run ./a.out on terminal

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <ncurses.h> // Required for smooth keyboard input

using namespace std;

const int WIDTH = 30;
const int HEIGHT = 20;

// Ball properties
int ballX = WIDTH / 2, ballY = HEIGHT - 5;
int ballDirX = 1, ballDirY = -1;

// Paddle properties
int paddleX = WIDTH / 2 - 3;
const int paddleWidth = 6;

// Blocks
vector<pair<int, int>> blocks;

// Initialize ncurses
void initScreen() {
    initscr();           // Start ncurses mode
    noecho();            // Don't show keypresses
    curs_set(0);         // Hide cursor
    keypad(stdscr, TRUE); // Enable arrow keys
    nodelay(stdscr, TRUE); // Make getch() non-blocking
}

// Initialize the game
void initializeGame() {
    for (int i = 2; i < 6; ++i) {
        for (int j = 2; j < WIDTH - 2; j += 4) {
            blocks.push_back({i, j});
        }
    }
}

// Draw the game screen
void drawGame() {
    clear();  // Clear screen before drawing

    // Draw blocks
    for (auto &block : blocks) {
        mvprintw(block.first, block.second, "#");
    }

    // Draw ball
    mvprintw(ballY, ballX, "O");

    // Draw paddle
    for (int i = 0; i < paddleWidth; ++i)
        mvprintw(HEIGHT - 2, paddleX + i, "=");

    // Draw borders
    for (int i = 0; i < WIDTH; ++i) {
        mvprintw(0, i, "*"); // Top border
        mvprintw(HEIGHT - 1, i, "*"); // Bottom border
    }
    for (int i = 0; i < HEIGHT; ++i) {
        mvprintw(i, 0, "*");  // Left border
        mvprintw(i, WIDTH - 1, "*");  // Right border
    }

    refresh();  // Refresh the screen
}

// Update the game state
void updateGame() {
    ballX += ballDirX;
    ballY += ballDirY;

    // Ball collision with walls
    if (ballX <= 1 || ballX >= WIDTH - 2) ballDirX *= -1;
    if (ballY <= 1) ballDirY *= -1;

    // Ball collision with paddle
    if (ballY == HEIGHT - 3 && ballX >= paddleX && ballX < paddleX + paddleWidth) {
        ballDirY *= -1;
    }

    // Ball collision with blocks
    for (size_t i = 0; i < blocks.size(); ++i) {
        if (ballY == blocks[i].first && ballX == blocks[i].second) {
            blocks.erase(blocks.begin() + i);
            ballDirY *= -1;
            break;
        }
    }

    // Game over if the ball falls below the paddle
    if (ballY >= HEIGHT - 1) {
        clear();
        mvprintw(HEIGHT / 2, WIDTH / 2 - 5, "Game Over!");
        refresh();
        this_thread::sleep_for(chrono::seconds(2));
        endwin();
        exit(0);
    }
}

// Handle paddle movement
void movePaddle() {
    int ch = getch();
    if (ch == 'a' && paddleX > 1) paddleX -= 2;
    if (ch == 'd' && paddleX < WIDTH - paddleWidth - 1) paddleX += 2;
}

// Game loop
void gameLoop() {
    while (true) {
        drawGame();
        movePaddle();
        updateGame();
        this_thread::sleep_for(chrono::milliseconds(200)); // Faster loop for smoother gameplay
    }
}

int main() {
    initScreen();
    initializeGame();
    gameLoop();
    endwin(); // Restore normal terminal settings
    return 0;
}
