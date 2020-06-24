/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// O(N) Time + O(N) Space.
// Refer BACKTOBACK SWE if the solution is not clear.

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*>mp;
        Node* curr=head;
        while(curr!=NULL){
            mp[curr]=new Node(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr!=NULL){
            mp[curr]->next=mp[curr->next];
            mp[curr]->random=mp[curr->random];
            curr=curr->next;
        }
        return mp[head];
    }
};


// O(N) Time + O(1) Space.

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* curr=head;
        while(curr!=NULL){
            Node* original_second=curr->next;
            Node* temp=new Node(curr->val);
            temp->next=original_second;
            curr->next=temp;
            curr=original_second;
        }
        curr=head;
        while(curr!=NULL){
            Node* clone_first=curr->next;
            if(curr->next!=NULL and curr->random!=NULL){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        Node* clone_head=new Node(0);
        Node* temp=clone_head;
        curr=head;
        while(curr!=NULL){
            Node* original_second=curr->next->next;
            Node* clone_first=curr->next;
            temp->next=clone_first;
            curr->next=original_second;
            temp=temp->next;
            curr=original_second;
        }
        return clone_head->next;
    }
};