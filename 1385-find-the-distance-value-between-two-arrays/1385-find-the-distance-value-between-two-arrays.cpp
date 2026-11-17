class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        vector<int> pref(2005);
        for(int i = 0; i < arr2.size(); i++) pref[arr2[i]+1000]++;
        for(int i = 1; i < 2005; i++) pref[i] += pref[i-1];

        int cnt = 0;
        for(int i = 0; i < arr1.size(); i++)
        {
            arr1[i] += 1000;
            int m = pref[min(2000, arr1[i]+d)];
            if(arr1[i]-d-1 >= 0) m -= pref[arr1[i]-d-1];
            if(m == 0) cnt++;
        }
        return cnt;
    }
};