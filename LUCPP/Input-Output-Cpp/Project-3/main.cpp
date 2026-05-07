#include <iostream>

#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#else
#include <unistd.h>
#include <locale>
#endif

using namespace std;

int main()
{

#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
#else
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    std::locale::global(std::locale(""));
#endif

    wcout << "Following characters are in Cyrillic" << endl;
    wcout << L"\x0411  \x0414  \x0416  \x0419  \x041B" << endl;

    wcout << "Following characters are in Devanagari" << endl;
    wcout << L"\x0905  \x0906  \x0907  \x0908  \x0909" << endl;

    return 0;
}