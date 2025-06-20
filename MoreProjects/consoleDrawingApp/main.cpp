#include <ncurses.h>

const int WIDTH = 40;
const int HEIGHT = 20;

char canvas[HEIGHT][WIDTH];  // Drawing grid
int cursorX = 0, cursorY = 0;

void drawCanvas() {
    clear();
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (y == cursorY && x == cursorX)
                attron(A_REVERSE);  // Highlight cursor
            addch(canvas[y][x] ? canvas[y][x] : '.');
            if (y == cursorY && x == cursorX)
                attroff(A_REVERSE);
        }
        printw("\n");
    }
    refresh();
}

int main() {
    initscr();            // Start ncurses mode
    keypad(stdscr, TRUE); // Enable arrow keys
    noecho();             // Don't show typed characters
    curs_set(0);          // Hide blinking cursor

    bool running = true;
    while (running) {
        drawCanvas();

        int ch = getch();
        switch (ch) {
            case KEY_UP:
                if (cursorY > 0) cursorY--;
                break;
            case KEY_DOWN:
                if (cursorY < HEIGHT - 1) cursorY++;
                break;
            case KEY_LEFT:
                if (cursorX > 0) cursorX--;
                break;
            case KEY_RIGHT:
                if (cursorX < WIDTH - 1) cursorX++;
                break;
            case ' ':  // Draw at position
                canvas[cursorY][cursorX] = '*';
                break;
            case 'c':  // Clear canvas
                for (int y = 0; y < HEIGHT; ++y)
                    for (int x = 0; x < WIDTH; ++x)
                        canvas[y][x] = 0;
                break;
            case 'q':  // Quit
                running = false;
                break;
        }
    }

    endwin();  // End ncurses mode
    return 0;
}
