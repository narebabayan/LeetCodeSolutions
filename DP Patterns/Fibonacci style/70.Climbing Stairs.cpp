/* 70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


Constraints:
1 <= n <= 45
*/

// create a dp array and store the values in it
// return the value of dp[n] as the answer
// Time Complexity O(n)
// Space Complexity O(n)

class Solution {
public:
    
    int Solve(int i, vector<int>& dp) {
     
        if(i < 2 )
            return dp[i];
            
        if(dp[i] != -1)
            return dp[i];
        
        return Solve(i-1, dp) + Solve(i-2, dp) + 1;         
    }
    
    
    int climbStairs(int n) {
        
        vector<int> dp(n+1, -1);
        
        dp[0] = 0;
        dp[1] = 1; 
        
        return Solve( n, dp);
    }
};