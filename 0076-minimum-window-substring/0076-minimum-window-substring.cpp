class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hashT, hashS;
        for(auto& c: t) hashT[c]++;
        int l = 0, r = 0, mn = s.size()+1, i = s.size(), j = -1;
        while(r < s.size())
        {
            hashS[s[r]]++;
            while(countMatching(hashT, hashS))
            {
                if(r-l+1 < mn)
                {
                    mn = r-l+1;
                    i = l; j = r;
                }
                hashS[s[l]]--;
                l++;
            }
            r++;
        }
        string ans = "";
        for(int idx = i; idx <= j; idx++) ans += s[idx];
        return ans;
    }
    bool countMatching(unordered_map<char, int>& hashT,
        unordered_map<char, int>& hashS)
    {
        for(auto& [ch, cnt]: hashT)
        {
            if(hashS.count(ch) && hashS[ch] >= cnt) continue;
            return false;
        }
        return true;
    }
};