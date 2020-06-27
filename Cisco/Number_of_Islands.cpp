class Solution {
public:
    // BFS Approach. 
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        if(rows==0){
            return 0;
        }
        int cols=grid[0].size();
        int islands=0;
        // Now itrerate over all the cells and pick the cells which are '1' and travel in 
        // all the 4 directions and make all '1's '0's.
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    bfs(grid,rows,cols,i,j);
                }
            }
        }
        return islands;
    }
    void bfs(vector<vector<char>>& grid,int rows,int cols,int x,int y){
        int dirs[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
        queue<pair<int,int>>q;
        grid[x][y]='0';
        q.push({x,y});
        while(q.size()!=0){
            auto elem=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x1=elem.first+dirs[i][0];
                int y1=elem.second+dirs[i][1];
                if(x1<0 or y1<0 or x1>=rows or y1>=cols or grid[x1][y1]=='0'){
                    continue;
                }
                grid[x1][y1]='0';
                q.push({x1,y1});
            }
        }
    }
};