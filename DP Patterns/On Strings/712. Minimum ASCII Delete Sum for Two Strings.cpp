class Solution {
public:
    
    int cost(string s)
    {
        int ascii_cost = 0;
        for(auto ch : s)
            ascii_cost += ch; 
        return ascii_cost;        
    }
        
    
    int solve(vector<vector<int>>& memo, string s1, string s2, int i , int j)
    {
        if(i < 0 )
        {            
            return cost(s2);
        }
        
        if(j < 0 )
            return cost(s1);
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        
        if(s1[i] == s2[j])
        {
            memo[i][j] = solve(memo,s1, s2, i-1, j-1);
        }
        else {
            
            int delfirst = s1[i] + solve(memo, s1, s2, i-1, j);
            int delsecond = s2[j] + solve(memo, s1, s2, i, j-1);
            int delboth = s1[i] + s2[j] +  solve(memo, s1, s2, i-1, j-1);
            
            memo[i][j] = min (delfirst, min (delsecond, delboth));            
            
        }
         
        return memo[i][j];        
        
    }
    
    
    
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n +1, vector<int>(m+1, 0));
        // Initialize the DP table for base cases
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0] + int(s1[i - 1]);
        }

        for (int j = 1; j <= m; ++j) {
            dp[0][j] = dp[0][j - 1] + int(s2[j - 1]);
        } 
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    
                    dp[i][j] = min ( dp[i-1][j] + (int) s1[i-1], 
                                      dp[i][j-1] + (int) s2[j-1]);                    
                }                
            }
        }
        
        return dp[n][m];
        
        
    }
};