#include <iostream>
#include "color.hpp"
using namespace std;

class ATM {
    public:
        int option;
        double balance = 500;
        double depositAmount;
        double withdrawAmount;

        void showMenu();
        void checkbalance();
        void deposit();
        void withdraw();
};

void ATM::showMenu() {
    cout << "********** ATM **********" << "\n\n";
    cout << "1. Check Balance" << '\n';
    cout << "2. Deposit" << '\n';
    cout << "3. Withdraw" << '\n';
    cout << "4. Exit" << "\n\n";
    cout << "**************************" << "\n\n";
}

void ATM::checkbalance() {
    cout << "Your balance is: " << balance << " $\n\n";
}

void ATM::deposit() {
    cout << "Please enter the deposit amount: ";
    cin >> depositAmount;

    balance += depositAmount;

    cout << "\nDeposited successfully. Your balance now is " << balance << " $\n\n";
}

void ATM::withdraw() {
    cout << "Please enter the withdraw amount: ";
    cin >> withdrawAmount;

    if (balance > withdrawAmount) {
        balance -= withdrawAmount;
        cout << "\nWithdraw successfully. Your balance now is " << balance << " $\n\n";
    }
    else {
        cout << dye::colorize("Not enough money", "light_red") << "\n\n";
    }
}

int main() {
    ATM atm;

    do {
        atm.showMenu();

        cout << "Please choose an option: ";
        cin >> atm.option;
        cout << '\n';

        system("cls");

        if (atm.option < 0 || atm.option > 4)  {
            cout << dye::colorize("Invalid option", "light_red") << "\n\n";
        }

        switch (atm.option) {
        case 1:
            atm.checkbalance();
            break;
        case 2:
            atm.deposit();
            break;
        case 3:
            atm.withdraw();
            break;
        }     
    } while (atm.option != 4);

    system("exit");
}
