class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordSize = words[0].size();
        int wordCount = words.size();
        unordered_map<string, int> originalCount;
        for(auto &w: words) originalCount[w]++;

        vector<int> ans;
        for(int i = 0; i < wordSize; i++)
        {
            unordered_map<string, int> currentCount;
            int count = 0, firstInd = i;
            for(int j = i; j+wordSize-1 < s.size(); j += wordSize)
            {
                string word = s.substr(j, wordSize);
                currentCount[word]++;
                if(originalCount.find(word) == originalCount.end())
                {
                    currentCount.clear();
                    count = 0;
                    firstInd = j + wordSize;
                    continue;
                }
                while(originalCount[word] < currentCount[word])
                {
                    string w = s.substr(firstInd, wordSize);
                    currentCount[w]--;
                    firstInd += wordSize;
                    count--;
                }
                count++;
                if(wordCount == count) ans.push_back(firstInd);
            }
        }
        return ans;
    }
};