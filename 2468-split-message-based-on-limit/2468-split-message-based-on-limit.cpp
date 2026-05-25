class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        vector<long long> cumSum(10002);
        for(int i = 1; i <= 10000; i++)
        {
            cumSum[i] += 0ll+cumSum[i-1]+to_string(i).size();
        }

        for(int part = 1; part <= message.size(); part++)
        {
            long long totLen = 0ll+message.size()+3*part+cumSum[part]+to_string(part).size()*part;

            if((totLen+limit-1ll)/limit == part)
            {
                vector<string> ans;
                string s = "";
                for(int i = 1, ind = 0; i <= part; i++)
                {
                    long long extra = limit-3-to_string(i).size()-to_string(part).size();
                    for(int j = 0; j < extra && ind < message.size(); j++) s += message[ind++];
                    s += "<"+to_string(i)+"/"+to_string(part)+">";
                    ans.push_back(s);
                    s.clear();
                }
                return ans;
            }
        }
        return {};
    }
};