// BackTracking Problem.
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0){
            return {};
        }
        vector<string> res;
        ParantheseHelper(n,0,0,res,"");
        return res;
    }
    void ParantheseHelper(int n,int open,int closed,vector<string>& res,string curr){
        if(curr.length()==2*n){
            res.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            ParantheseHelper(n,open+1,closed,res,curr);
            curr.pop_back();
        }
        if(closed<open){
            curr.push_back(')');
            ParantheseHelper(n,open,closed+1,res,curr);
            curr.pop_back();
        }
    }
};