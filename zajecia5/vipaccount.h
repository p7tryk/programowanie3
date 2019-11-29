#include "account.h"

class vipAccount : public account{
 private:
  static double m_interest;
 public:
  vipAccount(double amount =0);
  ~vipAccount();    
  bool withdraw(double amount);
  void info() const;
  bool transferTo(account * target, double amount, double comm = 0.5);
  inline double getInterest() const{ return m_interest;};
  static void setInterest(double interest = 0);
  void capitalize();
};

vipAccount::vipAccount(double amount) : account(amount)
{

}
vipAccount::~vipAccount()
{

}

bool vipAccount::withdraw(double amount)
{
  return account::withdraw(amount+0.1);  
}
void vipAccount::info() const
{
  printf("konto student ");
  account::info();
}
bool vipAccount::transferTo(account * target, double amount, double comm)
{
  return this->account::transferTo(target, amount, comm);
}

void vipAccount::setInterest(double interest)
{
  vipAccount::m_interest = interest;
}
void vipAccount::capitalize()
{
  m_balance *= 1. + vipAccount::m_interest/100;
}
