#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
private:
    string username;
    string password;

public:
    void registerUser() {
        cout << "\nEnter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (isUserExist(username)) {
            cout << "? Username already exists. Try another.\n";
            return;
        }

        ofstream file("users.txt", ios::app);
        if (!file) {
            cout << "Error opening file.\n";
            return;
        }
        file << username << " " << password << endl;
        file.close();
        cout << "? Registration successful!\n";
    }

    void loginUser() {
        string uname, pass;
        cout << "\nEnter username: ";
        cin >> uname;
        cout << "Enter password: ";
        cin >> pass;

        ifstream file("users.txt");
        if (!file) {
            cout << "No users registered yet.\n";
            return;
        }

        string u, p;
        bool found = false;
        while (file >> u >> p) {
            if (u == uname && p == pass) {
                found = true;
                break;
            }
        }
        file.close();

        if (found)
            cout << "? Login successful! Welcome, " << uname << "!\n";
        else
            cout << "? Invalid username or password.\n";
    }

private:
    bool isUserExist(const string& uname) {
        ifstream file("users.txt");
        if (!file) return false;

        string u, p;
        while (file >> u >> p) {
            if (u == uname) return true;
        }
        return false;
    }
};

int main() {
    User user;
    int choice;

    while (true) {
        cout << "\n====== LOGIN & REGISTRATION SYSTEM ======\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                user.registerUser();
                break;
            case 2:
                user.loginUser();
                break;
            case 3:
                cout << "Exiting program... Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
