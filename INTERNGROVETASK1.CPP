#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    // Constructor to initialize account holder and balance
    BankAccount(string holder, double initialBalance) {
        accountHolder = holder;
        balance = (initialBalance >= 0) ? initialBalance : 0; // Ensure non-negative balance
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }

    // Function to check the balance
    void checkBalance() const {
        cout << "Current balance for " << accountHolder << ": $" << balance << endl;
    }
};

int main() {
    BankAccount myAccount("Alice", 1000.0); // Create account with initial balance
    int choice;
    double amount;

    do {
        // Display menu
        cout << "\n--- Bank Account Menu ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Choose an option (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                myAccount.checkBalance(); // Check balance
                break;
            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                myAccount.deposit(amount); // Deposit money
                break;
            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                myAccount.withdraw(amount); // Withdraw money
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
