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
    Account(string fname, string lname, float balance);
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

long Account::NextAccountNumber=0;
// Bank has multiple accounts, so we retrieve details from file and store it in map container.
class Bank {
    map<long,Account> accounts; // Using map STL to store values from data file. long is basically account number and Account contains account details for the corresponding account number

    public:
    Bank();
    // Functions of Bank Program
    Account OpenAccount(string fname, string lname, float balance);
    Account BalanceEnquiry(long accountNumber);
    Account Deposit(long accountNumber, float amount);
    Account Withdraw(long accountNumber, float amount);
    void CloseAccount(long account);
    void ShowAllAccounts();
    ~Bank();
};


           
           
           
// Defining body of functions

    Account::Account(string fname, string lname, float balance)
    {
     NextAccountNumber++;
     accountNumber=NextAccountNumber;
     firstName=fname;
     lastName=lname;
     this->balance=balance;
    }
    void Account::Deposit(float amount)
    {
        balance+=amount;
    }
    void Account::Withdraw(float amount)
    {
        if(balance-amount<MIN_BALANCE)
        throw InsufficientFunds();
        balance-=amount;
    }
    void Account::setLastAccountNumber(long accountNumber)
    {
        NextAccountNumber = accountNumber;
    }
    long Account::getLastAccountNumber()
    {
        return NextAccountNumber;
    }
    
    // To accept input and output of user defined objects we need to overload insertion and extraction operators

    ofstream & operator<<(ofstream &ofs,Account &acc)
    {
        ofs<<acc.accountNumber<<endl;
        ofs<<acc.firstName<<endl;
        ofs<<acc.lastName<<endl;
        ofs<<acc.balance<<endl;
        return ofs;
    }
    ifstream & operator>>(ifstream &ifs,Account &acc)
    {
        ifs>>acc.accountNumber;
        ifs>>acc.firstName;
        ifs>>acc.lastName;
        ifs>>acc.balance;
        return ifs;
    }
     ostream & operator<<(ostream &os,Account &acc)
    {
        os<<"First Name:"<<acc.getFirstName()<<endl;
        os<<"Last Name:"<<acc.firstName<<endl;
        os<<"Account Number:"<<acc.lastName<<endl;
        os<<"Balance:"<<acc.balance<<endl;
        return os;
    }

Bank::Bank()
{

 Account account;
 ifstream infile;
 infile.open("Bank.data");
 if(!infile)
 {
 //Error File Not Found!!
 return;
 }
 while(!infile.eof())
 {
 infile>>account;
 accounts.insert(pair<long,Account>(account.getAccNo(),account));
 }
 Account::setLastAccountNumber(account.getAccNo());

 infile.close();

}
Account Bank::OpenAccount(string fname,string lname,float balance)
{
 ofstream outfile;
 Account account(fname,lname,balance);
 accounts.insert(pair<long,Account>(account.getAccNo(),account));

 outfile.open("Bank.data", ios::trunc);

 map<long,Account>::iterator itr;
 for(itr=accounts.begin();itr!=accounts.end();itr++)
 {
 outfile<<itr->second;
 }
 outfile.close();
 return account;
}
Account Bank::BalanceEnquiry(long accountNumber)
{
 map<long,Account>::iterator itr=accounts.find(accountNumber);
 return itr->second;
}
Account Bank::Deposit(long accountNumber,float amount)
{
 map<long,Account>::iterator itr=accounts.find(accountNumber);
 itr->second.Deposit(amount);
 return itr->second;
}
Account Bank::Withdraw(long accountNumber,float amount)
{
 map<long,Account>::iterator itr=accounts.find(accountNumber);
 itr->second.Withdraw(amount);
 return itr->second;
}
void Bank::CloseAccount(long accountNumber)
{
 map<long,Account>::iterator itr=accounts.find(accountNumber);
 cout<<"Account Deleted"<<itr->second;
 accounts.erase(accountNumber);
}
void Bank::ShowAllAccounts()
{
 map<long,Account>::iterator itr;
 for(itr=accounts.begin();itr!=accounts.end();itr++)
 {
 cout<<"Account "<<itr->first<<endl<<itr->second<<endl;
 }
}
Bank::~Bank()
{
 ofstream outfile;
 outfile.open("Bank.data", ios::trunc);

 map<long,Account>::iterator itr;
 for(itr=accounts.begin();itr!=accounts.end();itr++)
 {
 outfile<<itr->second;
 }
 outfile.close();
}

