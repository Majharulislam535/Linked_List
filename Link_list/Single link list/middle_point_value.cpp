#include <bits/stdc++.h>
using namespace std;

class Node{

  public:
      int value;
      Node *p;

      Node (int value){
          this->value = value;
          this->p=NULL;
        }
};

void insert_tail(Node * &head,int value){

    Node * newNode = new Node(value);

    if(head==NULL){
         head=newNode;
         return;
    }

    Node * temp = head;

    while(temp->p != NULL){
         temp=temp->p;
    }

    temp->p = newNode;

}


int count_value (Node * head){
   int cnt;
   Node * temp = head;
   while(temp != NULL){
      cnt++;
      temp=temp->p;
   }

   return cnt;
}

void middle_Number(Node *head,int n){

    Node *temp = head;


    if(n%2==0){
         int c = n/2;
         for(int i=0;i<c-1;i++){
            temp=temp->p;
         }

         cout<<temp->value<<" ";
         temp=temp->p;
         cout<<temp->value<<endl;
    }
    else{
         int c = n/2;
         for(int i=0;i<c;i++){
             temp=temp->p;
         }
         cout<<temp->value<<endl;
    }
 }




int main(){

    Node *head =NULL;

    int n;
    while(true){
         cin>>n;
         if(n==-1) break;
         insert_tail(head,n);
    }

    int cnt = count_value(head);
     middle_Number(head,cnt);

 return 0;
}
