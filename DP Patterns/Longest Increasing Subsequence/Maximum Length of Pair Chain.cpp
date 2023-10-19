class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), []( vector<int>& a, vector<int>& b) {
                    return a[0] < b[0];
        });
        
        
        int n = pairs.size();
        vector<int> dp(n, 1);
        int ans = 1; 
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(pairs[j][0] > pairs[i][1])
                    dp[j] = max(dp[j], 1 + dp[i]);
            }
            
            ans = max( ans, dp[i]);
            
        }
        return ans;
        
    }
};