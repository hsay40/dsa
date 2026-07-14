class Solution {
public:
    void bfs(int row, int col,vector<vector<char>>& grid,vector<vector<int>> &vis){
        queue<pair<int,int>>q;
        vis[row][col]=1;
        int m = grid.size();
        int n = grid[0].size();
         int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        q.push({row,col});
          

        while(!q.empty()){
           int row = q.front().first;
           int col = q.front().second;
           q.pop();
           for(int i = 0;i<4;i++){
                int rowneigh = row + delrow[i];
                int colneigh = col + delcol[i];
                        if(rowneigh>=0 && rowneigh < m && colneigh>=0 && colneigh <n && 
                        !vis[rowneigh][colneigh] && grid[rowneigh][colneigh]=='1'){
                           vis[rowneigh][colneigh] = 1;
                            q.push({rowneigh,colneigh});
                        }

           }
           }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
       for(int row = 0; row<m;row++){
            for(int col = 0; col<n;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    bfs(row, col, grid, vis);
                    count++;
                }
            }
       } 
       return count;
    }
};