
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int value;
    Node *pre;
    Node *next;

    Node(int value)
    {
        this->value=value;
        this->pre=NULL;
        this->next=NULL;
    }
};


void insert_value(Node *&head1, Node *&tail1,int value)
{
    Node * newNode = new Node(value);
    if(head1==NULL)
    {
        head1=newNode;
        tail1=newNode;
        return;
    }
    tail1->next=newNode;
    newNode->pre = tail1;
    tail1=tail1->next;
}



int main(){

  Node * head1=NULL;
  Node * tail1 = NULL;

  int n;
  while(true){
        cin>>n;
      if(n== -1) break;

      insert_value(head1,tail1,n);
  }

  Node * i = head1;
  Node * j = tail1;
  int flag=0;
  while(i!=j){
     if(i->value != j->value){
       flag=1;
     }
     i=i->next;
     j=j->pre;
  }

  if(flag){
     cout<<"No"<<endl;
  }
  else{
     cout<< "yes" << endl;
  }




return 0;
}
