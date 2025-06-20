#include <ncurses.h>
#include <string>

class NcursesApp
{
public:
    NcursesApp()
    {
        initscr();            // Start curses mode
        cbreak();             // Line buffering disabled
        noecho();             // Don't echo() while we do getch
        keypad(stdscr, TRUE); // Enable F1, F2 etc.
    }

    ~NcursesApp()
    {
        endwin(); // End curses mode
    }

    void drawText(int y, int x, const std::string &text)
    {
        mvprintw(y, x, "%s", text.c_str());
        refresh();
    }

    int waitKey()
    {
        return getch(); // Wait for user input
    }

private:
    // You could add more state here if needed
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    NcursesApp app;

    app.drawText(5, 10, "Hello from C++ ncurses wrapper!");
    app.drawText(7, 10, "Press any key to exit...");

    app.waitKey();

    return 0;
}
