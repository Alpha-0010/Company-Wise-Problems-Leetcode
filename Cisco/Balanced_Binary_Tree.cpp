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

// For a tree to be a balanced binary tree. The difference of its left and right subtrees should be less than
// or equal to 1 and its left part and right parts should be balanced binary tree.

class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int ans1=height(root->left);
        int ans2=height(root->right);
        return 1+max(ans1,ans2);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int h1=height(root->left);
        int h2=height(root->right);
        if(abs(h1-h2)>1){
            return false;
        }
        bool s1=isBalanced(root->left);
        bool s2=isBalanced(root->right);
        return s1 and s2;
    }
};