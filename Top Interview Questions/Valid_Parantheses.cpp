class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.length();
        if(n==0){
            return true;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='(' or s[i]=='[' or s[i]=='{'){
                st.push(s[i]);
            }else if(st.size()==0){
                return false;
            }else if(s[i]==')' and (st.top()=='{' or st.top()=='[' ) ){
                return false;
            }else if(s[i]=='}' and (st.top()== '(' or st.top()=='[' ) ){
                return false;
            }else if(s[i]==']' and (st.top()=='(' or st.top()=='{' ) ){
                return false;
            }else{
                st.pop();
            }
        }
        if(st.size()!=0){
            return false;
        }
        return true;
    }
};