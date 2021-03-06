#include "banking.h"

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
} //end of main
           
