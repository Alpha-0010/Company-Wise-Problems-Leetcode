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
    // Using the merge function.
    // Run through the whole lists array merge top 2 lists using the merge function
    // then erase those 2 lists from the lists array. Finally our required answer will be
    // in front of the lists array.
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
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