class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> Dp(row, vector<int> (col, 0));
        
        Dp[0][0] = grid[0][0];
        for(int i = 1;i < row; i++)
            Dp[i][0] = Dp[i-1][0] + grid[i][0];
        
        for(int j = 1; j < col; j++)
            Dp[0][j] = Dp[0][j-1] + grid[0][j];
        
        for(int i = 1; i < row; i++)
        {
            for(int j = 1; j < col; j++)
            {
                Dp[i][j] = min(Dp[i-1][j], Dp[i][j-1]) + grid[i][j];
            }
        }
        
        return Dp[row-1][col-1];
        
    }
};