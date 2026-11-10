class Solution {
public:
    string convert(string s, int numRows) {
        int row = numRows;
        int col = (s.size()+numRows-1)/numRows;
        if(numRows > 2) col += (col-1)*(numRows-2);

        vector<vector<char>> mat(row, vector<char>(col, '#'));

        int ind = 0, r = 0, c = 0;
        while(ind < s.size())
        {
            while(r >= 0 && r < row && c >= 0 && c < col && ind < s.size())
            {
                mat[r][c] = s[ind];
                r++; ind++;
            }
            r = (r-2 < 0 ? 0 : r-2);
            c++;

            if(numRows <= 2) continue;
            
            while(r >= 0 && r < row && c >= 0 && c < col && ind < s.size())
            {
                mat[r][c] = s[ind];
                r--; c++; ind++;
            }
            r+=2; c--;
        }

        string ans = "";
        for(auto &v: mat)
        {
            for(auto &ch: v)
            {
                if(ch != '#') ans += ch;
            }
        }

        return ans;
    }
};