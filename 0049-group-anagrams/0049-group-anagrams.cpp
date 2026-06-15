class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> hashMap;

        for(int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            hashMap[temp].push_back(i);
        }

        for(auto &u: hashMap)
        {
            vector<string> temp;
            for(auto &v: u.second) temp.push_back(strs[v]);
            if(!temp.empty()) ans.push_back(temp);
        }

        return ans;
    }
};