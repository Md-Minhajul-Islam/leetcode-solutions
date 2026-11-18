class Solution {
public:
    vector<vector<int>> memo;
    int mod = 1e9+7;
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memo.assign(m, vector<int>(n, -1));
        return paths(0, 0, m, n, grid, -1);
    }

    int paths(int i, int j, int m, int n, vector<vector<int>>& grid, int prev)
    {
        if(i >= m || j >= n) return 0;

        if(i == m-1 && j == n-1) return 1;

        if(grid[i][j] == 0 && memo[i][j] != -1) return memo[i][j];

        if(grid[i][j] == 0)
        {
            memo[i][j] = (0ll+paths(i, j+1, m, n, grid, 0)%mod+paths(i+1, j, m, n, grid, 1)%mod)%mod;
        }
        else
        {
            if(prev == 0) memo[i][j] = paths(i+1, j, m, n, grid, 1);
            else memo[i][j] = paths(i, j+1, m, n, grid, 0);
        }

        return memo[i][j];
    }
};