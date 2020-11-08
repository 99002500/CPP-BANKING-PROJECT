#include "banking.cc"
#include <gtest/gtest.h>

TEST(Account,CreditTest) {
    Account a1("sam","Lippman",5000.0);
    a1.Deposit(3000);
    EXPECT_EQ(8000.0,a1.getBalance());

}
/*
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
TEST(Account,DisplayTest) {
    Account a1("sam","Lippman",5000.0);
    std::string ExpectedOut="1001,Lippman,5000\n";
    testing::internal::CaptureStdout();
    a1.BalanceEnquiry(1001);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
*/