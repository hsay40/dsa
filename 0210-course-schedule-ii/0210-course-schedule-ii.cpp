class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
           vector<vector<int>> adj(numCourses);
        vector<int> Indegree(numCourses, 0 );
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            Indegree[it[0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0;i<numCourses;i++){
            if(Indegree[i]==0){q.push(i);}
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
           ans.push_back(node);
                for(auto it : adj[node]){
                    Indegree[it]--;
                    if(Indegree[it]==0){
                        q.push(it);}
                }

        }
        if(ans.size()<numCourses){ return {};}
        return ans;
    }
};