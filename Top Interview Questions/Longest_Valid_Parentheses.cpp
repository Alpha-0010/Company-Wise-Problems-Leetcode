// Refer: To the Top Comment of the below url.
// https://leetcode.com/problems/longest-valid-parentheses/discuss/14126/My-O(n)-solution-using-a-stack

// DP problem: 
// if s[i]=='(' open++
// else if s[i]==')' and open>0 v[i]=v[i-1]+2+v[i-v[i]].

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        if(n==0){
            return 0;
        }
        vector<int>v(n,0);
        int open=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }else if(s[i]==')' and open>0){
                // Matches found.
                v[i]=v[i-1]+2;
                // Add matches from previous.
                if(i-v[i]>0){
                    v[i]+=v[i-v[i]];
                }
                open--;
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,v[i]);
        }
        return maxi;
    }
};