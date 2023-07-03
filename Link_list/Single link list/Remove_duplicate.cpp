
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

void sortted_list(Node*&head){

 for (Node *i = head; i->next != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->value > j->value)
            {
                swap(i->value, j->value);
            }
        }
    }


 }

 void duplicate_delete(Node * head){
     Node * temp = head;
     while(temp->next != NULL){
         if(temp->value == temp->next->value){
             temp->next=temp->next->next;
         }
         if(temp->next==NULL) break;
         else if(temp->value != temp->next->value){
             temp=temp->next;
         }
     }
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

 sortted_list(head1);
 duplicate_delete(head1);
 printNormal(head1);




return 0;
}
