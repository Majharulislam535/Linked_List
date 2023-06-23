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

void insert_posi(Node*&head,Node *& tail,int posi,int value)
{
    Node * newNode = new Node(value);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    Node * temp = head;
    for(int i=0; i< posi-1; i++)
    {
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    newNode->next->pre=newNode;
    newNode->pre=temp;

}

int count_value(Node * head)
{
    Node * temp = head;
    int cnt=0;
    while(temp != NULL)
    {
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

void insert_head(Node *&head,Node *&tail,int value){

  Node * newNode = new Node(value);
  if(head==NULL){
     head=newNode;
     tail=newNode;
     return;
  }

  newNode->next = head;
  head->pre=newNode;
  head = newNode;

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

void printReverse(Node*tail)
{
    Node * temp = tail;
    while(temp != NULL)
    {
        cout<<temp->value<<" ";
        temp=temp->pre;
    }
    cout<<endl;
}


int main()
{

    Node * head1=NULL;
    Node * tail1 = NULL;

    int n;
    cin>>n;

    while(n--)
    {

        int x,v;
        cin>>x>>v;
        if(count_value(head1)<x)
        {
            cout<<"Invalid"<<endl;
            continue;
        }
        else if(x==0)
        {
            insert_head(head1,tail1,v);
            printNormal(head1);
             printReverse(tail1);
        }
        else if(count_value(head1)== x)
        {
            insert_value(head1,tail1,v);
            printNormal(head1);
            printReverse(tail1);
        }
        else
        {
            insert_posi(head1,tail1,x,v);
            printNormal(head1);
             printReverse(tail1);
        }


    }

    return 0;
}
