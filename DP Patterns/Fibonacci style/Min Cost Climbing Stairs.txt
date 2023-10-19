class Solution {
public:
    
    int SolveDp(vector<int>& cost, vector<int>& Dp, int n)
    {
        if(Dp[n] != -1)
            return Dp[n];
        
        
        Dp[n] = min(SolveDp(cost, Dp, n-1), SolveDp(cost, Dp, n-2));
        return Dp[n];        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> Dp(n+1, -1);
        if(n < 2)
            return cost[n];
        
        Dp[0] = 0;
        Dp[1] = 0;
        
        for(int i = 2; i <=n ; i++)
        {           
            int takeOneStep = Dp[i-1] + cost[i-1];
            int takeTwoStep = Dp[i-2] + cost[i-2];
            Dp[i] = min ( takeOneStep,  takeTwoStep);
        }
        
        return Dp[n];
        
    }
};