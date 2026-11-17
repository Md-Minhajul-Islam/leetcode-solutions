class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq1, pq2;
        int n = servers.size();
        int m = tasks.size();
        for(int i = 0; i < n; i++)
        {
            pq1.push({0, servers[i], i});
        }

        vector<int> ans(m);
        long long time = 0, i = 0;
        while(i < m)
        {
            time = max(time, i);
            while(!pq1.empty() && pq1.top()[0] <= time)
            {
                vector<long long> v = pq1.top();
                pq2.push({v[1], v[2], v[0]});
                pq1.pop();
            }
            if(pq2.empty())
            {
                time = pq1.top()[0];
                continue;
            }
            ans[i] = pq2.top()[1];
            pq1.push({time+tasks[i], pq2.top()[0], pq2.top()[1]});
            pq2.pop();
            i++;
        }
        return ans;
    }
};