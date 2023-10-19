class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> len(n, 1);
        vector<int> count(n, 1);
        
        for(int next = 0; next < n; next++)
        {
            for(int prev = 0; prev < next; prev++)
            {                
                if(nums[prev] < nums[next])
                {                    
                    if (len[prev] + 1 > len[next]) {                        
                        len[next] = len[prev] +1;
                        count[next] = 0;
                    }
                    if (len[prev] + 1 == len[next]) {
                        count[next] += count[prev];
                    }                                        
                }
            }
        }
        
       int maxLength = *max_element(len.begin(), len.end());
       int result = 0;

        for (int i = 0; i < n; i++) {
            if (len[i] == maxLength) {
                result += count[i];
            }
        }

        return result;
        
    }
};