class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        
        
         int n = obstacles.size();
    vector<int> ans(n);
    vector<int> dp; // dp[i] stores the smallest ending obstacle height for a course of length i.

    for (int i = 0; i < n; ++i) {
        int obstacle = obstacles[i];
        
        // Use binary search to find the position where we can insert the current obstacle.
        auto it = std::upper_bound(dp.begin(), dp.end(), obstacle);
        
        if (it == dp.end()) {
            // If no obstacle can be added to the existing courses, create a new course.
            dp.push_back(obstacle);
            ans[i] = dp.size();
        } else {
            // Otherwise, replace the existing course with the current obstacle.
            *it = obstacle;
            ans[i] = it - dp.begin() + 1;
        }
    }

    return ans;
        
    }
};