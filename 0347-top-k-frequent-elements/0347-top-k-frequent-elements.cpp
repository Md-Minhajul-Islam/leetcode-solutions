class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for(auto &n: nums) hashMap[n]++;

        vector<vector<int>> bucket(1e5+5);
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