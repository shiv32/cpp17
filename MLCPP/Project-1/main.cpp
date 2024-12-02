/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Linear Regression

 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include <cmath>

// Function to calculate mean of a vector
double mean(const std::vector<double> &v)
{
    double sum = 0.0;
    for (double value : v)
    {
        sum += value;
    }
    return sum / v.size();
}

// Function to calculate the slope (m) and intercept (b)
void linearRegression(const std::vector<double> &x, const std::vector<double> &y, double &m, double &b)
{
    double x_mean = mean(x);
    double y_mean = mean(y);

    double numerator = 0.0;
    double denominator = 0.0;

    for (size_t i = 0; i < x.size(); ++i)
    {
        numerator += (x[i] - x_mean) * (y[i] - y_mean);
        denominator += (x[i] - x_mean) * (x[i] - x_mean);
    }

    m = numerator / denominator;
    b = y_mean - (m * x_mean);
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Sample data points
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 4, 5, 4, 5};

    double slope = 0.0, intercept = 0.0;

    // Perform linear regression
    linearRegression(x, y, slope, intercept);

    // Output the results
    std::cout << "Linear Regression Model: y = " << slope << "x + " << intercept << std::endl;

    // Test the model with new data
    double test_x = 6;
    double predicted_y = slope * test_x + intercept;
    std::cout << "Prediction for x = " << test_x << ": y = " << predicted_y << std::endl;

    return 0;
}