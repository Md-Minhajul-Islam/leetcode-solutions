class Solution {
public:
    vector<vector<int>> memo;
    bool isMatch(string s, string p) {
        memo.assign(22, vector<int>(22, -1));
        return fun(0, 0, s, p);
    }

    bool fun(int i, int j, string& s, string& p)
    {
        if(j >= p.size())
        {
            return i >= s.size(); 
        }

        if(i < s.size() && memo[i][j] != -1) return memo[i][j];

        bool matched = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        bool ans = false;
        if(matched) ans = fun(i+1, j+1, s, p);
        if(!ans && j+1 < p.size() && p[j+1] == '*')
        {
            ans = fun(i, j+2, s, p) || (matched && fun(i+1, j, s, p));
        }
        return memo[i][j] = ans;
    }
};