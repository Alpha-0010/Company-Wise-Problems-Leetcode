class Solution {
public:
    int myAtoi(string str) {
        int n=str.length();
        if(n==0){
            return 0;
        }
        int i=0;
        // Skip all whitespaces.
        while(i<n and str[i]==' '){
            i++;
        }
        // If there are only spaces return 0.
        if(i==n){
            return 0;
        }
        // Get the sign of str.
        int sign=1;
        if(str[i]=='-'){
            sign=-1;
            i++;
        }else if(str[i]=='+'){
            sign=1;
            i++;
        }
        // If there are numbers after spaces then traverse over the numbers and add them to our final answer res.
        long res=0;
        while(i<n and isdigit(str[i])){
            res=res*10+(str[i]-'0');
            if( sign*res <= INT_MIN ){
                return INT_MIN;
            }
            if(sign*res >= INT_MAX){
                return INT_MAX;
            }
            i++;
        }
        return (int)sign*res;
    }
};