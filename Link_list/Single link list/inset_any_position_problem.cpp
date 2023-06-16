#include <bits/stdc++.h>
using namespace std;

 class Node {

 public:
    int value;
    Node *p;

    Node(int value){
      this->value =value;
      this->p=NULL;
    }
 };

 void insert_tail(Node *&head,int value){

     Node *newNode = new Node (value);
     if(head==NULL){
        head=newNode;
        return;
     }

     Node * temp = head;
     while(temp->p != NULL){
          temp= temp->p;
     }
     temp->p = newNode;

 }

 int count_value (Node *head){

     Node * temp =head;
     int cnt;
     while(temp != NULL){
         cnt++;
        temp = temp ->p;
     }
     return cnt;
 }



 void insert_any_pos(Node *head,int posi,int value){

     Node * newNode = new Node(value);
     Node *temp =head;

     for(int i=0;i<posi-1;i++){
         temp=temp->p;
     }

     newNode->p=temp->p;
     temp->p=newNode;
 }

 void print_element(Node * head){
     Node * temp =head;
     while(temp != NULL){
        cout<< temp-> value << " ";
        temp = temp ->p;
     }
     cout<< endl;
 }



int main()
{
    Node * head = NULL;

    int n;
    while(true){

        cin>>n;
        if(n==-1) break;
        insert_tail(head,n);
    }

    int count_v = count_value(head);

    int m;
    cin>>m;
    int flag =0;
    while(m--){
     int posi,value;
     cin>> posi >> value;
     if(posi>count_v){
        cout<<"Invalid " <<endl;
        flag=1;
     }
      else{
         insert_any_pos(head,posi,value);
      }
    }

   if(flag != 1){
    print_element(head);
   }



    return 0;
}
