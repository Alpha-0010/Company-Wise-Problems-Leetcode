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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        int carry=0;
        ListNode* l3=new ListNode();
        ListNode* curr=l3;
        while(curr1!=NULL and curr2!=NULL){
            int num=(curr1->val+curr2->val+carry);
            int add=num%10;
            carry=num/10;
            curr->next=new ListNode(add);
            curr=curr->next;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        while(curr1!=NULL){
            int num=curr1->val+carry;
            int add=num%10;
            carry=num/10;
            curr->next=new ListNode(add);
            curr=curr->next;
            curr1=curr1->next;
        }
        while(curr2!=NULL){
            int num=curr2->val+carry;
            int add=num%10;
            carry=num/10;
            curr->next=new ListNode(add);
            curr=curr->next;
            curr2=curr2->next;
        }
        if(carry!=0){
            curr->next=new ListNode(carry);
        }
        return l3->next;
    }
};