class Solution {
public:
        bool bfs(int node, int col, vector<int>&color, vector<vector<int>>&graph){
            color[node] = col;
              queue<int> q;
              q.push(node);
              while(!q.empty()){
                    node = q.front();
                    q.pop();
                    for(auto it: graph[node]){
                        if(color[it]==-1){
                            q.push(it);
                            color[it]=!color[node];
                           
                        }else if (color[it]==color[node]){
                        return false;
                         } 
                    }

              }
              return true;
        }


    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
          if(color[i]==-1)  {if(!bfs(i,0,color,graph)){return false; }}

        }
        return true;
    }
};