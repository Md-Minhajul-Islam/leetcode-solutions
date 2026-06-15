class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s(nums.begin(), nums.end());

        int mx = 0;
        for(auto &n: s)
        {
            if(s.count(n-1)) continue;
            int curr = n, len = 0;
            while(s.count(curr)) ++curr, ++len;
            mx = max(mx, len);
        }
        return mx;
    }
};