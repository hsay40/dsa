class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n = grid.size();if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
    return -1;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row==n-1 && col ==n-1){return dist[n-1][n-1];}
            int del[]={-1,0,1};
            for(int i = 0;i<3;i++){
                    for(int j= 0;j<3;j++){
                         int nrow = row +del[i];
                        int ncol = col + del[j];
                        if(nrow==row && ncol == col){continue;}
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                            dist[nrow][ncol]=1+dis;
                            q.push({dis+1,{nrow,ncol}});
                        }

                     }
            }
        }
            return -1;
    }
};