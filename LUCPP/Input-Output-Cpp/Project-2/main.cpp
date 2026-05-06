#include <iostream>

using namespace std;

int main()
{
     system("clear && printf '\e[3J'"); // clean the terminal before output in linux
     
     int ch = 90;

     cout << char(65) << endl;
     cout << char(90) << endl;

     char str[] = "Hello World";
     const char *ptr = "Hello 2";

     cout << str << endl;
     cout << ptr << endl;

     cout << static_cast<void *>(str) << endl;
     cout << static_cast<const void *>(ptr) << endl;

     return 0;
}