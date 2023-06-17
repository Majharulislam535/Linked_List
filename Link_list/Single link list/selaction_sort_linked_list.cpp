#include <bits/stdc++.h>
using namespace std;

 class Node{
public:
    int value;
    Node * p;
    Node(int value){
       this->value=value;
       this->p=NULL;
     }
 };

 void inser_tail(Node*&head,Node *&tail,int value){
      Node * newNode = new Node(value);

      if(head==NULL){
         head=newNode;
         tail=newNode;
         return;
      }
      tail->p=newNode;
      tail=newNode;
 }

 void print_value(Node*head){
    Node * temp = head;
    while(temp != NULL){
            cout<<temp->value<<" ";
         temp = temp->p;
    }
    cout<<endl;
 }

int main(){

   Node * head = NULL;
   Node * tail = NULL;

   int n;
   while(true){
     cin>> n;
     if(n==-1) break;
      inser_tail(head,tail,n);
   }

   for(Node*i=head;i->p != NULL;i=i->p){
     for(Node *j=i->p;j != NULL;j=j->p){
        if(i->value > j-> value){
             swap(i->value,j->value);
        }
     }
   }

    print_value(head);

 return 0;
}
