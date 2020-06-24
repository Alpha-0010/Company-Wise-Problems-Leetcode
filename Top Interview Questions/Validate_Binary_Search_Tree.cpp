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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        // if(root->left==NULL and root->right==NULL){
        //     return true;
        // }
        TreeNode* maxi=NULL;
        TreeNode* mini=NULL;
        return isBST(root,mini,maxi);
    }
    bool isBST(TreeNode* root,TreeNode* mini,TreeNode* maxi){
        if(root==NULL){
            return true;
        }
        if((mini!=NULL and root->val<=mini->val) or (maxi!=NULL and root->val>=maxi->val)){
            return false;
        }
        bool s1=isBST(root->left,mini,root);
        bool s2=isBST(root->right,root,maxi);
        return s1 and s2;
    }
};