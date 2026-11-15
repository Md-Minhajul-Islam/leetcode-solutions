class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum = 0, mod = 1e9+7;
        int oddPref = 0, evenPref = 1;
        int ans = 0;
        for(auto &a: arr)
        {
            sum += a;
            if(sum%2) oddPref++, ans = (ans%mod+ evenPref%mod)%mod;
            else evenPref++, ans = (ans%mod + oddPref%mod)%mod;
        }
        return ans;
    }
};