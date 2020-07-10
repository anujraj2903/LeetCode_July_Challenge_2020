/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return NULL;
        
       Node* temp=head;
        
        while(temp!=NULL && temp->child==NULL) temp=temp->next;
        
        if(temp){
            Node* top=flatten(temp->child);
            Node* x=temp->next;
            Node* tail=top;
            while(tail->next!=NULL) tail=tail->next;
            temp->next=top;
            top->prev=temp;
            tail->next=x;
            if(x)
                x->prev=tail;  
            temp->child=NULL;
        }
        
        return head;
    }
};