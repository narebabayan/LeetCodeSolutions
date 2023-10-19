class Solution {
public:
    
    int n;
    int solve(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& Dp)
    {
        if( row >= n)
            return 0; 
        
        int m = triangle[row].size();
        if(col >= m)
            return 0; 
        
        if(Dp[row][col] != -1)
            return Dp[row][col];
        
        
        int op1 = solve(row+1, col, triangle, Dp) + triangle[row][col];
        int op2 = solve(row+1, col + 1, triangle, Dp) + triangle[row][col];
        
        Dp[row][col] = min (op1 , op2);
        
        return Dp[row][col];
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        n = triangle.size();                
        vector<vector<int>> Dp(n , vector<int>(n, -1));
        
        
        return solve(0, 0, triangle, Dp);
        
        
    }
};