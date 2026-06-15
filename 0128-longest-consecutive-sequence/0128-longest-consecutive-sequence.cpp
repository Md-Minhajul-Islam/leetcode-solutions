class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> hashMap, vis;
        for(auto &n: nums) hashMap[n] = 1;

        int mx = 0;
        for(auto &[k, v]: hashMap)
        {
            if(vis.count(k)) continue;
            int cnt = 1;
            for(int i = k+1; hashMap.count(i); i++)
            {
                vis[i] = 1;
                cnt++;
            }
            for(int i = k-1; hashMap.count(i); i--)
            {
                vis[i] = 1;
                cnt++;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};