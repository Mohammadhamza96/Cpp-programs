#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct FoodItem {
    string name;
    int price;
};


void displayWelcomeMessage();
void displayVegMenu();
void displayNonVegMenu();
int takeOrder();
void displayOrderSummary(const vector<FoodItem>& orderList, int totalAmount);

int main() {
    displayWelcomeMessage();
    int totalAmount = takeOrder();

    cout << "\nThank you for your order!" << endl;
    cout << "Your total bill amount is Rs " << totalAmount << endl;
    return 0;
}

void displayWelcomeMessage() {
    cout << "================= Welcome to Online Food Ordering =================" << endl;
    cout << "Instructions:" << endl;
    cout << "1. You can order both Veg and Non-Veg items." << endl;
    cout << "2. Choose the food category and then the items you want." << endl;
    cout << "3. You can continue adding items until you're done." << endl;
    cout << "============================================================================\n" << endl;
}

void displayVegMenu() {
    cout << "\n--- Veg Menu ---" << endl;
    cout << "1. Paneer      - Rs 250" << endl;
    cout << "2. Veg Burger  - Rs 50" << endl;
    cout << "3. Veg Pizza   - Rs 100" << endl;
    cout << "4. Chowmein    - Rs 150" << endl;
    cout << "5. Veg Roll    - Rs 100" << endl;
}

void displayNonVegMenu() {
    cout << "\n--- Non-Veg Menu ---" << endl;
    cout << "1. Chicken        - Rs 350" << endl;
    cout << "2. Chicken Burger - Rs 100" << endl;
    cout << "3. Chicken Pizza  - Rs 150" << endl;
    cout << "4. Non-Veg Chowmein - Rs 200" << endl;
    cout << "5. Non-Veg Roll   - Rs 200" << endl;
}

int takeOrder() {
    vector<FoodItem> orderList;
    int totalAmount = 0;
    char categoryChoice, continueChoice;

    do {
        cout << "\nChoose food category: (v) Veg  (n) Non-Veg: ";
        cin >> categoryChoice;

        int itemChoice;
        if (categoryChoice == 'v' || categoryChoice == 'V') {
            displayVegMenu();
            cout << "Enter item number (1-5): ";
            cin >> itemChoice;

            switch (itemChoice) {
                case 1: orderList.push_back({"Noddles", 250}); totalAmount += 250; break;
                case 2: orderList.push_back({"Veg Burger", 50}); totalAmount += 50; break;
                case 3: orderList.push_back({"Veg Pizza", 100}); totalAmount += 100; break;
                case 4: orderList.push_back({"Herbs", 150}); totalAmount += 150; break;
                case 5: orderList.push_back({"Veg Roll", 100}); totalAmount += 100; break;
                default: cout << "Invalid item number. Please try again." << endl;
            }
        } else if (categoryChoice == 'n' || categoryChoice == 'N') {
            displayNonVegMenu();
            cout << "Enter item number (1-5): ";
            cin >> itemChoice;

            switch (itemChoice) {
                case 1: orderList.push_back({"Chicken", 350}); totalAmount += 350; break;
                case 2: orderList.push_back({"Chicken Burger", 100}); totalAmount += 100; break;
                case 3: orderList.push_back({"Chicken Pizza", 150}); totalAmount += 150; break;
                case 4: orderList.push_back({"Non-Veg Chowmein", 200}); totalAmount += 200; break;
                case 5: orderList.push_back({"Non-Veg Roll", 200}); totalAmount += 200; break;
                default: cout << "Invalid item number. Please try again." << endl;
            }
        } else {
            cout << "Invalid category. Please select (v) or (n)." << endl;
        }

        cout << "Do you want to add more items? (y/n): ";
        cin >> continueChoice;

    } while (continueChoice == 'y' || continueChoice == 'Y');

    displayOrderSummary(orderList, totalAmount);
    return totalAmount;
}

void displayOrderSummary(const vector<FoodItem>& orderList, int totalAmount) {
    cout << "\n-------- Order Summary --------" << endl;
    for (size_t i = 0; i < orderList.size(); ++i) {
        cout << "- " << orderList[i].name << ": Rs " << orderList[i].price << endl;
    }
    cout << "-------------------------------" << endl;
    cout << "Total: Rs " << totalAmount << endl;
    cout << "-------------------------------\n" << endl;
}
