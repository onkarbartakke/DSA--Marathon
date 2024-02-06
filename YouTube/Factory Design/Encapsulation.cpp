#include <iostream>
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
        }
    }

    double getBalance()
    {
        return balance;
    }
};

int main()
{
    BankAccount myAccount;
    myAccount.deposit(1000);
    myAccount.withdraw(500);

    // This will not work because balance is private.
    // cout << myAccount.balance << endl;

    // We can access balance using a public method.
    cout << "Current Balance: $" << myAccount.getBalance() << endl;
    return 0;
}
