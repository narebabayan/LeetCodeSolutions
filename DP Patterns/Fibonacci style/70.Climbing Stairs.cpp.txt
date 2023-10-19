class Solution {
public:
    
    int Solve(int i, vector<int>& dp) {
     
        if(i < 2 )
            return dp[i];
            
        if(dp[i] != -1)
            return dp[i];
        
        return Solve(i-1, dp) + Solve(i-2, dp) + 1;         
    }
    
    
    int climbStairs(int n) {
        
        vector<int> dp(n+1, -1);
        
        dp[0] = 0;
        dp[1] = 1; 
        
        return Solve( n, dp);
    }
};