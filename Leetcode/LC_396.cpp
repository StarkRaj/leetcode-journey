#include<vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, previousSum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            previousSum += i * nums[i];
        }
        int ans = previousSum;
        for (int i = 1; i < n; i++) {
            previousSum += sum - n * nums[n - i];
            ans = max(ans, previousSum);
        }
        return ans;
    }
};

