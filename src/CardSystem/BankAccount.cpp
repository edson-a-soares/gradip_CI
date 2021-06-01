#include "CardSystem/BankAccount.h"
#include "CardSystem/InsufficientBalanceException.h"

BankAccount::BankAccount(int balance)
    : _balance(balance)
{}

int BankAccount::balance() const
{
    return _balance;
}

void BankAccount::withdrawal(int value)
{
    if (value > _balance)
        throw InsufficientBalanceException();

    _balance -= value;
}
