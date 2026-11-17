class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int low = -1e9, high = 1e9;
        long long minMoves = LLONG_MAX;
        while(low <= high)
        {
            int m1 = low+(high-low)/3;
            int m2 = high-(high-low)/3;
            long long c1 = 0, c2 = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                c1 += abs(0ll+m1-nums[i]);
                c2 += abs(0ll+m2-nums[i]);
            }
            minMoves = min({minMoves, c1, c2});
            if(c1 < c2) high = m2-1;
            else if(c1 > c2) low = m1+1;
            else low = m1+1, high = m2-1;
        }
        return minMoves;
    }
};