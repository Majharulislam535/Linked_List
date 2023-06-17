 #include <bits/stdc++.h>

 using namespace std;

 class Node {
public :
    int value;
    Node *p;

    Node(int value){
       this-> value = value;
       this-> p =NULL;
     }
 };

 void insert_tail(Node *&head1,Node *&tail1,int value){
     Node *newNode = new Node(value);


     if(head1==NULL){
         head1=newNode;
         tail1=newNode;
         return;
     }
     tail1->p=newNode;
     tail1=newNode;
 }

 int size_element(Node *head1){


     Node * temp = head1;
     int cnt=0;
     while(temp != NULL){
         cnt++;
         temp = temp ->p;
     }
     return cnt;
 }

 void print_element (Node * head){
     Node * temp =head;
     int mx =0;
     while(temp != NULL){
         if(temp->value > mx){
             mx= temp->value;
         }
         temp=temp->p;
     }

     cout<< mx << endl;
  }


 int main(){

    Node * head1=NULL;
    Node * tail1 =NULL;


    int n;
    while(true){
            cin>>n;
         if(n==-1) break;
         insert_tail(head1,tail1,n);
    }

    print_element(head1);


 return 0;
 }
