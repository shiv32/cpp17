/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-05-01
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include "nDGrid.hpp"

using namespace std;

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Note : Each dimension size is 10

    NDGrid<int, 1> singleDGrid;
    NDGrid<int, 2> twoDGrid;
    NDGrid<int, 3> threeDGrid;

    singleDGrid[0] = 7;
    singleDGrid[1] = 70;
    singleDGrid[9] = 71;
    // singleDGrid[10] = 71; //crash out of bound

    clog << singleDGrid[0] << endl;
    clog << singleDGrid[1] << endl;
    clog << singleDGrid[9] << endl;

    twoDGrid[0][0] = 6;
    twoDGrid[0][1] = 60;
    twoDGrid[9][9] = 61;
    // twoDGrid[10][10] = 61; //crash out of bound

    clog << twoDGrid[0][0] << endl;
    clog << twoDGrid[0][1] << endl;
    clog << twoDGrid[9][9] << endl;

    threeDGrid[0][0][0] = 8;
    threeDGrid[0][0][1] = 80;
    threeDGrid[9][9][9] = 81;
    // threeDGrid[10][10][10] = 81; //crash out of bound

    clog << threeDGrid[0][0][0] << endl;
    clog << threeDGrid[0][0][1] << endl;
    clog << threeDGrid[9][9][9] << endl;

    //-----------------------------------------
    NDGrid<int, 3> my3DGrid;

    my3DGrid[2][1][2] = 5;
    my3DGrid[1][1][1] = 8;

    clog << my3DGrid[2][1][2] << endl;
    clog << my3DGrid[1][1][1] << endl;

    return 0;
}