class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int cnt = 0;
        int l = 0, r = 0;
        vector<string> ans;
        while(r < words.size())
        {
            if(cnt+words[r].size()+r-l > maxWidth)
            {
                int needSpace = maxWidth-cnt;
                int seg, mod;
                if(r-l-1 == 0)
                {
                    seg = needSpace;
                    mod = 0;
                }
                else 
                {
                    seg = needSpace/(r-l-1);
                    mod = needSpace%(r-l-1);
                }
                string s = "";

                for(int i = l; i < r; i++)
                {
                    s += words[i];
                    if(s.size() >= maxWidth) break;
                    for(int j = 0; j < seg; j++) s += " ";
                    if(mod > 0) s += " ", mod--;
                }
                ans.push_back(s);
                l = r;
                cnt = words[r].size();
            }   
            else cnt += words[r].size();
            r++;
        }
        string s = "";
        for(int i = l; i < r; i++)
        {
            s += words[i];
            if(s.size() < maxWidth) s += " ";
        }
        while(s.size() < maxWidth) s += " ";
        ans.push_back(s);
        return ans;
    }
};