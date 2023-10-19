class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int n = arr.size(); 
        unordered_map<int, int> Dp;
        int max_len = 1;
        for(int i = 0; i < n; i++)
        {
            if(Dp[arr[i] - difference] > 0)
                Dp[arr[i]] = Dp[arr[i] - difference] + 1;    
            else
                Dp[arr[i]] = 1;    
            max_len = max(max_len, Dp[arr[i]]);            
        }        
        
        return max_len;        
    }
};