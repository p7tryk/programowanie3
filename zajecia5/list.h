#include "account.h"

class accountList{
 private:
  account * m_begin;
  account * m_end;
  int m_size;
 public:
  accountList();
  ~accountList();
  int getSize();
  void addBegin(account * accountptr);
  void addEnd(account * accountptr);
  void info();
  void printall();
  void removeall();
  int remove(account * ptr);
  account * findByNum(int number) const;
};

accountList::accountList()
{
  m_begin = m_end = nullptr;
  m_size = 0;
}
accountList::~accountList()
{
  printf("destruktor ");
  removeall();
}
void accountList::removeall()
{
  if(m_size=0)
    return;
  printf("removing\n");
  account * ptr;
  account * ptr_next;
  for(int i=0;i<m_size;i++)
    {
      ptr=m_begin;
      ptr_next=ptr->m_next;
      delete ptr;
    }
  m_begin=m_end=nullptr;
  m_size=0;
}
int accountList::getSize()
{
  return m_size;
}
void accountList::addBegin(account * accountptr)
{
  
  accountptr->m_next = m_begin;
  accountptr->m_prev = nullptr;
  m_begin = accountptr;
  
  if(m_end==nullptr)
    {
      m_end = accountptr;
    }
  else
    accountptr->m_next->m_prev = accountptr;
   
  m_size++;
}
void accountList::addEnd(account * accountptr)
{
  
  accountptr->m_prev = m_end;
  accountptr->m_next = nullptr;
  m_end = accountptr;
  
  if(m_begin==nullptr)
    {
      m_begin = accountptr;
    }
  else
    accountptr->m_prev->m_next = accountptr;
   
  m_size++;
}

void accountList::info()
{
 
  printf("begin = %p, end = %p\n",m_begin,m_end);
}
void accountList::printall()
{
  account * ptr = m_begin;
  for(int i=0;i<m_size;i++)
    {
      printf("this = %p, prev = %p, next = %p\n",ptr,ptr->m_prev,ptr->m_next);
      ptr->info();
      ptr = ptr->m_next;
    }
}
account * accountList::findByNum(int number) const
{
   account * ptr = m_begin;
  for(int i=0;i<m_size;i++)
    {
      if(ptr->m_number==number)
	{
	  return ptr;
	}
      ptr = ptr->m_next;
    }
  printf("nie ma takiego konta\n");
  return nullptr;
}
int accountList::remove(account * ptr)
{
  if(ptr->m_next==nullptr)
    {
      m_end=ptr->m_prev;
      ptr->m_next=ptr;
    }
  else
    ptr->m_next->m_prev=ptr->m_prev;
  if(ptr->m_prev==nullptr)
    {
      m_begin=ptr->m_next;
      ptr->m_prev=ptr;
    }
  else
    ptr->m_prev->m_next=ptr->m_next;
  
  delete ptr;
  m_size--;
  return m_size;
}
