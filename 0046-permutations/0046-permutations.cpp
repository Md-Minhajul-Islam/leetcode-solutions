class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> per, vis(nums.size());
        backtrack(nums, per, vis, ans);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& per, vector<int>& vis, vector<vector<int>>& ans)
    {
        if(nums.size() == per.size())
        {
            ans.push_back(per);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(vis[i]) continue;
            vis[i] = 1;
            per.push_back(nums[i]);
            backtrack(nums, per, vis, ans);
            per.pop_back();
            vis[i] = 0;
        }
    }
};