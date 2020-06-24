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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>>res;
        vector<int>curr;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(q.size()!=0){
            TreeNode* Node=q.front();
            q.pop();
            if(Node==NULL){
                res.push_back(curr);
                curr.clear();
                if(q.size()!=0){
                    q.push(NULL);
                }
            }else{
                curr.push_back(Node->val);
                if(Node->left!=NULL){
                    q.push(Node->left);
                }
                if(Node->right!=NULL){
                    q.push(Node->right);
                }
            }
        }
        return res;
    }
};