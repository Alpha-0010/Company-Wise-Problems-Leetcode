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

// In these type of problems just think about the actual answer we need and what value are we going to pass
// on from the Node to its parents.
class Solution {
public:
    int maxi=INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        path(root);
        return maxi;
    }
    int path(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftans=path(root->left);
        int rightans=path(root->right);
        int ans1=root->val+leftans;
        int ans2=root->val+rightans;
        int ans3=root->val;
        int ans4=root->val+leftans+rightans;
        maxi=max(maxi,max(ans1,max(ans2,max(ans3,ans4)))); // Actual answer.
        return max(root->val,max(root->val+leftans,root->val+rightans)); // Answer passed on to the parent.
    }
};