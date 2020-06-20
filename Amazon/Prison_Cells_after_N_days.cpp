// The idea is we will try to find out the point after which the cells pattern is going to repeat.
// Use the normal logic to find the position of the cell the next day. Use a set to check if there
// is a repeatation or not. If there is a repeatation then break out of the loop and determine the
// condition of the cell after N%size days.

// Refer: https://www.youtube.com/watch?v=KcEtcBDX76w

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_set<string>mp;
        bool flag=false;
        int size=0;
        for(int i=0;i<N;i++){
            vector<int> NextDayValue=nextDay(cells);
            string str="";
            for(int i=0;i<NextDayValue.size();i++){
                str+=(NextDayValue[i]+'0');
            }
            if(mp.find(str)==mp.end()){
                mp.insert(str);
                size++;
            }else{
                flag=true;
                break;
            }
            cells=NextDayValue;
        }
        if(flag==true){
            N=N%size;
            for(int i=0;i<N;i++){
                cells=nextDay(cells);
            }
            return cells;
        }
        return cells;
    }
    vector<int> nextDay(vector<int>& cells){
        vector<int>res(8,0);
        for(int i=1;i<7;i++){
            if(cells[i-1]==cells[i+1]){
                res[i]=1;
            }
        }
        return res;
    }
};