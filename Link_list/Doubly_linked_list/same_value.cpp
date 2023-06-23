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

int count_value(Node * head){
    Node * temp = head;
    int cnt=0;
    while(temp != NULL){
         cnt++;
         temp=temp->next;
    }
    return cnt;
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


void printPre(Node*tail1)
{
    Node * temp = tail1;
    while(temp != NULL)
    {
        cout<<temp->value<<" ";
        temp=temp->pre;
    }
    cout<<endl;
}


int main()
{
    Node* head1=NULL;
    Node *tail1= NULL;
    Node * head2=NULL;
    Node * tail2=NULL;

    int n;
    while(true){
        cin>>n;
        if(n== -1) break;
        insert_value(head1,tail1,n);
    }



    int m;
    while(true){
        cin>>m;
        if(m== -1) break;
        insert_value(head2,tail2,m);
    }
    int cnt1 = count_value(head1);
    int cnt2 = count_value(head2);

    if(cnt1==cnt2){
       Node * temp1= head1;
       Node * temp2 = head2;
       int flag = 0;
       while(temp1 != NULL){
           if(temp1->value != temp2->value){
              flag=1;
              break;
           }
           temp1=temp1->next;
           temp2=temp2->next;
       }
       if(flag==1){
           cout<<"NO"<<endl;
       }
       else{
          cout<<"YES"<<endl;
       }
    }
    else{
         cout<<"NO"<<endl;
    }

    printNormal(head1);
    printPre(tail1);

    return 0;
}
