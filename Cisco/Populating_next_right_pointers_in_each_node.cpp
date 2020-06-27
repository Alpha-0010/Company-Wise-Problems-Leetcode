/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // Follow BFS style and store the previous encountered node and make prev->next=curr_elem.
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        root->next=NULL;
        Node* prev=NULL;
        while(q.size()!=0){
            Node* elem=q.front();
            q.pop();
            if(elem==NULL){
                if(prev!=NULL){
                    prev->next=elem;
                }
                if(q.size()!=0){
                    q.push(NULL);
                }
            }else{
                if(prev!=NULL){
                    prev->next=elem;
                }
                if(elem->left!=NULL){
                    q.push(elem->left);
                }
                if(elem->right!=NULL){
                    q.push(elem->right);
                }
            }
            prev=elem;
        }
        return root;
    }
};