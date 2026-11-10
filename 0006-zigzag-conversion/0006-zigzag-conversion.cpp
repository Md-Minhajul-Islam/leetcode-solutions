class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || s.size() <= numRows) return s;

        vector<string> mat(numRows, "");
        int r = 0, dir = 1;
        for(auto c: s)
        {
            mat[r] += c;
            if(r == 0) dir = 1;
            if(r == numRows-1) dir = -1;
            r += dir;
        }

        string ans = "";
        for(auto &str: mat) ans += str;

        return ans;
    }
};