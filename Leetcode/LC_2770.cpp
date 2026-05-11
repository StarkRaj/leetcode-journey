#include <vector>
using namespace std;

class Solution {
public:
    int traverse(vector<int>& nums, int target, int i, vector<int>& dp) {
        if (i == nums.size() - 1)
            return 0;
        if (dp[i] != INT_MIN)
            return dp[i];
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] - nums[i] <= target && nums[j] - nums[i] >= -target) {
                dp[i] = max(dp[i], 1 + traverse(nums, target, j, dp));
            }
        }
        return dp[i];
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(1001, INT_MIN);
        int ans = traverse(nums, target, 0, dp);
        return ans < 0 ? -1 : ans;
    }

    //Approach 2 [Bottom Up Approach]

    //int maximumJumps(vector<int>& nums, int target) {
    //    int n = nums.size();
    //    vector<int> dp(n, INT_MIN);
    //    dp[0] = 0;
    //    for (int i = 1; i < n; i++) {
    //        for (int j = 0; j < i; j++) {
    //            if (abs(nums[j] - nums[i]) <= target) {
    //                dp[i] = max(dp[i], dp[j] + 1);
    //            }
    //        }
    //    }

    //    return dp[n - 1] < 0 ? -1 : dp[n - 1];
    //}
};

