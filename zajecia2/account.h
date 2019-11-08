class account
{
 private:
  double m_balance;
  int m_number;
  
 public:
  account();
  account(int input);
  double getBalance();
  void info();
  bool deposit(double amount);
  bool withdraw(double amount);
  bool transferTo(account * acc, double amount);
};

account::account()
{
  m_number = 0;
  m_balance = 0;
}
account::account(int input)
{
  m_number = input;
  m_balance = 0;
  
}

double account::getBalance()
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
void account::info()
{
  printf("#%d ma %.2lf\n", m_number,m_balance);
}

bool account::withdraw(double amount)
{
  if(amount<0)
    return false;
  if(amount>getBalance())
    return false;
  m_balance -= amount;
}
bool account::transferTo(account * target, double amount)
{
  if(amount<0)
    return false;
  if(amount>getBalance())
    return false;
  m_balance -= amount;

  target->deposit(amount);

}
