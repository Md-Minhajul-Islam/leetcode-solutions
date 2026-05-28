class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hashT(60), hashS(60);
        int required = 0, formed = 0;
        for(auto& c: t)
        {
            if(!hashT[c-'A']) required++;
            hashT[c-'A']++;
        }
        int l = 0, r = 0, mn = 1e6, i = 1e6, j = -1;
        while(r < s.size())
        {
            hashS[s[r]-'A']++;
            if(hashT[s[r]-'A'] && hashT[s[r]-'A'] == hashS[s[r]-'A']) formed++;
            while(required == formed)
            {
                if(r-l+1 < mn)
                {
                    mn = r-l+1;
                    i = l; j = r;
                }
                hashS[s[l]-'A']--;
                if(hashT[s[l]-'A'] && hashS[s[l]-'A'] < hashT[s[l]-'A']) formed--;
                l++;
            }
            r++;
        }
        if(i > j) return "";
        return s.substr(i, j-i+1);
    }
};