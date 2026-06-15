class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashMap;

        for(auto &s: strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            hashMap[temp].push_back(s);
        }

        for(auto &u: hashMap)
        {
            ans.push_back(move(u.second));
        }

        return ans;
    }
};