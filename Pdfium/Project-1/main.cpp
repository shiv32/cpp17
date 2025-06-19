#include <fpdfview.h>
#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    FPDF_InitLibrary();

    FPDF_DOCUMENT doc = FPDF_LoadDocument("../sample.pdf", nullptr);

    if (!doc)
    {
        std::cerr << "Failed to open PDF\n";
        return 1;
    }

    std::cout << "Page count: " << FPDF_GetPageCount(doc) << std::endl;

    FPDF_CloseDocument(doc);
    FPDF_DestroyLibrary();

    return 0;
}
