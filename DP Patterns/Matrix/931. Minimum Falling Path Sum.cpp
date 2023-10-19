class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int row = matrix.size(); 
        int col = matrix[0].size();
        int minSum = INT_MAX; 
        vector<vector<int>> Dp(row, vector<int>(col, 0));
        
        for(int j = 0; j < col; j++)
            Dp[0][j] = matrix[0][j];
        
        for(int i = 1; i < row; i++ )
        {
            for(int j = 0; j < col; j++) {
                
                int way1 = j > 0 ? matrix[i][j] + Dp[i-1][j-1] : INT_MAX;
                int way2 = matrix[i][j] + Dp[i-1][j];
                int way3 = j < col -1 ? matrix[i][j] + Dp[i-1][j + 1] : INT_MAX;
                Dp[i][j] = min ( way1, min (way2, way3));            
         
            } 
            
        }
        for(int j = 0; j < col; j++)
            minSum = min (Dp[row - 1][j], minSum);
        
        return minSum;         
        
    }
};