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

 void revers(Node*head,Node *tail){

    Node * i = head;
    Node * j = tail;

    while(i!= j && i->next != j){
         swap(i->value,j->value);
         i=i->next;
         j=j->pre;
    }
    swap(i->value,j->value);
 }

void printNormal(Node*head)
{
    Node * temp = head;
    while(temp != NULL)
    {
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
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



  revers(head1,tail1);
  printNormal(head1);



return 0;
}
