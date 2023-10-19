class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        vector<vector<int>> Dp(n, vector<int>(n, 0)); 
        
        //polindrome 1 len 
        int length = 1;
        int start = 1; 
        for(int i = 0; i < n; i++)
        {
            Dp[i][i] = 1;
            start = i;
        }
                
        for(int i = 1; i < n; i++)
        {
            if(s[i-1] == s[i])
            {
                Dp[i-1][i] = 1;
                start = i-1; 
                length = 2;
            }
        }
        
        
        for(int i = n-3; i >= 0; i--)
        {
            for(int j = i + 2; j < n; j++)
            {   
                
                
                if(Dp[i+1][j-1]  && s[i] == s[j])
                {
                    Dp[i][j] = 1;
                    
                    if( j - i + 1 > length)
                    {
                        start = i;
                        length = j - i + 1;                        
                    }                    
                }
            }
        }
        
        return s.substr(start, length); 
        
        
    }
};