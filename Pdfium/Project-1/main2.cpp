#include <fpdfview.h>
#include <fpdf_render.h>
#include <fpdf_doc.h>

#include <iostream>
#include <fstream>
#include <vector>

// Save image buffer as PPM file (simple format)
void saveAsPPM(const std::string& filename, const std::vector<uint8_t>& buffer, int width, int height) {
    std::ofstream out(filename, std::ios::binary);
    out << "P6\n" << width << " " << height << "\n255\n";
    for (int i = 0; i < width * height; ++i) {
        out.put(buffer[i * 4 + 2]); // R
        out.put(buffer[i * 4 + 1]); // G
        out.put(buffer[i * 4 + 0]); // B
    }
    out.close();
}

int main() {
    FPDF_InitLibrary();

    const char* filePath = "../sample.pdf";
    FPDF_DOCUMENT doc = FPDF_LoadDocument(filePath, nullptr);
    if (!doc) {
        std::cerr << "Failed to open PDF file.\n";
        return 1;
    }

    FPDF_PAGE page = FPDF_LoadPage(doc, 0); // First page
    if (!page) {
        std::cerr << "Failed to load page.\n";
        FPDF_CloseDocument(doc);
        return 1;
    }

    int width = static_cast<int>(FPDF_GetPageWidth(page));
    int height = static_cast<int>(FPDF_GetPageHeight(page));
    int stride = width * 4;

    std::vector<uint8_t> buffer(stride * height, 255);

    FPDF_BITMAP bitmap = FPDFBitmap_CreateEx(width, height, FPDFBitmap_BGRA, buffer.data(), stride);
    FPDFBitmap_FillRect(bitmap, 0, 0, width, height, 0xFFFFFFFF);
    FPDF_RenderPageBitmap(bitmap, page, 0, 0, width, height, 0, 0);

    saveAsPPM("page0.ppm", buffer, width, height);
    std::cout << "Rendered page saved as page0.ppm\n";

    FPDFBitmap_Destroy(bitmap);
    FPDF_ClosePage(page);
    FPDF_CloseDocument(doc);
    FPDF_DestroyLibrary();

    return 0;
}
