class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        const int INF = 1e9;
        
        vector<vector<int>> dist(n, vector<int>(n, INF));

        // Distance from a city to itself
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Given edges
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        // Floyd-Warshall
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][k] + dist[k][j]
                    );
                }
            }
        }

        int ans = -1;
        int minCount = INT_MAX;

        // Count reachable cities
        for(int i = 0; i < n; i++) {
            int count = 0;

            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            // <= ensures larger index wins in case of tie
            if(count <= minCount) {
                minCount = count;
                ans = i;
            }
        }

        return ans;
    }
};