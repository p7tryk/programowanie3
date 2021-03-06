class account
{
 private:
  double m_balance;
  int m_number;
  static double m_interest;
  static int lastAccount;
 public:
  account();
  account(int input);
  double getBalance() const;
  void info() const;
  bool deposit(double amount);
  bool withdraw(double amount);
  bool transferTo(account * acc, double amount);
  void capitalize();
  void capitalize(double amount);
  inline double getInterest() const{ return m_interest;};
  static void setInterest(double interest = 0);
};

account::account()
{
  lastAccount++;
  m_number = lastAccount;
  m_balance = 0;
}
account::account(int input)
{
  m_number = input;
  m_balance = 0;
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
bool account::transferTo(account * target, double amount)
{
  if(!(withdraw(amount)))
    return false;

  target->deposit(amount);

  return true;
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
