/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Linear Regression
 * @version 0.1
 * @date 2024-12-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <iostream>
#include <vector>
#include <cmath>

// Function to calculate mean squared error
double computeMSE(const std::vector<double> &x, const std::vector<double> &y, double m, double b)
{
    double totalError = 0.0;
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        double prediction = m * x[i] + b;
        totalError += pow((y[i] - prediction), 2);
    }
    return totalError / n;
}

// Function to perform gradient descent
void gradientDescent(const std::vector<double> &x, const std::vector<double> &y, double &m, double &b, double learningRate, int iterations)
{
    int n = x.size();
    for (int i = 0; i < iterations; i++)
    {
        double mGradient = 0.0;
        double bGradient = 0.0;

        // Compute gradients
        for (int j = 0; j < n; j++)
        {
            double prediction = m * x[j] + b;
            mGradient += -(2.0 / n) * x[j] * (y[j] - prediction);
            bGradient += -(2.0 / n) * (y[j] - prediction);
        }

        // Update parameters
        m -= learningRate * mGradient;
        b -= learningRate * bGradient;

        // Print error every 100 iterations
        if (i % 100 == 0)
        {
            std::cout << "Iteration " << i << ", MSE: " << computeMSE(x, y, m, b) << "\n";
        }
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    // Example data: x (input) and y (output)
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 4, 6, 8, 10}; // y = 2 * x

    // Initialize parameters
    double m = 0.0; // Slope
    double b = 0.0; // Intercept
    double learningRate = 0.01;
    int iterations = 1000;

    // Train the model
    gradientDescent(x, y, m, b, learningRate, iterations);

    // Output the final values of m and b
    std::cout << "\nTrained model: y = " << m << " * x + " << b << "\n";

    // Test the model
    double testInput = 6.0;
    double prediction = m * testInput + b;
    std::cout << "Prediction for x = " << testInput << ": " << prediction << "\n";

    return 0;
}
