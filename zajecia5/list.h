#pragma once 
#include "account.h"
#include <fstream>
#include <iostream>
#include "student.h"
#include "vipaccount.h"

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
  void capitalize();
  account * findByNum(int number) const;
  account * getBegin() {return m_begin;};
  account * getEnd() {return m_end;};
  account * getNext(account * ptr) {return ptr->m_next;};
  account * getPrev(account * ptr) {return ptr->m_prev;};
  bool writeFile(const char * filename);
  bool readFile(const char * filename);
};
//test
accountList::accountList()
{
  m_begin = m_end = nullptr;
  m_size = 0;
}
accountList::~accountList()
{
  printf("destruktor\n");
  removeall();
}
void accountList::removeall()
{
  if(m_size==0)
    return;
  printf("removing\n");
  //info();
  account * ptr;
  account * ptr_next;
  int freed = 0;
  for(int i=0;i<m_size;i++)
    {
      ptr=m_begin;
      ptr_next=ptr->m_next;
      delete ptr;
      freed++;
    }
  m_begin=m_end=nullptr;
  m_size=0;
  printf("\nremoved %d records,freed %ld bytes\n", freed, freed*sizeof(account));
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
 
  printf("\nbegin = %p, end = %p\n",m_begin,m_end);
}
void accountList::printall()
{
  account * ptr = m_begin;
  for(ptr = m_begin;ptr;ptr=ptr->m_next)
    {
      printf("this = %p, prev = %p, next = %p\n",ptr,ptr->m_prev,ptr->m_next);
      ptr->info();
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
  printf("%p\n",ptr);
  free(ptr);
  m_size--;
  return m_size;
}
void accountList::capitalize()
{
  account * ptr = m_begin;
  for(ptr = m_begin;ptr;ptr=ptr->m_next)
    {
      ptr->capitalize();
    }
}

bool accountList::writeFile(const char * filename)
{
  printf("\nwriting to %s\n", filename);
  FILE * file = fopen(filename,"w");
  int written = 0;
  if(file == NULL)
    {
      printf("couldnt write to %s\n",filename);
      return false;
    }
  //iostream jest GLUPIE
  for(account * ptr = m_begin;ptr;ptr=ptr->m_next)
    {
      ptr->write(file);
      written++;
    }
  printf("written %d records\n\n", written);
  fclose(file);
}
bool accountList::readFile(const char * filename)
{
  printf("\nreading from %s\n", filename);
  FILE * file = fopen(filename,"r");
  if(file == NULL)
    {
      printf("couldnt read from %s\n",filename);
      return false;
    }
  //iostream jest GLUPIE
  char  mode = 0;
  int  accnumber = 0;
  double  balance = 0;
  int read =0;
  account * ptr = nullptr;
  
  while(true)
    {
      if(fscanf(file,"%c%d%lf\n",&mode,&accnumber,&balance) ==EOF)
	break;
      read++;
      switch(mode)
	{
	case 's':
	  ptr = new studentAccount(balance,accnumber);
	  this->addBegin(ptr);
	  break;
	  
	case 'v':
	  ptr = new vipAccount(balance,accnumber);
	  this->addBegin(ptr);
	  break;
	}
      
    }
  printf("read %d records\n\n",read);
  fclose(file);
}

