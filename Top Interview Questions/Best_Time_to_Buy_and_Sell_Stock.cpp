

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0){
            return 0;
        }
        int min_point=INT_MAX;
        int max_profit=0;
        for(int i=0;i<n;i++){
            if(prices[i]<min_point){
                min_point=prices[i];
            }else if((prices[i]-min_point)>max_profit){
                max_profit=prices[i]-min_point;
            }
        }
        return max_profit;
    }
};