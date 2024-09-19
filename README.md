# Guessing Game
This code is a simple "Guess the Number" game written in C++. Here's a breakdown of its functionality:

Compilation and Execution:

To compile the code, the command is: g++ jogoadvinha.cpp -o jogoadvinha.out
To run the compiled program: ./jogoadvinha.out
Every time changes are made to the code, it must be recompiled before running again.
Includes and Libraries:

#include <iostream>: Allows input and output operations (e.g., using cin for input and cout for output).
#include <cstdlib>: Contains functions for generating random numbers (like rand() and srand()).
#include <ctime>: Used to seed the random number generator with the current time.
using namespace std;: Allows the use of standard functions like cout without the need for std:: prefix.
Main Program:

The program begins by printing a welcome message to the user.
The user is asked to choose a difficulty level: Easy ('E'), Medium ('M'), or Difficult ('D'). Based on this choice, the number of allowed attempts (numOfTry) is set to 15, 10, or 5, respectively.
Random Secret Number:

A secret number between 0 and 99 is generated using rand() % 100. The random number generator is seeded with the current time using srand(time(NULL)), which ensures a different number is generated in each run of the game.
Gameplay:

The player is prompted to guess the secret number within the allowed number of attempts.
For each guess, the program calculates how close the guess is to the secret number and subtracts points based on the difference.
If the guess is too high or too low, the program provides feedback to the player.
If the player guesses the correct number, they win the game, and the program displays the number of attempts taken and their remaining points.
Scoring:

The player starts with 1000 points, and points are deducted based on the difference between the guess and the secret number. The formula used for point deduction is: abs(guess - secret_num) / 2.0.
The program uses cout.precision(2) to format the points with two decimal places and fixed to prevent scientific notation.
End of Game:

If the player guesses correctly, the game ends with a victory message. If all attempts are used without guessing correctly, the game reveals the secret number and ends.
This code demonstrates core C++ concepts such as conditionals, loops, user input/output, and basic random number generation.
