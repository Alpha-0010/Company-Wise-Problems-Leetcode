class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        if(rows==0){
            return 0;
        }
        int cols=grid[0].size();
        queue<pair<int,int>>q;
        int fresh_oranges=0;
        // Push all the rotten oranges into the queue and count the number of fresh oranges.
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh_oranges++;
                }
            }
        }
        if(fresh_oranges==0){
            return 0;
        }
        // Now iterate over the queue of rotten oranges and travel in all 4 directions and
        // maintain a count of minutes.
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        int minutes=0;
        while(q.size()!=0){
            minutes++;
            int size=q.size();
            for(int i=0;i<size;i++){
                auto elem=q.front();
                q.pop();
                int x=elem.first;
                int y=elem.second;
                for(int i=0;i<4;i++){
                    int x1=x+dir[i][0];
                    int y1=y+dir[i][1];
                    if(x1<0 or y1<0 or x1>=rows or y1>=cols or grid[x1][y1]==2 or grid[x1][y1]==0){
                        continue;
                    }
                    grid[x1][y1]=2;
                    q.push({x1,y1});
                    fresh_oranges--;
                }
            }
            if(fresh_oranges==0){
                return minutes;
            }
        }
        return -1;
    }
};