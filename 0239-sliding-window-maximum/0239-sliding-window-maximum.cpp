class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> dq(nums.size()), ans(nums.size()-k+1);
        int l = 0, r = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(l <= r && dq[l] <= i-k) l++;
            while(l <= r && nums[dq[r]] <= nums[i]) r--;
            dq[++r] = i;
            if(i >= k-1) ans[i-k+1] = nums[dq[l]];
        }
        return ans;
    }
};