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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int low=0;
        int high=preorder.size()-1;
        int i=0;
        return BuildFromPreorder(preorder,inorder,low,high,i);
    }
    TreeNode* BuildFromPreorder(vector<int>& preorder,vector<int>& inorder,int low,int high,int& i){
        if(low>high){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        int idx=-1;
        for(int j=0;j<inorder.size();j++){
            if(inorder[j]==root->val){
                idx=j;
                break;
            }
        }
        root->left=BuildFromPreorder(preorder,inorder,low,idx-1,i);
        root->right=BuildFromPreorder(preorder,inorder,idx+1,high,i);
        return root;
    }
};