#include <iostream>
int main() {
    // Ask the user to input two numbers and the desired arithmetic operation
    float num1, num2;
    char operation;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter arithmetic operation (+, -, *, /): ";
    std::cin >> operation;

    // Perform the arithmetic operation on the two numbers
    float result;
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "ERROR: Division by zero\n";
                return 1;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            std::cout << "ERROR: Invalid arithmetic operation\n";
            return 1;
    }

    // Output the result of the arithmetic operation
    std::cout << "Result: " << result << "\n";

    return 0;
}