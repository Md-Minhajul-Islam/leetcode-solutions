class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashMap;

        for(auto &s: strs)
        {
            vector<int> cnt(26);
            for(auto &c: s) cnt[c-'a']++;

            string key = "";
            for(auto &n: cnt) key += "#"+to_string(n);

            hashMap[key].push_back(s);
        }

        for(auto &[u, v]: hashMap)
        {
            ans.push_back(move(v));
        }

        return ans;
    }
};