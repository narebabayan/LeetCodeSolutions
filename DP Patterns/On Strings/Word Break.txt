class Solution {
public:
    
    bool dictContais(string s, vector<string>& wordDict)
    {
        for(const auto& str: wordDict){
            if(str == s)
                return true;
        }
        return false;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int size = s.size();
        if(size == 0)
            return false; 
        
        //creates array of the reults of subproblem
        // dp[i] will be true if the substring [0, i] can be segmented
        vector<bool> dp(size+1);
        dp[0] = true;
        
        
        for(int i = 1; i <= size; i++) {
            
            for(int j = 0; j < i; j++) {
                
                if(dp[j] and dictContais(s.substr(j, i-j), wordDict))
                {
                    dp[i] = true; 
                    break;
                }
                
            }
        }
        
        return dp[size];
        
    
    }
                        
};