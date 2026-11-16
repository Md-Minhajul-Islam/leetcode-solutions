class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        auto f = [&](long long k)
        {
            return costBoth*k+max(0ll, need1-k)*cost1+max(0ll, need2-k)*cost2;
        };
        
        long long low = min(need1, need2), high = max(need1, need2);
        return min({f(0), f(low), f(high)});
    }
};