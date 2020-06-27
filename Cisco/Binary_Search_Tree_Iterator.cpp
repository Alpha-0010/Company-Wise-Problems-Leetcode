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

// Do Inorder traversal of the BST(Ascending order) and store its elements into the stack.
class BSTIterator {
public:
    stack<TreeNode*>s;
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->right);
        s.push(root);
        inorder(root->left);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* elem=s.top();
        s.pop();
        return elem->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(s.size()!=0){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */