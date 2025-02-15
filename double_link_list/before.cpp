#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *pre;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
        this->pre = NULL;
    }
};
void normal_print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}
void reverse_print(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->pre;
    }
}

// void insert_at_any(Node *head, int pos, int value)
// {
//     Node *newNode = new Node(value);
//     Node *temp = head;
//     for (int i = 1; i <= pos - 1; i++)
//     {
//         temp = temp->next;
//     }
//     newNode->next = temp->next;
//     temp->next = newNode;

//     newNode->next->pre = newNode;
//     newNode->pre = temp;
// }

void insert_at_any_position(Node *head, int pos, int value)
{
    Node *newNode = new Node(value);
}

int size(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
// void insert_head(Node *&head, Node *&tail, int value)
// {
//     Node *newNode = new Node(value);
//     if (head == NULL)
//     {
//         head = newNode;
//         tail = newNode;
//         return;
//     }
//     newNode->next = head;
//     head->pre = newNode;
//     // newNode->next->pre = newNode;
//     head = newNode;
// }

void insert_head_again(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->pre = newNode;

    head = newNode;
}
void insert_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->pre = tail;
    tail = newNode;
}
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);

    Node *tail = c;
    // Doubly list connection

    head->next = a;
    a->pre = head;

    a->next = b;
    b->pre = a;
    b->next = c;
    c->pre = b;

    int size_print = size(head);
    int pos, value;
    
    cin >> pos >> value;
    if (pos == 0)
    {
        insert_head_again(head, value);
    }
    else if (pos == size_print)
    {
        insert_tail(head, tail, value);
    }
    else if (size_print <= pos)
    {
        cout << "Invalid Position" << endl;
    }
    else
    {
        insert_at_any_position(head, pos, value);
    }

    normal_print(head);
    cout << endl;
    reverse_print(tail);
    return 0;
}