#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class Patient {
public:
    string name;
    int age;
    string illness;

    // Constructor to initialize patient details
    Patient(string n, int a, string i) : name(n), age(a), illness(i) {}

    // Show patient details
    void showInfo() const {
        cout << "Name: " << name << "\nAge: " << age << "\nIllness: " << illness << "\n";
    }
};

class Hospital {
private:
    vector<Patient> patientList;

public:
    // Add a new patient
    void addPatient() {
        string name, illness;
        int age;

        cout << "Enter patient's name: ";
        getline(cin >> ws, name);

        cout << "Enter age: ";
        while (!(cin >> age) || age < 0) {
            cout << "Invalid age. Enter a non-negative number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter illness: ";
        getline(cin >> ws, illness);

        patientList.push_back(Patient(name, age, illness));
        cout << "Patient added successfully!\n";
    }

    // Show all patients
    void showAllPatients() {
        if (patientList.empty()) {
            cout << "No patients in the system.\n";
            return;
        }

        for (size_t i = 0; i < patientList.size(); ++i) {
            cout << "\nPatient " << i + 1 << ":\n";
            patientList[i].showInfo();
        }
    }

    // Find patients by name
    void findPatient() {
        string searchName;
        cout << "Enter name to search: ";
        getline(cin >> ws, searchName);

        bool found = false;
        for (size_t i = 0; i < patientList.size(); ++i) {
            if (patientList[i].name == searchName) {
                cout << "\nPatient " << i + 1 << ":\n";
                patientList[i].showInfo();
                found = true;
            }
        }

        if (!found) {
            cout << "No patients found with name '" << searchName << "'.\n";
        }
    }
};

int main() {
    Hospital hospital;
    int option;

    do {
        // Show menu
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Show All Patients\n";
        cout << "3. Find Patient\n";
        cout << "4. Exit\n";
        cout << "Enter your option: ";

        // Validate menu choice
        while (!(cin >> option)) {
            cout << "Invalid input. Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (option) {
            case 1:
                hospital.addPatient();
                break;
            case 2:
                hospital.showAllPatients();
                break;
            case 3:
                hospital.findPatient();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (option != 4);

    return 0;
}
