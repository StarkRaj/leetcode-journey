#include<stdio.h>
#include<vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int vSize = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(vSize, 1);
        int maxSize = 1, parent = -1;
        for (int i = 1; i < vSize; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    maxSize = max(maxSize, dp[i]);
                }
            }
        }
        vector<int> ans;
        for (int i = vSize - 1; i >= 0; i--) {
            if (dp[i] == maxSize) {
                if (parent == -1 || parent % nums[i] == 0) {
                    ans.push_back(nums[i]);
                    parent = nums[i];
                    maxSize--;
                }
            }
        }
        return ans;
    }
};