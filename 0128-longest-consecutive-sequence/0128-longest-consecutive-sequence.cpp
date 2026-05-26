class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> hashMap, vis;
        for(auto &n: nums) hashMap[n] = 1;

        int mx = 0;
        for(auto &n: nums)
        {
            if(vis.count(n)) continue;
            int cnt = 0;
            for(int i = n; hashMap.count(i); i++)
            {
                vis[i] = 1;
                cnt++;
            }
            for(int i = n-1; hashMap.count(i); i--)
            {
                vis[i] = 1;
                cnt++;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};