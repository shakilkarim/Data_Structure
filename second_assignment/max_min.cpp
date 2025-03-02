#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int value;
        Node * next;

        Node(int value){
            this->value = value;
            this->next = NULL;
        }
};
void insert_tail(Node * &head, Node * &tail, int value){
        Node * newNode = new Node (value);

        if(head == NULL){
            head = newNode; 
            tail = newNode;
            return;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
}

int max (Node * head){
    Node * temp = head;
    int max = INT_MIN;
    
      while(temp != NULL){
           if(max < temp->value){
                max = temp->value;
           }
            temp = temp->next;
      }

      return max;
}
int min (Node * head){
    Node * temp = head;
    int min = INT_MAX;
    
      while(temp != NULL){
           if(min > temp->value){
                min = temp->value;
           }
            temp = temp->next;
      }

      return min;
}

int main(){
    Node * head = NULL;
    Node * tail = NULL;
    int value;
    while(true){
        cin>>value;
        if(value == -1){
            break;
        }else{
            insert_tail(head,tail,value);
        }
    }

     int max_val = max(head);
     int min_val = min(head);
     cout<<max_val<<" "<<min_val;
    return 0;
}