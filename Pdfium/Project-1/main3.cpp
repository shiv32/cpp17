/**
 * @file main3.cpp
 * @author your name (you@domain.com)
 * @brief   inspect PDF structure
 * @version 0.1
 * @date 2025-06-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <fpdfview.h>
#include <fpdf_doc.h>
#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    FPDF_InitLibrary();

    const char *path = "../sample.pdf";
    FPDF_DOCUMENT doc = FPDF_LoadDocument(path, nullptr);
    if (!doc)
    {
        std::cerr << "Failed to open PDF\n";
        return 1;
    }

    int page_count = FPDF_GetPageCount(doc);
    std::cout << "Page count: " << page_count << "\n";

    // Show page sizes
    for (int i = 0; i < page_count; ++i)
    {
        FPDF_PAGE page = FPDF_LoadPage(doc, i);
        if (!page)
            continue;

        double width = FPDF_GetPageWidth(page);
        double height = FPDF_GetPageHeight(page);

        std::cout << "Page " << i << ": " << width << "x" << height << "\n";

        FPDF_ClosePage(page);
    }

    FPDF_CloseDocument(doc);
    FPDF_DestroyLibrary();
    return 0;
}
