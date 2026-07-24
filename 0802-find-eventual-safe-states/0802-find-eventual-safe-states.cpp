class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> Innode(graph.size(), 0);
        vector<int> ans;
                for(int i=0;i<graph.size();i++){
                    for(auto it : graph[i]){
                        adj[it].push_back(i);
                        Innode[i]++;
                    }
                }
                queue<int>q;
                for(int i=0;i<graph.size();i++){
                    if(Innode[i]==0){q.push(i);}
                }
            while(!q.empty()){
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for(auto it: adj[node]){
                    Innode[it]--;
                    if(Innode[it]==0){
                        q.push(it);
                    }
                }
            }
sort(ans.begin(), ans.end());
return ans;


    }
};