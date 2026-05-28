class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hashT, hashS;
        for(auto& c: t) hashT[c]++;
        int l = 0, r = 0, mn = 1e6, i = 1e6, j = -1;
        int required = hashT.size(), formed = 0;
        while(r < s.size())
        {
            hashS[s[r]]++;
            if(hashT.count(s[r]) && hashT[s[r]] == hashS[s[r]]) formed++;
            while(required == formed)
            {
                if(r-l+1 < mn)
                {
                    mn = r-l+1;
                    i = l; j = r;
                }
                hashS[s[l]]--;
                if(hashT.count(s[l]) && hashS[s[l]] < hashT[s[l]]) formed--;
                l++;
            }
            r++;
        }
        if(i > j) return "";
        return s.substr(i, j-i+1);
    }
};