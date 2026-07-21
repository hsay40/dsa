class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis){
        vis[row][col]=1;
        int m = grid.size();
        int n = grid[0].size();
            int delrow[]={-1,0,1,0};
            int delcol[]={0,-1,0,1};
    queue<pair<int,int>>q;
    q.push({row,col});
    while(!q.empty()){
         row = q.front().first;
         col = q.front().second;
         q.pop();
         for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]){
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
            }
         }
    }

        
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){             
            if(!vis[i][0] && grid[i][0]){           //first col
                bfs(i,0,grid,vis);
            }
            if(!vis[i][n-1] && grid[i][n-1]){       //last col
                bfs(i,n-1,grid,vis);
            }
        }
            for(int j=0;j<n;j++){
                if(!vis[0][j]&&grid[0][j]){
                    bfs(0,j,grid,vis);
                }
                if(!vis[m-1][j]&&grid[m-1][j]){
                    bfs(m-1,j,grid,vis);
                }
            }
            for(int i = 0;i<m;i++){
                for(int j=0;j<n;j++){
                    ans+= (!vis[i][j]&&grid[i][j]);
                }
            }
            return ans;
    }
};