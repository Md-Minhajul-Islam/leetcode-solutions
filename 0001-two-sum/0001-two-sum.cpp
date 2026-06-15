class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            if(hashMap.count(target-nums[i]))
            {
                return {hashMap[target-nums[i]], i};
            }
            hashMap[nums[i]] = i;
        }
        return {};
    }
};