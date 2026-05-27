class Solution {
public:
    string shortestPalindrome(string s) {

        string str = s;
        reverse(str.begin(), str.end());
        str = s + "*" + str;

        vector<int> lps(str.size());
        int l = 0, r = 1;
        while(r < str.size())
        {
            if(str[l] == str[r])
            {
                lps[r] = l+1;
                l++; r++;
            }
            else
            {
                if(l != 0) l = lps[l-1];
                else lps[r] = 0, r++;
            }
        }
        str = s.substr(lps.back());
        reverse(str.begin(), str.end());
        return str+s;
    }
};