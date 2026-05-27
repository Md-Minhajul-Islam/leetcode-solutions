class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i-1 >= 0) matrix[i][j] += matrix[i-1][j];
                if(j-1 >= 0) matrix[i][j] += matrix[i][j-1];
                if(i-1 >= 0 && j-1 >= 0) matrix[i][j] -= matrix[i-1][j-1];
            }
        }

        unordered_map<int, int> hashMap;
        int ans = 0;
        for(int rl = 0; rl < n; rl++)
        {
            for(int rh = rl; rh < n; rh++)
            {
                hashMap[0] = 1;
                for(int c = 0; c < m; c++)
                {
                    int prefSum = matrix[rh][c];
                    if(rl-1 >= 0) prefSum -= matrix[rl-1][c];
                    if(hashMap.count(prefSum-target)) ans += hashMap[prefSum-target];
                    hashMap[prefSum]++;
                }
                hashMap.clear();
            }
        }
        return ans;
    }
};