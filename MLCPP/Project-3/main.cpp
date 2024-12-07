/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief  K-Nearest Neighbors (KNN) for classification
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

// Structure to represent a data point
struct DataPoint
{
    std::vector<double> features; // Feature vector
    int label;                    // Class label
};

// Function to calculate Euclidean distance between two points
double euclideanDistance(const std::vector<double> &point1, const std::vector<double> &point2)
{
    double sum = 0.0;
    for (size_t i = 0; i < point1.size(); i++)
    {
        sum += pow(point1[i] - point2[i], 2);
    }
    return sqrt(sum);
}

// KNN Classifier
int knn(const std::vector<DataPoint> &trainingData, const std::vector<double> &testPoint, int k)
{
    // Vector to store distances and corresponding labels
    std::vector<std::pair<double, int>> distances;

    // Compute distances from testPoint to all training points
    for (const auto &data : trainingData)
    {
        double distance = euclideanDistance(data.features, testPoint);
        distances.push_back({distance, data.label});
    }

    // Sort distances in ascending order
    std::sort(distances.begin(), distances.end());

    // Count the labels of the k nearest neighbors
    std::map<int, int> labelCount;
    for (int i = 0; i < k; i++)
    {
        int label = distances[i].second;
        labelCount[label]++;
    }

    // Determine the most frequent label
    int predictedLabel = -1;
    int maxCount = 0;
    for (const auto &label : labelCount)
    {
        if (label.second > maxCount)
        {
            maxCount = label.second;
            predictedLabel = label.first;
        }
    }

    return predictedLabel;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Training data
    std::vector<DataPoint> trainingData = {
        {{1.0, 2.0}, 0},
        {{2.0, 3.0}, 0},
        {{3.0, 3.0}, 1},
        {{5.0, 6.0}, 1},
        {{6.0, 5.0}, 1}};

    // Test point
    std::vector<double> testPoint = {4.0, 4.0};

    // Test point
    // std::vector<double> testPoint = {-4.0, -4.0};

    // Number of neighbors
    int k = 3;

    // Predict the class of the test point
    int predictedLabel = knn(trainingData, testPoint, k);

    // Output the prediction
    std::cout << "The predicted class for the test point is: " << predictedLabel << std::endl;

    return 0;
}
