#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int val;
        Node* next;
        Node * pre;
        Node(int val){
            this->val = val;
            this->next = NULL;
            this->pre = NULL;
        }
};
void print_list(Node *head){

    Node * tmp = head;

    while (tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    
}

void reverse_print (Node *tail){
    Node * tmp = tail;
    while (tmp !=NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->pre;
    }
    
}
int main(){
    
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);

    Node * tail = c;

    head->next = a;
    a->pre = head;

    a->next = b;
    b->pre = a;

    b->next = c;
    c->pre = b;

    print_list(head);
    cout<<endl;
    reverse_print(tail);
    return 0;
}