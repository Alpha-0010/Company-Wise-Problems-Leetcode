/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// The idea is simple just make sure that the right part of the root point to the left of the tree and the
// left part of the root should point to NULL. At any point of time top of the stack should hold the left
// most Node of the tree. So we are making curr->left=s.top() and curr->left=NULL.

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        stack<TreeNode*>s;
        s.push(root);
        while(s.size()!=0){
            TreeNode* curr=s.top();
            s.pop();
            if(curr->right!=NULL){
                s.push(curr->right);
            }
            if(curr->left!=NULL){
                s.push(curr->left);
            }
            if(s.size()!=0){
                curr->right=s.top();
            }
            curr->left=NULL;
        }
    }
};