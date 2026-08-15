class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<pair<int,int>> adj[n];

        // Create adjacency list
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // {stops, {node, cost}}
        queue<pair<int, pair<int,int>>> q;

        q.push({0, {src, 0}});

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // We can make at most k+1 flights
            if (stops > k)
                continue;

            for (auto iter : adj[node]) {

                int adjNode = iter.first;
                int edgeWeight = iter.second;

                if (cost + edgeWeight < dist[adjNode]) {

                    dist[adjNode] = cost + edgeWeight;

                    q.push({
                        stops + 1,
                        {adjNode, cost + edgeWeight}
                    });
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};