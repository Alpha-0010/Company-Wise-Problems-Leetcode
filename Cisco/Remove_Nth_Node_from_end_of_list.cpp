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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL or (head->next==NULL and n>1) ){
            return NULL;
        }
        int len=length(head);
        if(len==n){
            return head->next;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        // First move fast pointer n nodes.
        while(fast!=NULL and n>0){
            fast=fast->next;
            n--;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        // Now slow is at n-1 position from the end.
        slow->next=slow->next->next;
        return head;
    }
    int length(ListNode* head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
};