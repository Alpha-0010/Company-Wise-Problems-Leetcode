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


// Merge 2 lists at a time in the lists array of lunked lists. After merging the first and second element of the 
// lists array erase the first 2 elements of the lists array. 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0){
            return NULL;
        }
        while(lists.size()>1){
            lists.push_back(merge(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* l3;
        if(l1->val<l2->val){
            l3=l1;
            l3->next=merge(l1->next,l2);
        }else{
            l3=l2;
            l3->next=merge(l1,l2->next);
        }
        return l3;
    }
};