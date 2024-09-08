#include <iostream>
#include <iomanip>
#include "Date.h"
#include "PremiumAccount.h"
#include "RegularAccount.h"

using namespace std;

int main()
{
    int userInput = 0, numAcc = 0, accountNum = 0, idx = 0; 
    double amountNum = 0.0; 
    
    string name = "";
    string date = "";

    const int MAX_NUM_ACCOUNTS = 5;
    Account *accountArray[MAX_NUM_ACCOUNTS];
    Date *subDate = new Date;
    subDate->set(0, 0, 0, 0);

    while (userInput != 6)
    {
        cout << "\n1->Create regular accnt, 2->Create premium accnt, 3->Deposit to accnt\n";
        cout << "4->Withdraw from accnt, 5->Print info accnts, 6->Quit\n";
        cin >> userInput;

        if (userInput == 1)
        {
            if (numAcc >= MAX_NUM_ACCOUNTS)
            {
                cout << "Max number of accounts reached, cannot add a new account\n";
            }
            else
            {
                cout << "Enter owner's name: ";
                cin >> name;
                cout << "Enter date, in the mm/dd/yyyy/hh format: ";
                cin >> date;
                cout << "Enter amount: ";
                cin >> amountNum;

                if (amountNum <= 0)
                {
                    cout << "Amount cannot be negative, account creation not executed\n";
                }
                else
                {
                    Date *tempDay = new Date;
                    tempDay->set(0, 0, 0, 0);
                    RegularAccount *newAcc = new RegularAccount(name, amountNum, *tempDay);

                    accountArray[numAcc] = newAcc;
                    numAcc++;
                    cout << "Account created: \n";
                    newAcc->print();
                }
            }
        }
        else if (userInput == 2)
        {
            if (numAcc >= MAX_NUM_ACCOUNTS)
            {
                cout << "Max number of accounts reached, cannot add a new account\n";
            }
            else
            {
                cout << "Enter owner's name: ";
                cin >> name;
                cout << "Enter date, in the mm/dd/yyyy/hh format: ";
                cin >> date;
                cout << "Enter amount: ";
                cin >> amountNum;

                if (amountNum <= 0)
                {
                    cout << "Amount cannot be negative, account creation not executed\n";
                }
                else if (amountNum < 1000)
                {
                    cout << "Insufficient amount, you need at least 1000.00 Galactic units to open a premium account\n";
                }
                else
                {
                    accountArray[numAcc] = new PremiumAccount(name, amountNum, *subDate);

                    cout << "Account created: \n";
                    accountArray[numAcc]->print();
                    numAcc++;
                }
            }
        }
        else if (userInput == 3)
        {
            cout << "Enter account number: ";
            cin >> accountNum;

            idx = -1;  
            for (int i = 0; i < numAcc; i++)
            {
                if (accountNum == accountArray[i]->getAccountNumber())
                {
                    idx = i;  
                    break;
                }
            }

            if (idx == -1)
            {  
                cout << "No such account\n";
            }
            else
            {
                cout << "Enter date, in the mm/dd/yyyy/hh format: ";
                cin >> date;
                cout << "Enter amount: ";
                cin >> amountNum;

                if (accountArray[idx]->deposit(amountNum, *subDate))
                {
                    cout << "Deposit executed: \n";
                    accountArray[idx]->print();
                }
                else
                {
                    cout << "Amount cannot be negative, deposit not executed\n";
                }
            }
        }
        else if (userInput == 4)
        {
            cout << "Enter account number: ";
            cin >> accountNum;

            bool accountExists = false;
            int i = 0;

            while (i < numAcc && !accountExists)
            {
                if (accountNum == accountArray[i]->getAccountNumber())
                {
                    accountExists = true;
                }
                else
                {
                    i++;
                }
            }

            if (accountExists)
            {
                cout << "Enter date, in the mm/dd/yyyy/hh format: ";
                cin >> date;
                cout << "Enter amount: ";
                cin >> amountNum;

                if (amountNum < 0)
                {
                    cout << "Amount cannot be negative, withdraw not executed\n";
                }
                else if (accountArray[i]->withdraw(amountNum, *subDate))
                {
                    cout << "Withdraw executed: \n";
                    accountArray[i]->print();
                }
                else
                {
                    cout << "Insufficient balance, withdrawal not executed\n";
                }
            }
            else
            {
                cout << "No such account\n";
            }
        }
        else if (userInput == 5)
        {
            cout << "Accounts\n========\n";
            for (int i = 0; i < numAcc; i++)
            {
                cout << endl;
                accountArray[i]->print();
            }
        }
    }

    delete subDate;
    subDate = nullptr;
    
    return 0; 
}