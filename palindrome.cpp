#include <iostream>
#include <string.h>
#include <sstream>
#define MAX 50
using namespace std;

class stack
{
 private:
  int length, top, count;
  char data[MAX], entered[MAX];
  void push_data(char element);
  char pop_data();

 public:

  stack()
  {
   top = -1;
   length = 0;
   count = 0;
  }
  void create();

  void check();

  void rev_display();

};

void stack::create()
{
 cout<<"Enter a string: ";
 cin.getline(entered, MAX);
 length = strlen(entered);
}

void stack::push_data(char element)
{
if (top == MAX - 1)
{
 cout <<"Stack Overflow"<<endl;
 return;
}
data[++top] = element;
}

char stack::pop_data()
{
if (top == -1)
{
 cout <<"Stack Underflow!"<<endl;
}
 char temp = data[top--];
 return temp;
}

void stack::check()
{
 for (int i = 0; i<length; i++)
 {
  push_data(entered[i]);
 }
 for (int i = 0; i<length; i++)
 {
  if (entered[i] == pop_data())
  {
   count++;
  }
 }
if (count == length)
 {
   cout<<"String is a palindrome"<<endl;
 
 }
 else
 {
  cout<<"String is NOT a palindrome"<<endl;
 }
}

void stack::rev_display()
{
 string temp = " ";
 for (int i = length - 1; i>= 0; i--)
 {
  temp.push_back(data[i]);
 }
 cout<<"Reverse of string is:  "<<temp<<endl;
}

int main()
{
cout<<"--------------------------------------------------"<<endl;
cout <<"--------------------------------------------------"<<endl;

stack obj;
obj.create();
obj.check();
obj.rev_display();

cout<<"-------------------------------------------------"<<endl;
cout<<"--------------------------------------------------"<<endl;
return 0;
}