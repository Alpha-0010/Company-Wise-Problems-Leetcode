/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int length(ListNode* head){
        int len=0;
        while(head!=NULL){
            head=head->next;
            len++;
        }
        return len;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL or (head->next==NULL and n==1)){
            return NULL;
        }
        
        int len=length(head);
        if(len==n){
            return head->next;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL and n>0){
            fast=fast->next;
            n--;
        }
        // fast has moved n steps.
        
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        // Now slow is at the node before the Nth Node.
        slow->next=slow->next->next;
        return head;
    }
};