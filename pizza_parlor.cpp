#include<iostream>
#define MAX 20
using namespace std;

struct Pizza_Parlor
{
 int order_id[MAX], front, rear;
 string orderer_name[MAX];
};

class queue_functions
{
 private:
 struct Pizza_Parlor q;
 bool isempty()
 {
  return (q.rear == -1) ? true : false;
 }

 bool isfull()
 {
  return ((q.rear + 1) % MAX == q.front) ? true : false;
 }

public:
 queue_functions()
 {
  q.front = q.rear = -1;
 }

 void display()
 {
  if (isempty())
  {
    cout<<"Cafe is EMPTY!!!"<<endl;
  }
  else
  {
  int i = q.front;
  while (i != q.rear + 1)
  {
   cout<<"Order Id: "<< q.order_id[i] << "Orderer Name: "<< q.orderer_name[i]<<endl;

   i = (i + 1) % MAX;
  }
 }
}

void place_order() 
 {
 if (isfull())
 {
  cout<<"Orders are FULL!!! New orders are not possible!!"<<endl;
 }
 else if (isempty())
 {
 int id;
 string name;
 cout<<"Enter Order ID: ";
 cin>>id;
 cout<<"Enter Orderer Name: ";
 cin>>name;
 q.front = q.rear = 0;
 q.order_id[q.rear] = id;
 q.orderer_name[q.rear] = name;
 cout <<"Order Placed successfully"<<endl;
 cout<<endl;
 display();
}
 else
 {
  int pos = (q.rear + 1) % MAX;
  if (pos == q.front)
  {
     cout<<"Cafe is Full!!"<<endl;
  }
  else
  {
  int id;
  string name;
  cout<<"Enter Order ID: ";
  cin>>id;
  cout<<"Enter Orderer Name: ";
  cin>>name;
  q.rear = pos;
  q.order_id[q.rear] = id;
  q.orderer_name[q.rear] = name;
  cout<<endl;
  display();
  }
 } 
}

void serve_order()
{
 if (isempty())
 {
  cout<<"No orders to Serve!!"<<endl;
 }
 else
 {
  cout<<"Order Id: "<< q.order_id[q.front] <<"Orderer Name: "<< q.orderer_name[q.front]<<endl;

  if (q.front == q.rear)
  {
   q.front = q.rear = -1; 
  }
  else
  {
   q.front = (q.front + 1) % MAX; 
  }
    cout<<"Order Served successfull"<<endl;
    cout<<endl;
    display(); 
    }
   }
};

int main()
{
 queue_functions obj;
 int choice;

 cout<<"\n-----------------PizzaParlor Menu-----------------"<<endl;
 do

  cout<<"--------------------------------------------------"<<endl;
  cout<<"Place Order "<<endl;
  cout<<"Serve Order " <<endl;
  cout<<"3.Display order_id"<<endl;
  cout<<"4.Exit" <<endl;
  cout<<"--------------------------------------------------"<<endl;
  cout<<"Enter your choice: ";
  cin>> choice;
  cout<<"--------------------------------------------------"<<endl;

  switch (choice)
  {
   case 1:
    obj.place_order();
    break;
   case 2:
     obj.serve_order();
     break;
    case 3:
     obj.display();
     break;
    default:
     break;
  }

  } while (choice != 4);
   {
    cout<<"--------------------------------------------------"<<endl;

 return 0;
}