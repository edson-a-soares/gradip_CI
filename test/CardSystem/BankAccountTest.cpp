#include "gtest/gtest.h"
#include "CardSystem/BankAccount.h"
#include "CardSystem/InsufficientBalanceException.h"

TEST(BankAccountTest, WithdrawalWithSuccess)
{
    BankAccount account(100);

    ASSERT_EQ(account.balance(), 100);

    account.withdrawal(25);
    ASSERT_EQ(account.balance(), 75);

    account.withdrawal(25);
    ASSERT_EQ(account.balance(), 50);

    account.withdrawal(25);
    ASSERT_EQ(account.balance(), 25);

    account.withdrawal(25);
    ASSERT_EQ(account.balance(), 0);
}

TEST(BankAccountTest, WithdrawalWithInsufficientBalanceException)
{
    BankAccount account(100);

    ASSERT_EQ(account.balance(), 100);
    ASSERT_THROW(account.withdrawal(150), InsufficientBalanceException);
}
