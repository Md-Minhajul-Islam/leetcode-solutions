class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = 1, increasing = 1, decreasing = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i-1]) increasing++;
            else mx = max(mx, increasing), increasing = 1;

            if(nums[i] < nums[i-1]) decreasing++;
            else mx = max(mx, decreasing), decreasing = 1;
        }

        mx = max({mx, increasing, decreasing});
        return mx;
    }
};