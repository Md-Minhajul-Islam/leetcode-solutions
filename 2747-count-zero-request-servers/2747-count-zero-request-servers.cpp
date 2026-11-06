class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [&](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });

        vector<int> queryIndex(queries.size());
        iota(queryIndex.begin(), queryIndex.end(), 0);
        sort(queryIndex.begin(), queryIndex.end(), [&](int a, int b){
            return queries[a] < queries[b];
        });

        int left = 0, right = 0, active = 0;
        vector<int> count(n+2, 0), ans(queries.size());
        for(auto i: queryIndex)
        {
            int windowStart = queries[i]-x, windowEnd = queries[i];
            while(right < logs.size() && logs[right][1] <= windowEnd)
            {
                count[logs[right][0]]++;
                if(count[logs[right][0]] == 1) active++;
                right++;
            }

            while(left < right && logs[left][1] < windowStart)
            {
                count[logs[left][0]]--;
                if(count[logs[left][0]] == 0) active--;
                left++;
            }

            ans[i] = n-active;
        }
        return ans;
    }
};