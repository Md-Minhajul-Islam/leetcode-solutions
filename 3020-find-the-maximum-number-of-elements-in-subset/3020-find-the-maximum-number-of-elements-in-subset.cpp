class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int cnt = 0, cntOne = 0;
        unordered_map<int, int> hashMap;
        for(auto& n: nums)
        {
            if(n == 1) cntOne++;
            else hashMap[n]++;
        }
        if(cntOne > 0)
        {
            cnt = cntOne%2 ? cntOne : cntOne-1;
        }
        for(auto &n: nums)
        {
            if(n == 1) continue;
            int c = 0;
            long long num = n;
            while(1)
            {
                if(num <= INT_MAX && hashMap.find(num) != hashMap.end())
                {
                    if(hashMap[num] >= 2) c+=2;
                    else
                    {
                        c++;
                        break;
                    }
                }
                else
                {
                    c--;
                    break;
                }
                num *= num;
            }
            cnt = max(cnt, c);
        }
        return cnt;
    }
};