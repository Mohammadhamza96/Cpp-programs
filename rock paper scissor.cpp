#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <cctype>  
using namespace std;


void clearScreen() {
    system("cls");
}

string moveToWord(char move) {
    if (move == 'r') return "Rock";
    if (move == 'p') return "Paper";
    if (move == 's') return "Scissors";
    return "Invalid";
}

int determineWinner(char move1, char move2) {
    if (move1 == move2) return 0;
    if ((move1 == 'r' && move2 == 's') ||
        (move1 == 'p' && move2 == 'r') ||
        (move1 == 's' && move2 == 'p')) {
        return 1;
    }
    return 2;
}

char getValidMove(string prompt) {
    char move;
    while (true) {
        cout << prompt;
        cin >> move;
        move = tolower(move);
        if (move == 'r' || move == 'p' || move == 's') {
            return move;
        } else {
            cout << "Invalid input. Please enter 'r', 'p', or 's'." << endl;
        }
    }
}

int main() {
    char gameMode;
    char player1Move, player2Move, computerMove;
    bool playAgain = true;
    int player1Score = 0, player2Score = 0;
    
    srand(time(0));

    cout << "========== Rock Paper Scissors Game ===========" << endl;

    while (playAgain) {
        // Choose game mode
        cout << "\nSelect Game Mode:" << endl;
        cout << "1. Single Player (vs Computer)" << endl;
        cout << "2. Two Player" << endl;
        cout << "Enter mode (1 or 2): ";
        cin >> gameMode;

        if (gameMode == '1') {
            // SINGLE PLAYER MODE
            player1Move = getValidMove("Enter your move (r: Rock, p: Paper, s: Scissors): ");

            // Random computer move
            int randomNumber = rand() % 3;
            computerMove = (randomNumber == 0) ? 'r' : (randomNumber == 1) ? 'p' : 's';

            cout << "Computer chose: " << moveToWord(computerMove) << endl;

            int result = determineWinner(player1Move, computerMove);
            if (result == 0) {
                cout << "It's a tie!" << endl;
            } else if (result == 1) {
                cout << "You win!" << endl;
                player1Score++;
            } else {
                cout << "Computer wins!" << endl;
                player2Score++;
            }
        } 
        else if (gameMode == '2') {
            // TWO PLAYER MODE
            cout << "\n--- Player 1 Turn ---" << endl;
            player1Move = getValidMove("Enter your move (r: Rock, p: Paper, s: Scissors): ");
            clearScreen();

            cout << "\n--- Player 2 Turn ---" << endl;
            player2Move = getValidMove("Enter your move (r: Rock, p: Paper, s: Scissors): ");
            clearScreen();

            cout << "Player 1 choose: " << moveToWord(player1Move) << endl;
            cout << "Player 2 choose: " << moveToWord(player2Move) << endl;

            int result = determineWinner(player1Move, player2Move);
            if (result == 0) {
                cout << "It's a tie!" << endl;
            } else if (result == 1) {
                cout << "Player 1 wins!" << endl;
                player1Score++;
            } else {
                cout << "Player 2 wins!" << endl;
                player2Score++;
            }
        } 
        else {
            cout << "Invalid mode selected. Please choose 1 or 2." << endl;
            continue;
        }

        // Display current scores
        cout << "\nScoreboard:" << endl;
        cout << "Player 1: " << player1Score << endl;
        if (gameMode == '1') {
            cout << "Computer: " << player2Score << endl;
        } else {
            cout << "Player 2: " << player2Score << endl;
        }

        // Ask if the player wants to play again
        char choice;
        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;
        playAgain = (tolower(choice) == 'y');
        clearScreen();
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}

