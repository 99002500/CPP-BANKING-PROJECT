#include "banking.h"
#include <gtest/gtest.h>
/*
TEST(Account,DefaultConstructor) {
    Account a1;
    EXPECT_EQ(0.0,a1.getBalance());
   
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
*/
//#define _CMAKE_

#ifdef DEBUG
#define debug(msg) std::cout << msg << std::endl    
#else
#define debug(msg) " "
#endif

#ifdef _CMAKE_
#include "banking.cc"
#endif

TEST(Account,CreditTest) {
    debug("Credit Test");
    Account a1("sam","Lippman",5000.0);
    a1.Deposit(3000);
    EXPECT_EQ(8000.0,a1.getBalance());

}

TEST(Account,DebitTest) {
    Account a1("sam","Lippman",5000.0);
    a1.Withdraw(1200);
    EXPECT_EQ(3800.0,a1.getBalance());
}
TEST(Account,TransactionTest) {
    Account a1("sam","Lippman",5000.0);
    a1.Withdraw(1200);
    a1.Deposit(3400);
    a1.Withdraw(2000);
    a1.Deposit(3000);
    EXPECT_EQ(8200.0,a1.getBalance()) << "Invalid Balance";
}



