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

long Account::NextAccountNumber=0;

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

int main()
{
    Bank b; // Creating object of bank class
    Account acc; // Creating object of account class
    int choice;
    string fname, lname;
    long accountNumber;
    float balance;
    float amount;
    cout<< "# # # Hastrix Bank # # #";
    do{
    cout<<"\n\tSelect one option from below set of options";
    cout<<"\n\t1 Open Account";
    cout<<"\n\t2 Enquire Balance";
    cout<<"\n\t3 Deposit Money";
    cout<<"\n\t4 Withdraw Money";
    cout<<"\n\t5 Close Account";
    cout<<"\n\t6 Display details of all accounts";
    cout<<"\n\t7 Quit";
    cout<<"\nEnter your choice";
    cin>>choice;
    switch(choice)
    {
        case 1: 
         cout<<"Enter first name: ";
         cin>>fname;
         cout<<"Enter last name: ";
         cin>>lname;
         cout<<"Enter initial balance";
         cin>>balance;
         acc = b.OpenAccount(fname, lname, balance);
         cout<<endl<<"Account created successfully!!"<<endl;
         cout<<acc;
         break;

         case 2: 
          cout<<"Enter Account Number";
          cin>>accountNumber;
          acc=b.BalanceEnquiry(accountNumber);
          cout<<endl<<"Total Balance in Account along with details:"<<endl;
          cout<<acc;
          break;

          case 3:
          cout<<"Enter Account Number";
          cin>>accountNumber;
          cout<<"Enter Balance: ";
          cin>>amount;
          acc=b.Deposit(accountNumber, amount);
          cout<<endl<<"Amount is deposited successfully!!"<<endl;
          cout<<acc;
          break;

          case 4: 
          cout<<"Enter Account Number:";
          cin>>accountNumber;
          cout<<"Enter Balance:";
          cin>>amount;
          acc=b.Withdraw(accountNumber, amount);
          cout<<endl<<"Amount withdrawn"<<endl;
          cout<<acc;
          break;

          case 5: 
           cout<<"Enter Account Number";
           cin>>accountNumber;
           b.CloseAccount(accountNumber);
           cout<<endl<<"Account is closed!!"<<endl;
           cout<<acc;

           case 6: 
           b.ShowAllAccounts();
           break;

           case 7: break;

           default: cout<<"\n Enter correct choice!!";
           exit(0);
           }} while(choice!=7);
           return 0;
           }

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
    








}
