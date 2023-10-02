#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Generate a random number between 1 and 100
    srand(time(nullptr));
    int secretNumber = rand() % 100 + 1;

    // Ask the user to guess the number
    std::cout << "Guess a number between 1 and 100: ";
    int guess;
    std::cin >> guess;

    // Keep asking the user to guess until they guess the correct number
    while (guess != secretNumber) {
        if (guess < secretNumber) {
            std::cout << "Too low! Guess again: ";
        } else {
            std::cout << "Too high! Guess again: ";
        }
        std::cin >> guess;
    }

    // The user has guessed the correct number
    std::cout << "Congratulations! You guessed the number.\n";

    return 0;
}