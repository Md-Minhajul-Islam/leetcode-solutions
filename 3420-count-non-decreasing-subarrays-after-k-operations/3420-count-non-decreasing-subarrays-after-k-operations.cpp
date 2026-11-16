class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ans = 0, cost = 0, l = nums.size()-1, r = nums.size()-1;
        deque<pair<long long, long long>> dq;
        while(l >= 0)
        {
            long long c = 1;
            while(!dq.empty() && dq.front().first <= nums[l])
            {
                cost += (nums[l]-dq.front().first)*dq.front().second;
                c += dq.front().second;
                dq.pop_front();
            }
            dq.push_front({nums[l], c});
            while(k < cost)
            {
                cost -= dq.back().first-nums[r];
                if(--dq.back().second == 0) dq.pop_back();
                r--;
            }
            ans += r-l+1;
            l--;
        }
        return ans;
    }
};