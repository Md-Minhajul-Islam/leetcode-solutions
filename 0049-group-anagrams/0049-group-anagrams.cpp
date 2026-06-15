class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashMap;

        for(int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            hashMap[temp].push_back(strs[i]);
        }

        for(auto &u: hashMap)
        {
            ans.push_back(u.second);
        }

        return ans;
    }
};