#include<vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size();i++) {
            if (mp.find(nums[i]) != mp.end())
                ans = min(ans, abs(mp[nums[i]] - i));
            int reversed_number = 0, remainder = 0;
            while (nums[i] != 0) {
                remainder = nums[i] % 10;
                reversed_number = reversed_number * 10 + remainder;
                nums[i] /= 10;
            }
            mp[reversed_number] = i;
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};