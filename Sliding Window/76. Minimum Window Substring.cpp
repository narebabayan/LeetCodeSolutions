class Solution {
public:
    // https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/discuss/708092/C%2B%2B-Sliding-Window-O(N)-or-O(1)-or-Explained
    // Solution 1: Sliding Window
    // Time: O(n)
    // Space: O(1)
    // solution description:
    // 1. use sliding window to find the longest subarray with at most one zero
    // 2. update the max length
    // 3. return the max length
    // 4. note: the length of the subarray is end - start, not end - start + 1  
    int longestSubarray(vector<int>& nums) {
        int numOfZero = 0;
        int end = 0;
        int start = 0;
        int maxLen = INT_MIN;
        while (end < nums.size())
        {
            if (nums[end] == 0)
            {
                numOfZero++;
            }

            if (numOfZero > 1)
            {
                if (nums[start++] == 0)
                {
                    numOfZero--;
                }
            }

            maxLen = max(maxLen, end - start);
            end++;
        }

        return maxLen;

    }
};