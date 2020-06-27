/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return;
        }
        ListNode* temp=NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL and fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        slow=reverse(slow);
        fast=head;
        while(slow!=NULL and fast!=NULL){
            ListNode* fast_next=fast->next;
            ListNode* slow_next=slow->next;
            fast->next=slow;
            if(slow->next!=NULL and fast_next!=NULL){
                slow->next=fast_next;
            }
            slow=slow_next;
            fast=fast_next;
        }
    }
    ListNode* reverse(ListNode* head){
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* p=NULL;
        ListNode* c=head;
        ListNode* n=head->next;
        while(c!=NULL){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
};