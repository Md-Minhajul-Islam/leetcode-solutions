class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<int> s;
        int n = arrival.size();
        for(int i = 0; i < min(k, n); i++) s.insert(i);

        vector<int> servers(n);
        int mx = 0;

        for(int i = 0; i < n; i++)
        {
            while(!pq.empty() && pq.top().first <= arrival[i])
            {
                s.insert(pq.top().second);
                pq.pop();
            }
            if(s.empty()) continue;
            int server = i%k;
            auto it = s.lower_bound(server);
            if(it == s.end()) it = s.begin();
            pq.push({arrival[i]+load[i], *it});
            servers[*it]++;
            mx = max(mx, servers[*it]);
            s.erase(it);
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(servers[i] == mx) ans.push_back(i);
        }
        return ans;
    }
};