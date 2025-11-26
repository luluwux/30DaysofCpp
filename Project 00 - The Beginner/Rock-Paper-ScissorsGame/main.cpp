#include <iostream>  
#include <random>    
#include <string>  
#include <limits>  
#include <cctype>

// 0: Rock, 1: Paper, 2: Scissors
enum class Choice {
    Rock,
    Paper,
    Scissors
};

/**
 * @brief Converts a Choice enum to a printable string.
 * @param choice The enum value to convert.
 * @return A string representation ("Rock", "Paper", or "Scissors").
 */

std::string choiceToString(Choice choice) {
    switch (choice) {
        case Choice::Rock:     
        return "Rock";
        case Choice::Paper:    
        return "Paper";
        case Choice::Scissors: 
        return "Scissors";
        default:               
        return "Unknown"; 
    }
}

int main() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(0, 2); // 0, 1, or 2

    char playAgain;

    do {
        std::cout << "===================================" << std::endl;
        std::cout << "Welcome to Rock-Paper-Scissors!" << std::endl;
        std::cout << "Choose your option:" << std::endl;
        std::cout << "0: Rock" << std::endl;
        std::cout << "1: Paper" << std::endl;
        std::cout << "2: Scissors" << std::endl;
        
        int userInput = -1; 
        

        while (userInput < 0 || userInput > 2) {
            std::cout << "Your choice: ";

            if (!(std::cin >> userInput)) {
                std::cout << "Invalid input! Please enter a number." << std::endl;
                std::cin.clear(); 
 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                userInput = -1;
            } else if (userInput < 0 || userInput > 2) {
                std::cout << "Invalid choice! Please enter 0, 1, or 2." << std::endl;
            }
        }

        Choice userChoice = static_cast<Choice>(userInput);
        
        Choice computerChoice = static_cast<Choice>(distribution(gen));
    
        std::cout << "--------------------" << std::endl;
        std::cout << "You chose:     " << choiceToString(userChoice) << std::endl;
        std::cout << "Computer chose: " << choiceToString(computerChoice) << std::endl;
        std::cout << "--------------------" << std::endl;

        if (userChoice == computerChoice) {
            std::cout << "It's a tie!" << std::endl;
        } else if ((userChoice == Choice::Rock && computerChoice == Choice::Scissors) ||
                   (userChoice == Choice::Paper && computerChoice == Choice::Rock) ||
                   (userChoice == Choice::Scissors && computerChoice == Choice::Paper)) {
            std::cout << "Congratulations, you win!" << std::endl;
        } else {
            std::cout << "Computer wins!" << std::endl;
        } 


        std::cout << "\nPlay again? (y/n): ";
        std::cin >> playAgain;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (std::tolower(playAgain) == 'y');

    std::cout << "\nThanks for playing! Goodbye." << std::endl;

    return 0;
}