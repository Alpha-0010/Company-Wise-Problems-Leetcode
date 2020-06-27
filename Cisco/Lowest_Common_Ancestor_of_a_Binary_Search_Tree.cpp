/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Use the property of BST .i.e. root->left->val<root->val<root->right->right.
    // And the node with the maximum depth is the LCA.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if((root->val>p->val) and (root->val>q->val)){
            // Then p and q must be present in the left part of the tree.
            return lowestCommonAncestor(root->left,p,q);
        }
        if((root->val<p->val) and (root->val<q->val)){
            // In this case p and q must be present in the right part of the tree.
            return lowestCommonAncestor(root->right,p,q);
        }
        // If both p and q are not present in the same branch(left or right) then must be
        // present in different branch in that case root is the LCA of p and q.
        return root;
    }
};