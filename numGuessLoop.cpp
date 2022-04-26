// Copyright (c) 2022 Nicolas Riscalas All rights reserved.
//
// Created by: Nicolas Riscalas
// Created on:April 25 2022
// This program makes a random number game

#include <stdlib.h>
#include <iostream>
#include <random>
#include "colours/colors.h"

using std::cout;
using std::cin;
using std::string;

int main() {
    int randomNum, biggestNum, usersNum;
    string biggestNumStr, usersNumStr;
    cout << "Enter the largest number to be generated: ";
    cin >> biggestNumStr;
    // get the guess from the user as a string
    try {
        // convert the user's guess to an int
        biggestNum = std::stoi(biggestNumStr);
        // check if the guess is correct
    } catch (std::invalid_argument) {
    // The user did not enter an integer.
    cout << BOLDRED << biggestNumStr << " is not an integer.\n";
    main();
    }
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(1, biggestNum);
    randomNum = idist(rgen);

    while (true) {
        cout << BOLDWHITE << "Guess a number between 1 and "\
        << biggestNum << ": ";
        cin >> usersNumStr;
        try {
            // convert the user's guess to an int
            usersNum = std::stoi(usersNumStr);
            // check if the guess is correct
        } catch (std::invalid_argument) {
            // The user did not enter an integer.
            cout << usersNumStr << " is not an integer.\n";
            main();
        }
        if (randomNum < usersNum) {
            cout << BOLDRED << "The secret number is lower\n";
        } else if (randomNum > usersNum) {
            cout << BOLDRED << "The secret number is higher\n";
        } else {
            cout << BOLDGREEN << "You guessed the right number!\n";
        break;
        }
    }
}
