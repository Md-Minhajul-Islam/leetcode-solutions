class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.size() > k)
        {
            string t = "";
            int sum = s[0]-'0';
            for(int i = 1; i < s.size(); i++)
            {
                if(i%k == 0)
                {
                    t += to_string(sum);
                    sum = 0;
                }
                sum += s[i]-'0';
            }
            t += to_string(sum);
            s = t;
        }
        return s;
    }
};