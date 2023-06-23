#include <bits/stdc++.h>
using namespace std;

class Node {

 public:
     Node * pre ;
     int value;
     Node * next;

     Node (int value){
          this->value=value;
          this->pre=NULL;
          this->next=NULL;
      }
 };


  void insert_at_pos(Node*&head,Node *&tail,int posi,int value){
     Node * newNode = new Node (value);

     if(head == NULL){
         head=newNode;
         tail = newNode;
         return;
     }
      Node * temp = head;
     for(int i=0;i<posi-1;i++){
        temp = temp ->next;
     }
     newNode->next=temp->next;
     temp->next=newNode;
     newNode->next->pre= newNode;
     newNode->pre=temp;

  }

  void insert_head(Node*&head,Node*&tail,int value){
       Node * newNode = new Node(value);
       if(head==NULL){
          head = newNode;
          tail= newNode;
          return;
       }

       newNode->next = head;
       head->pre=newNode;

       head = newNode;
       head->pre=NULL;
  }

  void insert_tail(Node*&head,Node*&tail,int value){
     Node * newNode = new Node (value);
      if(head== NULL){
        head=newNode;
        tail=newNode;
        return;
      }

      tail->next = newNode;
      newNode->pre = tail;
      tail = tail->next;

  }

  void delete_posi(Node * head,int posi){

     Node * temp = head;
     for(int i=0;i<posi-1;i++){
        temp = temp->next;
     }

     Node * deleteNode = temp->next;

     temp->next=temp->next->next;
     temp->next->pre=temp;

     delete deleteNode;

  }

  void delete_head(Node*&head){
     Node * deleteNode = head;
     head = head->next;
     delete deleteNode;
     head->pre = NULL;
  }

  void delete_tail(Node *& tail){
     Node * deleteNoder = tail;
     tail = tail->pre;
     delete deleteNoder;
     tail->next = NULL;
  }


 void print_normar(Node * head){

     Node * temp = head;
     while(temp != NULL){
        cout<< temp->value<< " ";
        temp = temp ->next;
     }
     cout<< endl;

 }

 void print_reverse(Node * tail){

     Node * temp = tail;

     while(temp != NULL){
        cout<<temp->value<< " ";
        temp=temp->pre;
     }
     cout<< endl;
 }


 int main(){
/*
   Node * head = NULL;
   Node * tail = NULL;
*/
   Node *head = new Node(10);
   Node *a = new Node(20);
   Node *b = new Node(30);
   Node *c = new Node(40);
   Node *d = new Node(50);

   Node * tail =d;

   head->next=a;
   a->next=b;
   a->pre=head;
   b->pre=a;
   b->next=c;
   c->pre=b;
   c->next=d;
   d->pre=c;

     delete_tail(tail);
    //delete_head(head);
   //delete_posi(head,1);
    //insert_tail(head,tail,300);
     //insert_head(head,tail,100);
   //insert_at_pos(head,tail,3,200);
   print_normar(head);
   print_reverse(tail);





 return 0;
 }
