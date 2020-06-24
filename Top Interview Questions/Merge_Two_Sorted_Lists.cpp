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
// Iterative Approach.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* l3=new ListNode();
        ListNode* curr=l3;
        while(l1!=NULL and l2!=NULL){
            if(l1->val<l2->val){
                curr->next=new ListNode(l1->val);
                l1=l1->next;
                curr=curr->next;
            }else{
                curr->next=new ListNode(l2->val);
                l2=l2->next;
                curr=curr->next;
            }
        }
        while(l1!=NULL){
            curr->next=new ListNode(l1->val);
            l1=l1->next;
            curr=curr->next;
        }
        while(l2!=NULL){
            curr->next=new ListNode(l2->val);
            l2=l2->next;
            curr=curr->next;
        }
        return l3->next;
    }
};

// Recursive Approach.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* l3;
        if(l1->val<l2->val){
            l3=l1;
            l3->next=mergeTwoLists(l1->next,l2);
        }else{
            l3=l2;
            l3->next=mergeTwoLists(l1,l2->next);
        }
        return l3;
    }
};