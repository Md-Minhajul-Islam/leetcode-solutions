class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &e: edges) adj[e[0]].push_back({e[1], e[2]});

        vector<vector<long long>> dist(n, vector<long long>(k+1, LLONG_MAX));
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        while(!pq.empty())
        {
            auto [w, u, cnt] = pq.top();
            pq.pop();
            if(u == n-1) return dist[u][cnt];
            for(auto [v, weight]: adj[u])
            {
                int c = labels[u] == labels[v] ? cnt+1 : 1;
                if(c <= k && dist[v][c] > w+weight)
                {
                    dist[v][c] = w+weight;
                    pq.push({dist[v][c], v, c});
                }
            }
        }
        return -1;
    }
};