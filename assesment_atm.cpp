#include<iostream>
using namespace std;

class Bank {
private:
    int atm_pin;
    int deposit;
    int withdraw;
    int option;
    int balance;
    int pin;
    int choice;
    int attempts;
    int time;

public:
    Bank() : pin(1234), balance(60000), attempts(0) {}

    void inputPin() {
        do {
            cout << "1. Press 1 To Enter ATM Pin" << endl;
            cout << "Press 0 to get help" << endl;
            cout << "Enter Your choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter ATM Pin: ";
                cin >> atm_pin;

                if (atm_pin == pin) {
                    break; 
                } else {
                    cout << "Incorrect pin. Please try again." << endl;
                    attempts++;

                    if (attempts >= 1) {
                        cout << "Too many incorrect attempts. Exiting." << endl;
                        exit(0);
                    }
                }
            }
        } while (true);
    }

    void displayMenu() {
    	  time_t currentTime = time(3:50);
          tm *now = localtime(&currentTime);

        cout << "---------------Welcome to ATM ---------------" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check balance" << endl;
        cout << "4. Exit" << endl;
    }

    void performTransaction() {
        switch(option) {
            case 1:
                cout << "Enter the amount to deposit: ";
                cin >> deposit;
                balance += deposit;
                cout << "Balance after depositing = " << balance << endl;
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> withdraw;
                if (withdraw <= balance) {
                    balance -= withdraw;
                    cout << "Balance after withdrawal: " << balance << endl;
                } else {
                    cout << "Insufficient funds!" << endl;
                }
                break;

            case 3:
                cout << "Balance= " << balance << endl;
                break;

            default:
                cout << "Invalid input" << endl;
        }
    }

    void displayData() {
        do {
            displayMenu();
            cout << "Choose what would you like to do: ";
            cin >> option;

            if (option == 4) {
                break;
            }

            performTransaction();

        } while (true);
    }
};

int main() {
    Bank userAccount;
    userAccount.inputPin();
    userAccount.displayData();

    return 0;
}

