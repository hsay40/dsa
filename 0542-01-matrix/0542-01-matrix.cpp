class Solution {
public:
bool valid(int nrow, int ncol, int n,int m){
    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
        return true;
    }
    return false;
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
            while(!q.empty()){
                    int row = q.front().first.first;
                    int col = q.front().first.second;
                    int distance = q.front().second;
                        q.pop();
                        dis[row][col]=distance;
                    for(int i = 0;i<4;i++){
                        int nrow= row+delrow[i];
                        int ncol= col+delcol[i];

                            if(valid(nrow,ncol,n,m) && mat[nrow][ncol]==1 && vis[nrow][ncol]==0){
                                vis[nrow][ncol]=1;
                                dis[nrow][ncol]= distance+1;
                                q.push({{nrow,ncol},distance+1});
                            }


                    }

            }

        return dis;
    }
};