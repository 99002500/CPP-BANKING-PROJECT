// Include header files
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

#define MIN_BALANCE 500

class InsufficientFunds {}; // Class for insufficient balance

class Account {
    // Variables required for the program!!
    long accountNumber;
    string firstName;
    string lastName;
    float balance;
    static long NextAccountNumber;
  // We define default, parameterized constructors now. To access private variables we use getter and setter methods
    public:
// Defining constructors
    Account(){}
    Account(string fname, string lname, float balance)
    //Defining getter methods
    long getAccNo(){return accountNumber;}
    string getFirstName(){return firstName;}
    string getLastName(){return lastName;}
    float getBalance(){return balance;}

    // Defining functions of the bank program

    void Deposit(float amount);
    void Withdraw(float amount);
    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();
    // Overloading operators
    friend ofstream & operator<<(ofstream &ofs, Account &acc);
    friend ifstream & operator>>(ifstream &ifs, Account &acc);
    friend ostream & operator<<(ostream &os, Account &acc);
};








}
