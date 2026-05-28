class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dq(n), ans(n-k+1);
        int l = 0, r = -1;
        for(int i = 0; i < n; i++)
        {
            if(l <= r && dq[l] <= i-k) l++;
            while(l <= r && nums[dq[r]] <= nums[i]) r--;
            dq[++r] = i;
            if(i >= k-1) ans[i-k+1] = nums[dq[l]];
        }
        return ans;
    }
};