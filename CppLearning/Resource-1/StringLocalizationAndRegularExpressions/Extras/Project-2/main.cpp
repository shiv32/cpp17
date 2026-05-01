#include <iostream>
#include <locale>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // std::locale locUSEng("en-US");//window
    std::locale locUSEng("en_US"); // linux
    // locale locBritEng("en-GB"); //window
    std::locale locBritEng("en_GB"); // linux

    std::wstring dollars = std::use_facet<std::moneypunct<wchar_t>>(locUSEng).curr_symbol();
    std::wstring pounds = std::use_facet<std::moneypunct<wchar_t>>(locBritEng).curr_symbol();

    std::wcout << L"In the US, the currency symbol is " << dollars << std::endl;
    std::wcout << L"In Great Britain, the currency symbol is " << pounds << std::endl;

    return 0;
}