class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<pair<int, int>> adj[n+1]; // Adjusting for 1-based indexing

        // Building the adjacency list
        for(int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> dist(n+1, INT_MAX); // Distance vector with size n+1
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src}); // Priority queue stores {distance, node}

        while(!pq.empty()) {
            auto temp = pq.top();
            int d = temp.first;
            int node = temp.second;
            pq.pop();

            for(auto it: adj[node]) {
                int nextNode = it.first;
                int edgeWeight = it.second;

                if(dist[nextNode] > d + edgeWeight) {
                    dist[nextNode] = d + edgeWeight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) { // Start from 1 for 1-based indexing
            if(dist[i] == INT_MAX) return -1; // If any node is unreachable
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
