class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long low = 1, high = max(need1, need2), ans, m = 0;
        while(low <= high)
        {
            long long mid1 = low+(high-low)/2ll;
            long long mid2 = mid1-1;
            long long c1 = costBoth*mid1+max(0ll, need1-mid1)*cost1+max(0ll, need2-mid1)*cost2;
            long long c2 = costBoth*mid2+max(0ll, need1-mid2)*cost1+max(0ll, need2-mid2)*cost2;
            ans = min(c1, c2);
            if(c2 <= c1) high = mid2;
            else low = mid1+1;
        }
        return ans;
    }
};