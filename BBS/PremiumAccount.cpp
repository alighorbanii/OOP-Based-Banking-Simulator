/**
 * This code defines a class called PremiumAccount, which is a subclass of the Account class. It represents a premium bank account with additional functionalities compared 
 * to a standard account, such as maintaining a minimum balance requirement. This class overrides the withdraw method to enforce the minimum balance constraint and provides a 
 * method to retrieve the minimum balance value. Additionally, it overrides the print method to provide specific information about the account type.
 */

#include "PremiumAccount.h" 

// Initialize the static constant MIN_BALANCE
const double PremiumAccount::MIN_BALANCE = 1000; 

// Constructor definition for PremiumAccount class, initializes using Account constructor
PremiumAccount::PremiumAccount(string nam, double amnt, Date d) : Account(nam, amnt, d) {}

bool PremiumAccount::withdraw(double amnt, Date d) {
    // Method to withdraw funds from the premium account, considering the minimum balance
    if (balance - amnt >= MIN_BALANCE) { // Check if withdrawal maintains the minimum balance
        balance -= amnt; // Deduct amount from balance
        return true; // Return true indicating successful withdrawal
    }
    return false; // Return false indicating insufficient funds or violating minimum balance
}

double PremiumAccount::getMinBalance() {
    return MIN_BALANCE; // Return the minimum balance value
}

void PremiumAccount::print() const {
    
    cout << "Premium account, "; // Print that its a premium account
    this->Account::print(); // Call the base class print method to print general account information
}