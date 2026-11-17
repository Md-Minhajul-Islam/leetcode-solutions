class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = nums[nums.size()/2];
        long long moves = 0;
        for(auto &n: nums) moves += abs(m-n);
        return moves;
    }
};