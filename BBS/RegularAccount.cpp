/**
 * This code defines a C++ class called RegularAccount, which is a subclass of the Account class. 
 * It represents a regular bank account with standard functionalities. This class overrides the print 
 * method to provide specific information about the account type.
 **/

#include "RegularAccount.h"

// Constructor definition for RegularAccount class, initializes using Account constructor
RegularAccount::RegularAccount(string nam, double amnt, Date d) : Account(nam, amnt, d) {}

void RegularAccount::print() const {
    
    cout << "Regular account, "; 
    this->Account::print(); // Call the base class print method to print general account information
}