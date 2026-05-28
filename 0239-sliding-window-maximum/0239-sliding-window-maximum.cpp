class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> l;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            while(!l.empty() && nums[l.back()] <= nums[i]) l.pop_back();
            l.push_back(i);
            if(i < k-1) continue;
            while(l.front() <= i-k) l.pop_front();
            ans.push_back(nums[l.front()]);
        }
        return ans;
    }
};