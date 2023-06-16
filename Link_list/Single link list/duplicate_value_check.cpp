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

 void inset_tail(Node *&head,int v){

     Node *newNode = new Node(v);
     if(head==NULL){
         head=newNode;
         return;
     }
     Node *temp = head;
     while(temp->p != NULL){
          temp = temp->p;
     }

     temp->p=newNode;

  }

  void print_value(Node * head){
       Node * tmp = head;
       int cnt[100] = {0};

       while(tmp != NULL){
          cnt[tmp->value]++;
          tmp = tmp->p;
       }

       int flag =0;

       for(int i=0;i<100;i++){
          if(cnt[i] != 0 && cnt[i]==2){
              flag=1;
          }
       }

       if(flag){
         cout<< "YES"  << endl;
       }
       else{
         cout<< "NO" << endl;
       }

   }

int main(){

    Node *head = NULL;
    int n;
    while(true){
      cin >> n;
      if(n== -1) break;
      inset_tail(head,n);
    }

    print_value(head);



    return 0;
}
