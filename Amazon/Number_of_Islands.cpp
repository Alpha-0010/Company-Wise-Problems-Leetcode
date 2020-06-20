class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        if(rows==0){
            return 0;
        }
        int cols=grid[0].size();
        int islands=0;
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1' and visited[i][j]==false){
                    islands++;
                    bfs(grid,i,j,visited,rows,cols);
                }
            }
        }
        return islands;
    }
    void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& visited,int rows,int cols){
        int dirs[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=true;
        while(q.size()!=0){
            auto elem=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int x=elem.first+dirs[k][0];
                int y=elem.second+dirs[k][1];
                if(x<0 or y<0 or x>=rows or y>=cols or grid[x][y]=='0' or visited[x][y]==true){
                    continue;
                }
                visited[x][y]=true;
                q.push({x,y});
            }
        }
    }
};