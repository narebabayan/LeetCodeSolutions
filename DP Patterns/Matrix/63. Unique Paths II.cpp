class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>> Dp(n, vector<int>(m, 0));
        
        
        for(int i = 0; i < n; i++) {
            if(obstacleGrid[i][0] == 1)
            {
                Dp[i][0] = 0;
                 break;                
            }
            else 
                Dp[i][0] = 1;
        }
        
        for(int j = 0; j < m; j++) {
            if(obstacleGrid[0][j] == 1)
            {
                Dp[0][j] = 0;
                 break;                
            }
            else 
                Dp[0][j] = 1;
        }
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(obstacleGrid[i][j] != 1 )
                    Dp[i][j] = Dp[i-1][j] + Dp[i][j-1];
                else                 
                    Dp[i][j] = 0;
            }            
        }
        
        return Dp[n-1][m-1];
        
    }
};