class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for(int sz = l; sz <= r; sz++)
        {
            int left = 0, right = 0, sum = 0, mn = INT_MAX;
            while(right < nums.size())
            {
                sum += nums[right];
                if(right-left+1 < sz)
                {
                    right++;
                    continue;
                }
                while(right-left+1 > sz) sum -= nums[left++];
                right++;
                if(sum > 0) mn = min(mn, sum);
            }
            ans = min(ans, mn);
        }   
        return ans == INT_MAX ? -1 : ans;
    }
};