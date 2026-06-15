class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashMap;

        for(auto &s: strs)
        {
            int cnt[26] = {};
            for(auto &c: s) cnt[c-'a']++;

            string key = "";
            for(int i = 0; i < 26; i++) key += "#"+to_string(cnt[i]);

            hashMap[key].push_back(s);
        }

        for(auto &[u, v]: hashMap)
        {
            ans.push_back(move(v));
        }

        return ans;
    }
};