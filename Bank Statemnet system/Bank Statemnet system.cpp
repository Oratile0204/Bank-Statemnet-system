// Bank Statemnet system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder; // Stors the name of the account holder.
    double balance;       // Stors the account balnce.

public:
    //Constructor using a list of intializer
    BankAccount(string name, double initialBalance)
        : accountHolder(name), balance(initialBalance) {
    }

    // this method will be used  to depost money then increment your current balance
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
        }
        else {
            cout << "Eror: Deposit amount must be postive." << endl;
        }
    }

    // this step is on how  to withdrw money
    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
            }
            else {
                cout << "Errror: Insufficient balnce." << endl;
            }
        }
        else {
            cout << "Errror: Withdrawal amount must be positive." << endl;
        }
    }

    // step on how  to dispaly account balance
    void displayBalance() const {
        cout << "Account Holder: " << accountHolder << " | Balance: " << balance << endl;
    }
};

// Function to demonstrate the BankAccount functinality with user input
void bankAccountManagement() {
    string name;
    double initialBalance;

    // Prompt for account holders name and initial balnce
    cout << "Enter account holder's name: ";
    getline(cin, name);
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(name, initialBalance); // Creae a new account
    account.displayBalance();

    int choice;
    double amount;

    do {
        // Display menue
        cout << "\nMenu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter deposit amount: ";
            cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            account.displayBalance();
            break;
        case 4:
            cout << "Exiting the program. Goodby!\n";
            break;
        default:
            cout << "Invalid chice. Please try again.\n";
        }
    } while (choice != 4);
}

// Main funtion to run the program
int main() {
    bankAccountManagement(); // Call the funtion to manage the account interactively
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
