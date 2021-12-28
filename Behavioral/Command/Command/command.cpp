#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct BankAccount
{ 
  int balance = 0;
  int overdraft_limit = -500;

  void deposit(int amount)
  {
    balance += amount;
    cout << "deposited " << amount << ", balance now " << 
      balance << "\n";
  }

  void withdraw(int amount)
  {
    if (balance - amount >= overdraft_limit)
    {
      balance -= amount;
      cout << "withdrew " << amount << ", balance now " << 
        balance << "\n";
    }
  }
};

struct Command
{
  virtual ~Command() = default;
  virtual void call() const = 0;
  virtual void undo() const = 0;
};

struct BankAccountCommand : Command
{
  BankAccount& account;
  enum Action { deposit, withdraw } action;
  int amount;

  BankAccountCommand(BankAccount& account, 
    const Action action, const int amount)
    : account(account), action(action), amount(amount) {}

  void call() const override
  {
    switch (action)
    {
    case deposit:
      account.deposit(amount);
      break;
    case withdraw: 
      account.withdraw(amount);
      break;
    default: break;
    }
  }

  void undo() const override
  {
    switch (action)
    {
    case deposit:
      account.withdraw(amount);
      break;
    case withdraw:
      account.deposit(amount);
      break;
    default: break;
    }
  }
};


int main()
{
  BankAccount ba;

  vector<BankAccountCommand> commands{
    BankAccountCommand{ba, BankAccountCommand::deposit, 100},
    BankAccountCommand{ba, BankAccountCommand::withdraw, 200}
  };

  cout << ba.balance << endl;

  for (auto& cmd : commands)
    cmd.call();

  for (auto it = commands.rbegin(); it != commands.rend(); ++it)
    it->undo();


  cout << ba.balance << endl;

  getchar();
  return 0;
}
