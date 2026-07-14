class Solution {
public:
    void bfs(int row, int col, int initial, vector<vector<int>>& image, int color, vector<vector<int>> &vis){
        queue<pair<int,int>>q;
        vis[row][col]=1;
        image[row][col] = color;
        q.push({row,col});
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

                for(int i= 0;i<4;i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(nrow>=0 && ncol>=0 && nrow<image.size() && ncol<image[0].size()&& !vis[nrow][ncol] && image[nrow][ncol]==initial  ){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                        image[nrow][ncol] = color;
                    }
                }
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        bfs(sr,sc, image[sr][sc],image,color,vis);
        return image;
    }
};