class Solution {
public:
    
    int solve(vector<vector<int>>& dp, string word1, string word2, int idx1, int idx2)
    {
          if (idx1 == 0)
        {
            return idx2;
        }
        if (idx2 == 0)
        {
            return idx1;
        }
        
           
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        if(word1[idx1-1] == word2[idx2-1])
        {
            dp[idx1][idx2] = solve(dp, word1, word2, idx1 -1, idx2 -1);
        }
        else {
            
            int delFromFirst = solve(dp, word1, word2, idx1- 1, idx2);
            int delFromSecond = solve(dp, word1, word2, idx1, idx2 -1);
            int replace = solve(dp, word1, word2, idx1 -1, idx2 -1);
            
            dp[idx1][idx2] = min (delFromFirst , min (delFromSecond , replace)) +1;            
        }
        
        return dp[idx1][idx2];        
    }
    
    
    
    int minDistance(string word1, string word2) {
        
        int size1 = word1.size();
        int size2 = word2.size();
        
        vector<vector<int>> Dp(size1 +1 , vector<int>(size2 + 1, -1));
        
        return solve(Dp, word1, word2, size1, size2);
              
        
    }
};