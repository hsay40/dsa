class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> Indegree(numCourses, 0 );
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            Indegree[it[0]]++;
        }
        queue<int> q;
        int count = 0;
        for(int i = 0;i<numCourses;i++){
            if(Indegree[i]==0){q.push(i);}
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
           count++;

                for(auto it : adj[node]){
                    Indegree[it]--;
                    if(Indegree[it]==0){q.push(it);}
                }

        }
        return numCourses== count;
    }
};