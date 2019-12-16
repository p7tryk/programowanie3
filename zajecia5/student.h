#pragma once
#include "account.h"

class studentAccount : public account{
 private:
  static double m_interest;
  friend class accountList;
 protected:
  studentAccount(double amount, int accnumber);
 public:
  studentAccount(double amount =0);
  ~studentAccount();    
  bool withdraw(double amount);
  virtual void info() const;
  bool transferTo(account * target, double amount, double comm = 2);
  inline double getInterest() const{ return m_interest;};
  static void setInterest(double interest = 0);
  virtual void capitalize();
  virtual void write(FILE * file) const;
};

studentAccount::studentAccount(double amount) : account(amount)
{

}
studentAccount::~studentAccount()
{

}

bool studentAccount::withdraw(double amount)
{
  return account::withdraw(amount+1);  
}
void studentAccount::info() const
{
  printf("konto student ");
  account::info();
}
bool studentAccount::transferTo(account * target, double amount, double comm)
{
  return this->account::transferTo(target, amount, comm);
}

void studentAccount::setInterest(double interest)
{
  m_interest = interest;
}
void studentAccount::capitalize()
{
  m_balance *= 1. + m_interest/100;
}
void studentAccount::write(FILE * file) const
{
  fprintf(file, "s\t%d\t%0.2lf\n",m_number,getBalance());
}

