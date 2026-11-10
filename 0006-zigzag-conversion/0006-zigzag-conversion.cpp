class Solution {
public:
    string convert(string s, int numRows) {
        int row = numRows;

        vector<string> mat(row, "");

        int ind = 0, r = 0;
        while(ind < s.size())
        {
            while(r >= 0 && r < row && ind < s.size())
            {
                mat[r] += s[ind];
                r++; ind++;
            }
            r = (r-2 < 0 ? 0 : r-2);

            if(numRows <= 2) continue;
            
            while(r >= 0 && r < row && ind < s.size())
            {
                mat[r] += s[ind];
                r--; ind++;
            }
            r+=2;
        }

        string ans = "";
        for(auto &v: mat)
        {
            for(auto &ch: v) ans += ch;
        }

        return ans;
    }
};