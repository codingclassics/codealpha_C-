#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ===== CLASS: Customer =====
class Customer {
private:
    string name;
    string customerID;
    string password;
    int linkedAccountNo;

public:
    void createCustomer() {
        cout << "\nEnter your name: ";
        cin >> name;
        cout << "Enter your ID card number: ";
        cin >> customerID;
        cout << "Create a password: ";
        cin >> password;
        cout << "Enter a new account number (or linked account number if existing): ";
        cin >> linkedAccountNo;

        cout << "\n? Customer created successfully!\n";
        cout << "Name: " << name << "\nID: " << customerID
             << "\nLinked Account No: " << linkedAccountNo << endl;
    }

    int getLinkedAccountNo() const {
        return linkedAccountNo;
    }
};

// ===== CLASS: Account =====
class Account {
private:
    int accountNumber;
    int pin;
    float balance;
    vector<string> transactions; // to store transaction history

public:
    Account() : accountNumber(0), pin(0), balance(0) {}

    void createAccount(int accNo) {
        accountNumber = accNo;
        cout << "\nSet a 4-digit PIN for account " << accountNumber << ": ";
        cin >> pin;
        balance = 0;
        cout << "? Account created successfully!\n";
    }

    void deposit() {
        float amount;
        cout << "\nEnter amount to deposit: ";
        cin >> amount;
        if (amount <= 0) {
            cout << "? Invalid amount.\n";
            return;
        }
        balance += amount;
        transactions.push_back("Deposited " + to_string(amount));
        cout << "? " << amount << " deposited successfully.\n";
    }

    void withdraw() {
        float amount;
        int enteredPin;
        cout << "\nEnter amount to withdraw: ";
        cin >> amount;
        if (amount > balance) {
            cout << "? Insufficient balance.\n";
            return;
        }
        cout << "Enter your PIN: ";
        cin >> enteredPin;
        if (enteredPin == pin) {
            balance -= amount;
            transactions.push_back("Withdrew " + to_string(amount));
            cout << "? " << amount << " withdrawn successfully.\n";
        } else {
            cout << "? Incorrect PIN.\n";
        }
    }

    void transfer(Account &toAccount) {
        float amount;
        int enteredPin;
        cout << "\nEnter amount to transfer: ";
        cin >> amount;
        if (amount > balance) {
            cout << "? Insufficient balance.\n";
            return;
        }
        cout << "Enter your PIN: ";
        cin >> enteredPin;
        if (enteredPin == pin) {
            balance -= amount;
            toAccount.balance += amount;
            transactions.push_back("Transferred " + to_string(amount) + " to Account " + to_string(toAccount.accountNumber));
            toAccount.transactions.push_back("Received " + to_string(amount) + " from Account " + to_string(accountNumber));
            cout << "? Transfer successful!\n";
        } else {
            cout << "? Incorrect PIN.\n";
        }
    }

    void displayAccountInfo() const {
        cout << "\n======= ACCOUNT INFO =======\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    void showTransactions() const {
        cout << "\n======= TRANSACTION HISTORY =======\n";
        if (transactions.empty()) {
            cout << "No transactions yet.\n";
            return;
        }
        for (const auto &t : transactions) {
            cout << "- " << t << endl;
        }
    }

    int getAccountNumber() const { return accountNumber; }
};

// ===== MAIN PROGRAM =====
int main() {
    Customer customer;
    Account account1, account2; // 2 accounts to demonstrate transfers
    int choice;

    cout << "===== SIMPLE BANKING SYSTEM =====" << endl;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Create Customer & Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Money\n";
        cout << "5. Show Account Info\n";
        cout << "6. Show Transactions\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            customer.createCustomer();
            int accNo = customer.getLinkedAccountNo();
            account1.createAccount(accNo);
            break;
        }
        case 2:
            account1.deposit();
            break;
        case 3:
            account1.withdraw();
            break;
        case 4:
            account2.createAccount(2222); // another example account
            account1.transfer(account2);
            break;
        case 5:
            account1.displayAccountInfo();
            break;
        case 6:
            account1.showTransactions();
            break;
        case 7:
            cout << "Exiting program... Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
