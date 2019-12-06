#pragma once



class account
{
 protected:
  double m_balance;
  int m_number;
  friend class accountList;
 private:
  static double m_interest;
  static int lastAccount;
  account * m_next;
  account * m_prev;
 public:
  account();
  account(double amount);
  double getBalance() const;
  virtual void info() const;
  bool deposit(double amount);
  bool withdraw(double amount);
  bool transferTo(account * target, double amount, double comm = 0);
  void capitalize();
  void capitalize(double amount);
  double getInterest() const{ return m_interest;};
  static void setInterest(double amount = 0);
};

account::account(double amount = 0)
{
  lastAccount++;
  m_number = lastAccount;
  m_balance = amount;
  m_interest = 0;
}

double account::getBalance() const
{
  return m_balance;
}

bool account::deposit(double amount)
{
  if(amount<0)
    return false;
  m_balance+=amount;
  return true;
}
void account::info() const
{
  printf("#%d ma %.2lf€\n", m_number,m_balance);
}

bool account::withdraw(double amount)
{
  if(amount<0)
    return false;
  if(amount>getBalance())
    return false;
  m_balance -= amount;
  return true;
}
bool account::transferTo(account * target, double amount, double comm)
{
  if(account::withdraw(amount+comm))
    return target->deposit(amount);
  return false;
}
void account::capitalize()
{
  m_balance *= 1. + m_interest/100;
}
void account::capitalize(double amount)
{
  m_balance *= 1. + amount/100;
}

void account::setInterest(double amount)
{
  m_interest = amount;
}





