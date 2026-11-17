class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt = 0, mx = nums[0];
        for(auto &n: nums) mx = max(mx, n);
        for(auto &n: nums) cnt += mx-n;
        return cnt;
    }
};