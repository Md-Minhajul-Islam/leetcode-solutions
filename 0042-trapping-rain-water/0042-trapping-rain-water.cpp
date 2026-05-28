class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, prev = 0, ans = 0;
        while(l < r)
        {
            int mnHeight = min(height[l], height[r]);
            if(mnHeight > prev)
            {
                ans -= prev;
                ans += (r-l-1)*(mnHeight-prev);
                prev = mnHeight;
            }
            else ans -= mnHeight;

            if(mnHeight == height[l]) l++;
            else r--;
        }
        return ans;
    }
};