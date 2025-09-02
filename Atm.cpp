#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int AccountNumber = 12345;
int PinCode = 123456;
long long AccountBalance = 0;

vector<int> TransactionAmounts;
vector<string> TransactionTypes;

void ClearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void AddTransaction(const string& Type, int Amount) {
    const size_t MaxEntries = 50;
    if (TransactionAmounts.size() >= MaxEntries) {
        TransactionAmounts.erase(TransactionAmounts.begin());
        TransactionTypes.erase(TransactionTypes.begin());
    }
    TransactionTypes.push_back(Type);
    TransactionAmounts.push_back(Amount);
}

bool Login() {
    int EnteredAccount, EnteredPin;

    cout << "==============================" << endl;
    cout << "         ATM Login       " << endl;
    cout << "==============================" << endl;

    while (true) {
        cout << "Enter Account Number: ";
        if (!(cin >> EnteredAccount)) {
            cout << "Invalid input. Numbers only.\n";
            ClearInput();
            continue;
        }
        if (EnteredAccount == AccountNumber) break;
        cout << "Wrong account number. Try again.\n";
    }

    while (true) {
        cout << "Enter PIN: ";
        if (!(cin >> EnteredPin)) {
            cout << "Invalid input. Numbers only.\n";
            ClearInput();
            continue;
        }
        if (EnteredPin == PinCode) break;
        cout << "Wrong PIN. Try again.\n";
    }

    cout << "\nLogin successful!\n\n";
    return true;
}

int GetMenuOption() {
    int Option;
    cout << "========== Main Menu ==========" << endl;
    cout << "1. View Balance" << endl;
    cout << "2. Withdraw Cash" << endl;
    cout << "3. Deposit Funds" << endl;
    cout << "4. Change PIN" << endl;
    cout << "5. View Mini Statement" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an option: ";

    if (!(cin >> Option)) {
        ClearInput();
        return -1;
    }
    return Option;
}

void ViewBalance() {
    cout << "\nYour balance is: $" << AccountBalance << "\n\n";
}

void WithdrawCash() {
    long long Amount;
    cout << "\nEnter amount to withdraw (0 to cancel): ";
    if (!(cin >> Amount)) {
        ClearInput();
        cout << "Invalid input. Cancelled.\n\n";
        return;
    }

    if (Amount == 0) {
        cout << "Transaction cancelled.\n\n";
        return;
    }
    if (Amount < 0) {
        cout << "Amount cannot be negative.\n\n";
        return;
    }
    if (Amount > AccountBalance) {
        cout << "Insufficient funds. Available: $" << AccountBalance << "\n\n";
        return;
    }

    AccountBalance -= Amount;
    cout << "You withdrew $" << Amount << ". New balance: $" << AccountBalance << "\n\n";
    AddTransaction("Withdraw", Amount);
}

void DepositFunds() {
    long long Amount;
    cout << "\nEnter amount to deposit (0 to cancel): ";
    if (!(cin >> Amount)) {
        ClearInput();
        cout << "Invalid input. Cancelled.\n\n";
        return;
    }

    if (Amount == 0) {
        cout << "Transaction cancelled.\n\n";
        return;
    }
    if (Amount < 0) {
        cout << "Amount cannot be negative.\n\n";
        return;
    }

    AccountBalance += Amount;
    cout << "You deposited $" << Amount << ". New balance: $" << AccountBalance << "\n\n";
    AddTransaction("Deposit", Amount);
}

void ChangePin() {
    int OldPin, NewPin;
    cout << "\nEnter current PIN: ";
    if (!(cin >> OldPin)) {
        ClearInput();
        cout << "Invalid input.\n\n";
        return;
    }

    if (OldPin != PinCode) {
        cout << "Incorrect PIN. Cannot change.\n\n";
        return;
    }

    cout << "Enter new PIN: ";
    if (!(cin >> NewPin)) {
        ClearInput();
        cout << "Invalid input.\n\n";
        return;
    }

    PinCode = NewPin;
    cout << "PIN changed successfully.\n\n";
    AddTransaction("PIN Change", 0);
}

void ViewMiniStatement() {
    cout << "\n------ Mini Statement ------\n";
    if (TransactionAmounts.empty()) {
        cout << "No transactions yet.\n";
    } else {
        int Start = max(0, (int)TransactionAmounts.size() - 5);
        for (int i = Start; i < (int)TransactionAmounts.size(); i++) {
            cout << TransactionTypes[i] << ": $" << TransactionAmounts[i] << "\n";
        }
    }
    cout << "----------------------------\n\n";
}

int main() {
    if (Login()) {
        bool Running = true;
        while (Running) {
            switch (GetMenuOption()) {
                case 1: ViewBalance(); break;
                case 2: WithdrawCash(); break;
                case 3: DepositFunds(); break;
                case 4: ChangePin(); break;
                case 5: ViewMiniStatement(); break;
                case 6:
                    cout << "\nThank you for using  ATM. Goodbye!\n";
                    Running = false;
                    break;
                default:
                    cout << "Invalid option. Try again.\n\n";
                    break;
            }
        }
    }
    return 0;
}

