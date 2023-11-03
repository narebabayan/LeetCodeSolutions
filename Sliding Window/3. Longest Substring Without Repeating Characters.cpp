class Solution {
public:
    // this is a sliding window problem
    // we keep a window of unique characters
    // we keep expanding the window until we find a duplicate
    // once we find a duplicate, we start shrinking the window
    // we keep track of the max length of the window
    // keeping track of the start and end of the window
    // we use a map to keep track of the characters in the window
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> Map; 
        
        int maxLen = 0;
        int start = 0; int end = 0;
        
        while(end < s.size())
        {
            Map[s[end]]++; 
            
            while(Map[s[end]] > 1 )
            {
                 Map[s[start]]--;
                 start++;
            }
            
            maxLen = max(maxLen, end - start+1);                
            
            end++; 
        }
        return maxLen;
        
    }
};