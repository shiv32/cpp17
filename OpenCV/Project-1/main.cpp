#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0]
                  << " <input_image> <output_image>\n";
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];

    cv::Mat image = cv::imread(inputFile);

    if (image.empty())
    {
        std::cerr << "Error: Could not read image\n";
        return 1;
    }

    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    if (!cv::imwrite(outputFile, gray))
    {
        std::cerr << "Error: Could not write image\n";
        return 1;
    }

    std::cout << "Image processed successfully!\n";
    std::cout << "Input  : " << inputFile << "\n";
    std::cout << "Output : " << outputFile << "\n";

    return 0;
}
