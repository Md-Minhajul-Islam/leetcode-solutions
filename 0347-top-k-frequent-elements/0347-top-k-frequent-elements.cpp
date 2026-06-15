class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for(auto &n: nums) hashMap[n]++;

        vector<vector<int>> bucket(1e5+5);
        for(auto &[k, v]: hashMap) bucket[v].push_back(k);

        vector<int> ans;
        for(auto it = bucket.rbegin(); it != bucket.rend(); ++it)
        {
            if(k <= 0) break;
            for(auto &n: *it)
            {
                k--;
                ans.push_back(n);
                if(k <= 0) break;
            }
        }
        return ans;
    }
};