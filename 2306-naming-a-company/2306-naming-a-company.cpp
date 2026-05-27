class Solution {
public:
    long long distinctNames(vector<string>& ideas) {

        unordered_map<string, bool> hashMap;
        for(auto& idea: ideas) hashMap[idea] = true;

        vector<vector<int>> v(30, vector<int>(30));
        for(auto& idea: ideas)
        {
            int r = idea[0]-'a';
            for(int c = 0; c < 26; c++)
            {
                if(r == c) continue;
                idea[0] = 'a'+c;
                if(!hashMap.count(idea)) v[r][c]++;
            }
        }
        long long ans = 0;
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
                ans += v[i][j]*v[j][i];
        return ans;
    }
};