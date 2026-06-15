class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        int mx = 0;
        for(auto &n: nums) mx = max(++hashMap[n], mx);

        vector<vector<int>> bucket(mx+2);
        for(auto &[k, v]: hashMap) bucket[v].push_back(k);

        vector<int> ans;
        for(int i = bucket.size()-1; i >= 0 && k > 0; i--)
        {
            for(auto &n: bucket[i])
            {
                k--;
                ans.push_back(n);
                if(k <= 0) break;
            }
        }
        return ans;
    }
};