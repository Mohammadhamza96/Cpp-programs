#include <iostream>
#include <string>
#include <vector>
#include <windows.h> // For Sleep() and system("cls")

using namespace std;

// Represents a single bank account with its details.
class Account {
private:
    string accountNo;
    string password;
    int balance;

public:
    // Default constructor to initialize account details.
    Account() : accountNo(""), password(""), balance(0) {}

    // Getters and setters for account data.
    void setAccountNo(string id) {
        accountNo = id;
    }

    void setPassword(string pw) {
        password = pw;
    }

    void setBalance(int b) {
        balance = b;
    }

    string getAccountNo() const {
        return accountNo;
    }

    string getPassword() const {
        return password;
    }

    int getBalance() const {
        return balance;
    }
};

// Manages all banking operations.
class Bank {
private:
    // Stores all accounts in a vector. Data will not persist after the program closes.
    vector<Account> accounts;

    // Clears the console screen for better UI.
    void clearScreen() {
        system("cls");
    }

public:
    // Creates a new bank account.
    void openAccount() {
        clearScreen();
        cout << "\t*** Open a New Account ***" << endl;
        Account newAccount;
        string id, pw;

        cout << "\tEnter Account No: ";
        cin >> id;
        newAccount.setAccountNo(id);

        cout << "\tEnter A Strong Password: ";
        cin >> pw;
        newAccount.setPassword(pw);
        
        // Check for duplicate account numbers.
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (accounts[i].getAccountNo() == id) {
                cout << "\tAccount with this number already exists!" << endl;
                Sleep(3000);
                return;
            }
        }

        newAccount.setBalance(0);
        accounts.push_back(newAccount);

        cout << "\tAccount Created Successfully!" << endl;
        Sleep(3000);
    }

    // Adds cash to an existing account.
    void addCash() {
        clearScreen();
        cout << "\t*** Deposit Cash ***" << endl;
        string id;
        cout << "\tEnter Account No: ";
        cin >> id;

        bool found = false;
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (accounts[i].getAccountNo() == id) {
                found = true;
                int cash;
                cout << "\tEnter amount to deposit: ";
                cin >> cash;
                if (cash > 0) {
                    accounts[i].setBalance(accounts[i].getBalance() + cash);
                    cout << "\tDeposit successful!" << endl;
                    cout << "\tNew Balance: " << accounts[i].getBalance() << endl;
                } else {
                    cout << "\tInvalid amount. Deposit must be a positive value." << endl;
                }
                break;
            }
        }
        if (!found) {
            cout << "\tInvalid Account No!" << endl;
        }
        Sleep(5000);
    }

    // Withdraws cash from an account.
    void withdraw() {
        clearScreen();
        cout << "\t*** Withdraw Cash ***" << endl;
        string id, pw;
        cout << "\tEnter Account No: ";
        cin >> id;
        cout << "\tEnter Password: ";
        cin >> pw;

        bool found = false;
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (accounts[i].getAccountNo() == id && accounts[i].getPassword() == pw) {
                found = true;
                int cash;
                cout << "\tEnter amount to withdraw: ";
                cin >> cash;
                if (cash > 0 && cash <= accounts[i].getBalance()) {
                    accounts[i].setBalance(accounts[i].getBalance() - cash);
                    cout << "\tWithdrawal successful!" << endl;
                    cout << "\tRemaining Balance: " << accounts[i].getBalance() << endl;
                } else if (cash <= 0) {
                    cout << "\tInvalid amount. Withdrawal must be a positive value." << endl;
                } else {
                    cout << "\tLow Balance!" << endl;
                }
                break;
            }
        }
        if (!found) {
            cout << "\tInvalid Account No or Password!" << endl;
        }
        Sleep(5000);
    }
    
    // Checks the balance of an account.
    void checkBalance() {
        clearScreen();
        cout << "\t*** Check Balance ***" << endl;
        string id, pw;
        cout << "\tEnter Account No: ";
        cin >> id;
        cout << "\tEnter Password: ";
        cin >> pw;

        bool found = false;
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (accounts[i].getAccountNo() == id && accounts[i].getPassword() == pw) {
                found = true;
                cout << "\tYour current balance is: " << accounts[i].getBalance() << endl;
                break;
            }
        }
        if (!found) {
            cout << "\tInvalid Account No or Password!" << endl;
        }
        Sleep(5000);
    }

    // Changes the password for an account.
    void changePassword() {
        clearScreen();
        cout << "\t*** Change Password ***" << endl;
        string id, oldPw, newPw;
        cout << "\tEnter Account No: ";
        cin >> id;
        cout << "\tEnter Current Password: ";
        cin >> oldPw;

        bool found = false;
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (accounts[i].getAccountNo() == id && accounts[i].getPassword() == oldPw) {
                found = true;
                cout << "\tEnter New Password: ";
                cin >> newPw;
                accounts[i].setPassword(newPw);
                cout << "\tPassword changed successfully!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "\tInvalid Account No or Password!" << endl;
        }
        Sleep(5000);
    }
    
    // Deletes an account from the system.
    void deleteAccount() {
        clearScreen();
        cout << "\t*** Delete Account ***" << endl;
        string id, pw;
        cout << "\tEnter Account No: ";
        cin >> id;
        cout << "\tEnter Password: ";
        cin >> pw;

        bool found = false;
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (accounts[i].getAccountNo() == id && accounts[i].getPassword() == pw) {
                found = true;
                accounts.erase(accounts.begin() + i);
                cout << "\tAccount deleted successfully!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "\tInvalid Account No or Password!" << endl;
        }
        Sleep(5000);
    }

    // Displays the main menu and handles user input.
    void showMenu() {
        bool exit = false;
        while (!exit) {
            clearScreen();
            cout << "\t==========================================" << endl;
            cout << "\tWelcome To Bank Account Management System" << endl;
            cout << "\t==========================================" << endl;
            cout << "\t1. Open New Account" << endl;
            cout << "\t2. Deposit Cash" << endl;
            cout << "\t3. Withdraw Cash" << endl;
            cout << "\t4. Check Balance" << endl;
            cout << "\t5. Change Password" << endl;
            cout << "\t6. Delete Account" << endl;
            cout << "\t7. Exit" << endl;
            cout << "\tEnter Your Choice: ";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    openAccount();
                    break;
                case 2:
                    addCash();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    checkBalance();
                    break;
                case 5:
                    changePassword();
                    break;
                case 6:
                    deleteAccount();
                    break;
                case 7:
                    clearScreen();
                    exit = true;
                    cout << "\tGood Luck!" << endl;
                    Sleep(2000);
                    break;
                default:
                    cout << "\tInvalid choice! Please try again." << endl;
                    Sleep(3000);
                    break;
            }
        }
    }
};

int main() {
    Bank myBank;
    myBank.showMenu();
    return 0;
}

