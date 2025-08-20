#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <utility>
#include <cctype>

using namespace std;

void displayWelcomeMessage() {
    cout << "------ Welcome to the Number Guessing Game ------" << endl;
    cout << "In this game, you need to guess a secret number within a chosen range." << endl;
    cout << "You can select different difficulty levels to adjust the number range:" << endl;
    cout << "  - Easy: 1 to 50" << endl;
    cout << "  - Medium: 1 to 100" << endl;
    cout << "  - Hard: 1 to 200" << endl;
    cout << "Enter 'quit' at any time during guessing to exit the current game." << endl;
    cout << "Have fun and good luck!" << endl;
}

// Function to get the user's chosen difficulty level
pair<int, int> getDifficultyLevel() {
    string difficultyInput;
    while (true) {
        cout << "Choose difficulty (easy/medium/hard): ";
        getline(cin, difficultyInput);
        
        // Convert input to lowercase for case-insensitive comparison
        for (char& ch : difficultyInput) {
            ch = tolower(ch);
        }
        
        if (difficultyInput == "easy") {
            return {1, 50};
        } else if (difficultyInput == "medium") {
            return {1, 100};
        } else if (difficultyInput == "hard") {
            return {1, 200};
        } else {
            cout << "Invalid choice. Please enter 'easy', 'medium', or 'hard'." << endl;
        }
    }
}

// Function to run a single game round and returns the number of guesses taken (0 if user quits)
int playSingleGame(int minNumber, int maxNumber) {
    // Generate the secret number within the specified range
    int secretNumber = rand() % (maxNumber - minNumber + 1) + minNumber;
    int guessCount = 0;
    bool isPlaying = true;
    
    cout << "\nStarting a new game with range " << minNumber << " to " << maxNumber << "..." << endl;
    
    while (isPlaying) {
        string userInput;
        cout << "Enter your guess (or 'quit' to exit): ";
        getline(cin, userInput);
        
        // Check if user wants to quit
        if (userInput == "quit") {
            cout << "Quitting the current game. The secret number was " << secretNumber << "." << endl;
            return 0;
        }
        
        try {
            // Attempt to convert input to integer
            int userGuess = stoi(userInput);
            guessCount++;
            
            // Validate if guess is within range
            if (userGuess < minNumber || userGuess > maxNumber) {
                cout << "That guess is out of range. Please choose between " << minNumber << " and " << maxNumber << "." << endl;
            } else if (userGuess < secretNumber) {
                cout << "Too low! Try a higher number." << endl;
            } else if (userGuess > secretNumber) {
                cout << "Too high! Try a lower number." << endl;
            } else {
                // Correct guess
                cout << "Congratulations! You guessed the correct number: " << secretNumber << "." << endl;
                cout << "It took you " << guessCount << " guesses." << endl;
                isPlaying = false;
                return guessCount;
            }
        } catch (...) {
            // Handle non-numeric input
            cout << "Invalid input. Please enter a number or 'quit'." << endl;
        }
    }
    
    return guessCount;
}

// Main function to control the game flow
int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    displayWelcomeMessage();
    
    string playAgainResponse;
    do {
        // Get difficulty and range
        auto [minNumber, maxNumber] = getDifficultyLevel();
        
        // Play the game and get the result
        int guessesTaken = playSingleGame(minNumber, maxNumber);
        
        // If user quit during the game, exit the program
        if (guessesTaken == 0) {
            break;
        }
        
        // Ask if the user wants to play another round
        cout << "Do you want to play again? (yes/no): ";
        getline(cin, playAgainResponse);
        
        // Convert response to lowercase for comparison
        for (char& ch : playAgainResponse) {
            ch = tolower(ch);
        }
    } while (playAgainResponse == "yes" || playAgainResponse == "y");
    
    cout << "Thanks for playing the Number Guessing Game!" << endl;
    return 0;
}