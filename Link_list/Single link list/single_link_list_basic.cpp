#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int vlu;
    Node *p;

    Node(int vlu)
    {
        this->vlu = vlu;
        this->p = NULL;
    }
};

int main()
{

    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);

    head->p = a;
    a->p = b;
    b->p = c;
    c->p = d;

    Node *tmp = head;

    while (tmp != NULL)
    {
        cout << tmp->vlu << endl;
        tmp = tmp->p;
    }

    return 0;
}
