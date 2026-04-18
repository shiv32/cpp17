#include <iostream>
using namespace std;

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    char ch;
    cout << endl
         << "Enter a character:";

    cin.get(ch); // Extract one character into ch

    cout << ch;

    cin.putback(ch); // Insert last character read, back into input stream

    cin.get(ch); // Extract one character into ch

    cout << endl
         << ch;

    // Return number of character read by a (immediately preceding)call to get(), getline(), or read()
    int count = cin.gcount();
    cout << endl
         << "Character extraxted in last get()=" << count;

    // stuff stream with a Z
    cin.putback('Z'); // Insert Z, back into input stream

    ch = cin.peek(); // Reads one character, leaves it in stream

    cout << endl
         << ch;

    // Z is still in stream
    cin.get(ch); // Extract one character into ch

    cout << endl
         << ch << endl;

    return EXIT_SUCCESS;
}
