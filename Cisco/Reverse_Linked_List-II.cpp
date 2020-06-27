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

// In this problem we basically need three variables Tail_of_the_first_part, Previous_Head_of_the_reversed_part.
// After reversing from m to n Previous_Head_of_the_reversed_part will become tail of the reversed part and the 
// head of the reversed part will be p.

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL){
            return NULL;
        }
        ListNode* c=head;
        ListNode* p=NULL;
        while(m>1){
            p=c;
            c=c->next;
            m--;
            n--;
        }
        ListNode* tail_of_the_first_part=p;
        ListNode* head_of_the_reversed_part=c;
        ListNode* temp=c->next;
        while(n>0){
            temp=c->next;
            c->next=p;
            p=c;
            c=temp;
            n--;
        }
        if(tail_of_the_first_part!=NULL){
            tail_of_the_first_part->next=p;
        }else{
            head=p;
        }
        head_of_the_reversed_part->next=c;
        return head;
    }
};