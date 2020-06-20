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
    void prefix(TreeNode* root,string& pre1,bool l){
        if(root==NULL){
            if(l==true){
                pre1+="lnull";
            }else{
                pre1+="rnull";
            }
            return;
        }
        pre1+="#"+to_string(root->val);
        prefix(root->left,pre1,true);
        prefix(root->right,pre1,false);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL and t==NULL){
            return true;
        }
        string pre1="";
        string pre2="";
        prefix(s,pre1,true);
        prefix(t,pre2,true);
        if(pre1.find(pre2)!=string::npos){
            return true;
        }
        return false;
    }
};