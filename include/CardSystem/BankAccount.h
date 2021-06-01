#ifndef CardSystem_BankAccount_INCLUDED
#define CardSystem_BankAccount_INCLUDED

class BankAccount {
public:
    BankAccount() = delete;
    explicit BankAccount(int balance);

    int balance() const;
    void withdrawal(int value);

private:
    int _balance;

};

#endif
