#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0]
                  << " <input_gray> <output_color>\n";
        return 1;
    }

    cv::Mat gray = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    if (gray.empty()) {
        std::cerr << "Failed to read image\n";
        return 1;
    }

    cv::Mat color;
    cv::applyColorMap(gray, color, cv::COLORMAP_JET);

    cv::imwrite(argv[2], color);

    std::cout << "Gray → COLOR conversion done\n";
    return 0;
}
