#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

struct QuizQuestion {
    string question;
    vector<string> options;
    char correctOption;
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

char getValidAnswer() {
    char answer;
    while (true) {
        cin >> answer;
        answer = tolower(answer);
        if (answer >= 'a' && answer <= 'd') return answer;
        cout << "Invalid input! Please enter a, b, c, or d: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int runQuiz(const vector<QuizQuestion>& questions, vector<bool>& results) {
    int score = 0;
    for (size_t i = 0; i < questions.size(); ++i) {
        clearScreen();
        cout << "Q" << i + 1 << ": " << questions[i].question << "\n";
        cout << "a) " << questions[i].options[0] << "\n";
        cout << "b) " << questions[i].options[1] << "\n";
        cout << "c) " << questions[i].options[2] << "\n";
        cout << "d) " << questions[i].options[3] << "\n";
        cout << "Your answer (a/b/c/d): ";

        char userAns = getValidAnswer();
        bool correct = userAns == questions[i].correctOption;
        results[i] = correct;
        if (correct) {
            ++score;
            cout << "\nCorrect!\n";
        } else {
            cout << "\nIncorrect. Correct answer: " << questions[i].correctOption << ") "
                 << questions[i].options[questions[i].correctOption - 'a'] << "\n";
        }
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }
    return score;
}

void showResults(const vector<QuizQuestion>& questions, const vector<bool>& results, int score) {
    clearScreen();
    cout << "\n==== Quiz Results ====\n";
    cout << "Score: " << score << "/" << questions.size() << " -> " << (score >= 6 ? "Congradulation $$$  PASS  $$$ " : " FAIL ") << "\n\n";

    for (size_t i = 0; i < questions.size(); ++i) {
        cout << "Q" << i + 1 << ": " << questions[i].question << "\n";
        cout << "Correct: " << questions[i].correctOption << ") "
             << questions[i].options[questions[i].correctOption - 'a'] << "\n";
        cout << "You were: " << (results[i] ? "Correct" : "Wrong") << "\n\n";
    }
}

int main() {
    vector<QuizQuestion> questions = {
        {"Which planet is known as the Red Planet?", {"Mercury", "Venus", "Mars", "Jupiter"}, 'c'},
        {"What is the chemical symbol for water?", {"WO", "H2O", "HO2", "OH"}, 'b'},
        {"Who wrote 'Romeo and Juliet'?", {"Charles Dickens", "Jane Austen", "William Shakespeare", "Mark Twain"}, 'c'},
        {"What is the capital of France?", {"Berlin", "Madrid", "Rome", "Paris"}, 'd'},
        {"Which organ in the human body pumps blood?", {"Brain", "Lungs", "Heart", "Kidneys"}, 'c'},
        {"What is the largest ocean on Earth?", {"Atlantic", "Indian", "Arctic", "Pacific"}, 'd'},
        {"What gas do plants absorb?", {"Oxygen", "Carbon Dioxide", "Hydrogen", "Nitrogen"}, 'b'},
        {"Which country has the Great Wall?", {"India", "China", "Egypt", "Japan"}, 'b'},
        {"Currency of Japan?", {"Yen", "Won", "Euro", "Ringgit"}, 'a'},
        {"Photosynthesis takes place in?", {"Root", "Stem", "Flower", "Leaf"}, 'd'}
    };

    char playAgain;
    do {
        clearScreen();
        cout << "========= Welcome to the Quiz Game ============\n";
        cout << "Press 's' to start: ";
        char start;
        cin >> start;
        cin.ignore(10000, '\n');
        if (tolower(start) != 's') break;

        vector<bool> results(questions.size());
        int score = runQuiz(questions, results);
        showResults(questions, results, score);

        cout << "Play again? (y/n): ";
        cin >> playAgain;
        cin.ignore(10000, '\n');
    } while (tolower(playAgain) == 'y');

    clearScreen();
    cout << "Thanks for playing!\n";
    return 0;
}

