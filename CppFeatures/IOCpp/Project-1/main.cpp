#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdio> // C-style I/O

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // ================================
    // 1. BASIC OUTPUT (cout, cerr, clog)
    // ================================
    std::cout << "cout: Normal output\n";
    std::cerr << "cerr: Error output (unbuffered)\n";
    std::clog << "clog: Log output (buffered)\n";

    // ================================
    // 2. BASIC INPUT (cin)
    // ================================
    int num;
    std::cout << "\nEnter an integer: ";
    std::cin >> num;
    std::cout << "You entered: " << num << "\n";

    // ================================
    // 3. LINE INPUT (getline)
    // ================================
    std::cin.ignore(); // clear leftover newline
    std::string line;
    std::cout << "Enter a full line: ";
    std::getline(std::cin, line);
    std::cout << "Line: " << line << "\n";

    // ================================
    // 4. UNFORMATTED INPUT
    // ================================
    std::cout << "\nPress any character: ";
    char ch = std::cin.get(); // read single char
    std::cout << "You pressed: " << ch << "\n";

    // peek next char (does not extract)
    std::cout << "Next char in buffer (peek): " << (char)std::cin.peek() << "\n";

    // ignore next character
    std::cin.ignore(1);

    // ================================
    // 5. UNFORMATTED OUTPUT
    // ================================
    std::cout.put('A'); // write single char
    std::cout << " <- printed using put()\n";

    const char *msg = "HelloBuffer";
    std::cout.write(msg, 5); // write first 5 chars
    std::cout << " <- printed using write()\n";

    std::cout.flush(); // force flush

    // ================================
    // 6. STRING STREAM (stringstream)
    // ================================
    std::stringstream ss;
    ss << "100 200";
    int a, b;
    ss >> a >> b;
    std::cout << "Parsed from stringstream: " << a << ", " << b << "\n";

    // ================================
    // 7. FORMATTING (iomanip)
    // ================================
    double pi = 3.1415926535;
    std::cout << "Default: " << pi << "\n";
    std::cout << "Fixed (2 decimal): " << std::fixed << std::setprecision(2) << pi << "\n";
    std::cout << "Width(10): [" << std::setw(10) << 42 << "]\n";

    // ================================
    // 8. C-STYLE OUTPUT
    // ================================
    printf("\nprintf: Value = %d\n", 123);
    puts("puts: prints string");
    putchar('Z');
    putchar('\n');

    // ================================
    // 9. C-STYLE INPUT
    // ================================
    int x;
    printf("Enter number (scanf): ");
    scanf("%d", &x);
    printf("You entered (scanf): %d\n", x);

    printf("Press a key (getchar): ");
    getchar(); // consume leftover newline
    char c = getchar();
    printf("You pressed: %c\n", c);

    // ================================
    // 10. FAST I/O SETTINGS
    // ================================
    std::ios::sync_with_stdio(false); // disable sync with C I/O
    std::cin.tie(nullptr);            // untie cin from cout

    // ================================
    // 11. CONSOLE CONTROL (UI tricks)
    // ================================
    std::cout << "\nUpdating line...";
    std::cout << "\rOverwritten line using carriage return\n";

    // ================================
    // 12. BUFFER ACCESS (advanced)
    // ================================
    std::streambuf *buf = std::cin.rdbuf();
    std::cout << "Accessed cin buffer (rdbuf)\n";

    // ================================
    // 13. WIDE CHARACTER I/O
    // ================================
    std::wcout << L"Wide output (wcout)\n";

    return 0;
}