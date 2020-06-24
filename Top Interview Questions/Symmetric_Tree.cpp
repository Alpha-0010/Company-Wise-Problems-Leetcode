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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return check(root->left,root->right);
    }
    bool check(TreeNode* root1,TreeNode* root2){
        if(root1==NULL and root2==NULL){
            return true;
        }
        if(root1==NULL or root2==NULL or root1->val!=root2->val){
            return false;
        }
        bool s1=check(root1->left,root2->right);
        bool s2=check(root1->right,root2->left);
        return s1 and s2;
    }
};