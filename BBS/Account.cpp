/** 
 * This code defines a class called Account, which represents a bank account. It includes functionalities to create an account, deposit and withdraw funds, 
 * and print account information. Additionally, it maintains a count of the total number of accounts created.
 **/

#include "Account.h" // Include the header file containing the declaration of the Account class
#include <iomanip> 

 // Initialize the static member variable numberAccounts
int Account::numberAccounts = 0;

// Constructor definition for Account class, initializes member variables
Account::Account(string nam, double bal, Date d) : ownerName(nam), balance(bal), transactionHistory(nullptr), numberTransactions(0) {
    // Increment and assign account number
    accountNumber = ++numberAccounts + 999; 
}

// Withdraw method definition, subtracts amount from balance if sufficient funds are available
bool Account::withdraw(double amount, Date) {
    
    if (balance >= amount) { // Check if there are sufficient funds
        balance -= amount; // Deduct amount from balance
        return true; // Return true indicating successful withdrawal
    }
    return false; // Return false indicating insufficient funds
}

// Deposit method definition, adds amount to balance if amount is positive
bool Account::deposit(double amount, Date) {
    
    if (amount > 0) { // Check if amount is positive
        balance += amount; // Add amount to balance
        return true; // Return true indicating successful deposit
    }
    return false; // Return false indicating invalid deposit amount
}

 // Method to get the account number
int Account::getAccountNumber() const {
   
    return accountNumber; // Return the account number
}

// Method to get the current balance
double Account::getBalance() const {
    
    return balance; // Return the current balance
}

// Method to get the total number of accounts
int Account::getNumberAccounts() {
    
    return numberAccounts; // Return the total number of accounts
}

// Method to print account information
void Account::print() const {
    
    // Output account number, owner name, and balance with proper formatting
    cout << "#: " << accountNumber << ", Name: " << ownerName << ", Balance: " << fixed << setprecision(2) 
    << balance << " Galactic units\n";
    
}