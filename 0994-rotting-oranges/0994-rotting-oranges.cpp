class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        int ans = 0;
        for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                vis[i][j]=2; 
                q.push({{i,j},0});
            }
        }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
             ans = max(ans, time);
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nrow = row+ drow[i];
                    int ncol = col+ dcol[i];
                    if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol]==1 
                    && vis[nrow][ncol]==0){
                        q.push({{nrow,ncol},time+1});
                        vis[nrow][ncol]=2;
                    }
                }
        
        }
          for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && vis[i][j] != 2)
                    return -1;
            }
        }
        
        return ans;
    }
};